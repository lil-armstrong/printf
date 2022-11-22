## PROJECT
Printf project

## DESCRIPTION
This team project is part of the first year curriculum of ALX. _printf replicates the C standard library printf() function.

> What you should learn from this project:
> - How to use git in a team setting
> - Applying variadic functions to a big project
> - The complexities of printf
> - Managing a lot of files and finding a good workflow

## TASKS
Write a function that produces output according to a format.

**Prototype:**
``
int _printf(const char *format, ...);
``

- Returns: the number of characters printed (excluding the null byte used to end output to strings)
- Write output to stdout, the standard output stream
- Format is a character string. The format string is composed of zero or more directives. See ``man 3 printf`` for more detail. 
- You need to handle the following conversion specifiers:
``
c
s
%``
- You don’t have to reproduce the buffer handling of the C library printf function
- You don’t have to handle the flag characters
- You don’t have to handle field width
- You don’t have to handle precision
- You don’t have to handle the length modifiers

## RESOURCES
[Format specification syntax]("https://learn.microsoft.com/en-us/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-170")

%[[``flags``]("https://learn.microsoft.com/en-us/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-170#flags")][[``width``]("https://learn.microsoft.com/en-us/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-170#width")][[``.precision``]("https://learn.microsoft.com/en-us/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-170#precision")][[``size``]("https://learn.microsoft.com/en-us/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-170#size")][``type``]("https://learn.microsoft.com/en-us/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-170#type")

[Parameter validation]("https://learn.microsoft.com/en-us/cpp/c-runtime-library/parameter-validation?view=msvc-170")