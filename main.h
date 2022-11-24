#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_SHORT 1
#define S_LONG 2

/* STRUCT */
typedef struct fmt
{
    char fmt;
    int (*fn)(va_list, char[], int, int, int, int);
} fmt_t;

/* PROTOTYPES */
int _putchar(char c);
int _printf(const char *format, ...);
int handle_conversion(const char *fmt, int *i, va_list list, char buffer[], int flags, int width, int precision, int size);
void print_buffer(char buffer[], int *buffer_index);

/* CHARS & STRINGS */
int print_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags, int width, int procision, int size);
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size);

/* NUMBERS */
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hex_uppercase(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hex(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size);
int print_non_printable(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_pointer(va_list types, char buffer[], int flags, int width, int precision, int size);

int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

int print_reverse(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_rot13string(va_list types, char buffer[], int flags, int width, int precision, int size);

int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size);
int write_number(int is_positive, int index, char buffer[], int flags, int width, int precision, int size);
int write_num(int index, char buffer[], int flags, int width, int precision, int length, char padd, char extra_c);
int write_pointer(char buffer[], int index, int length, int width, int flags, char padd, char extra_c, int padd_start);

int write_unsigned(int is_negative, int index, char buffer[], int flags, int width, int precision, int size);

/* UTILS */
int is_printable(char);
int append_hex_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsigned(unsigned long int num, int size);

#endif