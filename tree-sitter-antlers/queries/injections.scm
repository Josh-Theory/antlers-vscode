; Inject the HTML parser into the surrounding template text.
; The Antlers parser emits everything outside `{{...}}` as `text` nodes.

((text) @injection.content
  (#set! injection.language "html")
  (#set! injection.combined))
