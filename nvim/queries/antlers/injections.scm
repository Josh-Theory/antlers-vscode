; Render the surrounding markup using the HTML grammar.
; Combine all `text` runs so the HTML parser sees a coherent document
; rather than fragments split by Antlers tags.

((text) @injection.content
  (#set! injection.language "html")
  (#set! injection.combined))
