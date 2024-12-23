^[ \t]*(?<key>[a-zA-Z_][\w]*)[^\S\n]*=[^\S\n]*"?(?<value>(?<!")[\w:\/\-\\]+|(?<=")[\S ]*(?="))"?

Version for C++ - value is in group 2 if value in "" or group 3, so make sure to check for both groups
^[ \\t]*([a-zA-Z_][\\w]*)[^\\S\\n]*=[^\\S\\n]*(?:(?:\"([\\S\\t ]*)\")|([\\w\\.:\\/\\-\\\\]+))

Warning:
    Make sure the -gm flags are enabled.

^[ \t]*                     - allow for spaces and tabs at the start of the line
(?<key>[a-zA-Z_][\w]*)      - get the key (has to start with a letter or _)
[^\S\n]*=[^\S\n]*"?         - equal sign
(?<value>                   - get value
    (?<!")[\w:\/\-\\]+              - as contiguous string - additional allowed characers: \ / : - _ 
    |(?<=")[\S ]*(?=")              - or a string with spaces contained within ""
)
"?                         - possibly match the following " for consistency
