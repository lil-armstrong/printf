#include "main.h"

int get_flags(const char *format, int *i)
{
    /* - + 0 # ' ' */
    /* 1 2 4 8 16 */
    int j, index, flags = 0;

    const char FLAGS[] = {'-', '+', '0', '#', ' ', '\0'};
    const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

    for (index = *i + 1; format[index] != '\0'; index++)
    {
        for (j = 0; FLAGS != '\0'; ++j)
        {
            if (format[index] == FLAGS[j])
            {
                flags |= FLAGS_ARR[j];
                break;
            }
        }

        if (FLAGS[j] == 0)
            break;
    }

    *i = index - 1;

    return (flags);
}