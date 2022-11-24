#include "main.h"

int _printf(const char *format, ...)
{
    va_list list;
    int i = 0, buffer_index = 0,
        flags, width, precision, size,
        printed_chars = 0, printed = 0;
    char buffer[BUFF_SIZE];

    if (format == NULL)
        return (-1);

    va_start(list, format);

    for (; format && format[i] != '\0'; ++i)
    {
        if (format[i] != '%')
        {
            buffer[buffer_index++] = format[i];
            if (buffer_index == BUFF_SIZE)
                print_buffer(buffer, &buffer_index);
            printed_chars++;
        }
        else
        {
            print_buffer(buffer, &buffer_index);
            flags = get_flags(format, &i);
            width = get_width(format, &i, list);
            precision = get_precision(format, &i, list);
            size = get_size(format, &i);
            ++i;
            printed = handle_conversion(format, &i, list, buffer,
                                        flags, width, precision, size);

            if (printed == -1)
                return (-1);

            printed_chars += printed;
        }
    }
    print_buffer(buffer, &buffer_index);
    va_end(list);

    return (printed_chars);
}

void print_buffer(char buffer[], int *buffer_index)
{
    if (*buffer_index > 0)
    {
        write(1, &buffer[0], *buffer_index);

        *buffer_index = 0;
    }
}