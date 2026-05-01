; Tree-sitter highlights for Antlers.
; Designed to be used alongside an HTML highlight set via injections.scm.

(comment) @comment

["{{" "}}"] @tag.delimiter

(closing_tag "/" @tag.delimiter)
(closing_tag name: (variable) @keyword.control)

(boolean) @constant.builtin

(operator) @operator

(string) @string

(number) @number

(modifier
  "|" @operator
  name: (identifier) @function.method)

; Antlers control-flow words at the head of a tag are emitted as variables;
; tag them by name.
((variable) @keyword.control
  (#match? @keyword.control "^(if|elseif|else|unless|foreach|for|each|endif|endunless|endforeach|endfor|endeach)$"))

(variable) @variable
