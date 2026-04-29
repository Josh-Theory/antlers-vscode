import {
	createConnection,
	TextDocuments,
	Diagnostic,
	DiagnosticSeverity,
	ProposedFeatures,
	InitializeParams,
	DidChangeConfigurationNotification,
	TextDocumentSyncKind,
	InitializeResult,
	DocumentDiagnosticReportKind,
	type DocumentDiagnosticReport
} from 'vscode-languageserver/node';

import { TextDocument } from 'vscode-languageserver-textdocument';

import type { Diagnostic as LinterDiagnostic, LinterConfig, Severity } from 'td-antlers-linter' with { 'resolution-mode': 'import' };

const connection = createConnection(ProposedFeatures.all);
const documents = new TextDocuments(TextDocument);

let hasConfigurationCapability = false;
let hasWorkspaceFolderCapability = false;

connection.onInitialize((params: InitializeParams) => {
	const capabilities = params.capabilities;

	hasConfigurationCapability = !!capabilities.workspace?.configuration;
	hasWorkspaceFolderCapability = !!capabilities.workspace?.workspaceFolders;

	const result: InitializeResult = {
		capabilities: {
			textDocumentSync: TextDocumentSyncKind.Incremental,
			diagnosticProvider: {
				interFileDependencies: false,
				workspaceDiagnostics: false
			}
		}
	};
	if (hasWorkspaceFolderCapability) {
		result.capabilities.workspace = {
			workspaceFolders: { supported: true }
		};
	}
	return result;
});

connection.onInitialized(() => {
	if (hasConfigurationCapability) {
		connection.client.register(DidChangeConfigurationNotification.type, undefined);
	}
	if (hasWorkspaceFolderCapability) {
		connection.workspace.onDidChangeWorkspaceFolders(() => {
			linterConfigCache = undefined;
		});
	}
});

interface AntlersSettings {
	maxNumberOfProblems: number;
}

const defaultSettings: AntlersSettings = { maxNumberOfProblems: 100 };
let globalSettings: AntlersSettings = defaultSettings;
const documentSettings = new Map<string, Thenable<AntlersSettings>>();

connection.onDidChangeConfiguration(change => {
	if (hasConfigurationCapability) {
		documentSettings.clear();
	} else {
		globalSettings = (change.settings?.antlers ?? defaultSettings) as AntlersSettings;
	}
	connection.languages.diagnostics.refresh();
});

function getDocumentSettings(resource: string): Thenable<AntlersSettings> {
	if (!hasConfigurationCapability) {
		return Promise.resolve(globalSettings);
	}
	let result = documentSettings.get(resource);
	if (!result) {
		result = connection.workspace.getConfiguration({
			scopeUri: resource,
			section: 'antlers'
		}) as Thenable<AntlersSettings>;
		documentSettings.set(resource, result);
	}
	return result;
}

documents.onDidClose(e => {
	documentSettings.delete(e.document.uri);
});

type LinterModule = typeof import('td-antlers-linter', { with: { 'resolution-mode': 'import' } });
let linterModulePromise: Promise<LinterModule> | undefined;
let linterConfigCache: LinterConfig | undefined;

async function getLinter(): Promise<LinterModule> {
	if (!linterModulePromise) {
		linterModulePromise = import('td-antlers-linter');
	}
	return linterModulePromise;
}

async function getLinterConfig(): Promise<LinterConfig> {
	if (linterConfigCache) {
		return linterConfigCache;
	}
	const { loadConfig, recommendedConfig } = await getLinter();
	const folders = await connection.workspace.getWorkspaceFolders();
	const cwd = folders?.[0]?.uri ? new URL(folders[0].uri).pathname : process.cwd();
	linterConfigCache = await loadConfig({ cwd, defaults: recommendedConfig });
	return linterConfigCache;
}

connection.languages.diagnostics.on(async params => {
	const document = documents.get(params.textDocument.uri);
	if (!document) {
		return {
			kind: DocumentDiagnosticReportKind.Full,
			items: []
		} satisfies DocumentDiagnosticReport;
	}
	return {
		kind: DocumentDiagnosticReportKind.Full,
		items: await validateTextDocument(document)
	} satisfies DocumentDiagnosticReport;
});

documents.onDidChangeContent(change => {
	validateTextDocument(change.document);
});

connection.onDidChangeWatchedFiles(() => {
	linterConfigCache = undefined;
	connection.languages.diagnostics.refresh();
});

const severityMap: Record<Severity, DiagnosticSeverity | undefined> = {
	error: DiagnosticSeverity.Error,
	warning: DiagnosticSeverity.Warning,
	info: DiagnosticSeverity.Information,
	hint: DiagnosticSeverity.Hint,
	off: undefined
};

async function validateTextDocument(textDocument: TextDocument): Promise<Diagnostic[]> {
	const settings = await getDocumentSettings(textDocument.uri);
	const { lintText } = await getLinter();
	const config = await getLinterConfig();

	const filename = new URL(textDocument.uri).pathname;
	const lintDiagnostics = lintText(textDocument.getText(), { config, filename });

	const diagnostics: Diagnostic[] = [];
	for (const diag of lintDiagnostics) {
		if (diagnostics.length >= settings.maxNumberOfProblems) {
			break;
		}
		const lspDiag = toLspDiagnostic(diag, textDocument);
		if (lspDiag) {
			diagnostics.push(lspDiag);
		}
	}
	return diagnostics;
}

function toLspDiagnostic(diag: LinterDiagnostic, textDocument: TextDocument): Diagnostic | null {
	const severity = severityMap[diag.severity];
	if (severity === undefined) {
		return null;
	}
	const start = diag.range.start;
	const end = diag.range.end ?? start;
	if (!start || !end) {
		return null;
	}
	return {
		severity,
		range: {
			start: { line: Math.max(0, start.line - 1), character: Math.max(0, start.column - 1) },
			end: { line: Math.max(0, end.line - 1), character: Math.max(0, end.column - 1) }
		},
		message: diag.message,
		source: diag.source || 'antlers',
		code: diag.ruleId
	};
}

documents.listen(connection);
connection.listen();
