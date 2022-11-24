#include "main.h"

int handle_conversion(const char *format, int *ind, va_list list, char buffer[], int flags, int width, int precision, int size)
{
    int i, unknown_len = 0, printed_chars = -1;

    fmt_t fmt_types[] = {
        {'c', print_char}, {'s', print_string}, {'%', print_percent}, {'i', print_int}, {'d', print_int}, {'b', print_binary}, {'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal}, {'X', print_hex_uppercase}, {'p', print_pointer}, {'S', print_non_printable}, {'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}};

    for (i = 0; fmt_types[i].fmt != '\0'; ++i)
        if (format[*ind] == fmt_types[i].fmt)
            return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

    if (fmt_types[i].fmt == '\0')
    {
        if (format[*ind] == '\0')
            return (-1);

        unknown_len += write(1, "%%", 1);

        if (format[*ind - 1] == ' ')
            unknown_len += write(1, " ", 1);
        else if (width)
        {
            --(*ind);
            while (format[*ind] != ' ' && format[*ind] != '%')
                --(*ind);
            if (format[*ind] == ' ')
                --(*ind);

            return (1);
        }

        unknown_len += write(1, &format[*ind], 1);

        return (unknown_len);
    }

    return (printed_chars);
}