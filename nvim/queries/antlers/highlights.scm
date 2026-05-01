; extends

(comment) @comment

["{{" "}}"] @tag.delimiter

(closing_tag "/" @tag.delimiter)
(closing_tag name: (variable) @keyword.directive)

(boolean) @boolean

(operator) @operator

(string) @string

(number) @number

(modifier
  "|" @operator
  name: (identifier) @function.method)

((variable) @keyword.conditional
  (#any-of? @keyword.conditional "if" "elseif" "else" "unless" "endif" "endunless"))

((variable) @keyword.repeat
  (#any-of? @keyword.repeat "foreach" "for" "each" "endforeach" "endfor" "endeach"))

(variable) @variable
