; extends

(comment) @comment

["{{" "}}"] @tag.delimiter

(closing_tag "/" @tag.delimiter)
(closing_tag name: (variable) @tag)

(boolean) @constant.builtin

(operator) @operator

(string) @string

(number) @number

(modifier
  "|" @operator
  name: (identifier) @function.method)

((variable) @keyword.conditional
  (#any-of? @keyword.conditional "if" "elseif" "else" "unless" "elseunless" "endif" "endunless"))

((variable) @keyword.repeat
  (#any-of? @keyword.repeat "foreach" "for" "each" "endforeach" "endfor" "endeach"))

((tag (variable) @tag)
  (#match? @tag "^[A-Za-z_][A-Za-z0-9_]*:[A-Za-z_]"))

(variable) @variable
