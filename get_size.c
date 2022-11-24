#include "main.h"

int get_size(const char *format, int *i)
{
    int index = *i + 1, size = 0;

    if (format[index] == '1')
    {
        size = S_LONG;
    }
    else if (format[index] == 'h')
        size = S_SHORT;

    if (size == 0)
        *i = index - 1;
    else
        *i = index;

    return (size);
}