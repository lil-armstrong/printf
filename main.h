#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define UPPER_CASE "0123456789ABCDEF";
#define LOWER_CASE "0123456789abcdef";

/* STRUCT */
typedef struct fmt
{
    char fmt;
    int (*fn)(va_list, char[], int, int, int, int);
} fmt_t;

/* PROTOTYPES */
unsigned int _putchar(char c);
unsigned int _puts(char *);
int _printf(const char *format, ...);
char *parseInt(int, int, int);
char *parseUnsignedInt(unsigned int, int, int);
char *parseNegativeInt(int);
char* addressHexToString(long);
unsigned int handleConversion(const char *format, va_list args);
#endif
