# CodeExtractor

A tool that can read all files in the folder non-recursively and copy all code in the separate file.

## Example

If there is a file "main.h" that contains "abc" and a file "main.cpp" that contains "xyz", the following will be produced:

```
main.h

abc

main.cpp
  
xyz

```

## Supported extensions (languages)

- .h and .cpp (C++)
- .cs (C#)
