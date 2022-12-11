#include "main.h"
#include <fcntl.h>

/**
 * _printf - Prints fromatted string to STDOUT
 * @format: The formatted string
 * Return: Number of printed characters
 */
int _printf(const char *format, ...)
{
	unsigned int nchars = 0;
	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			nchars += handleConversion(format, args);
		}
		else
			nchars += _putchar(*format);

		++format;
	}

	va_end(args);
	return (nchars);
}

/**
 * handleConversion - handles format conversion logic
 * @format: format string
 * @args: variable arguments
 * Return: number of handled conversion
 */
unsigned int handleConversion(const char *format, va_list args)
{
	unsigned int u_int, *address;
	int s_int;
	char *s;

	switch (*format)
	{
		case 'd':
		case 'i':
			s_int = va_arg(args, int);
			return (_puts(parseInt(s_int, 1, 10)));
		case 'u':
			u_int = va_arg(args, unsigned int);
			return (_puts(parseUnsignedInt(u_int, 1, 10)));
		case 'o':{
			u_int = va_arg(args, unsigned int);
			return (_puts(parseUnsignedInt(u_int, 1, 8)));
		}
		case 'x':
		case 'X':
			u_int = va_arg(args, unsigned int);
			return ((*format == 'X') ? _puts(parseUnsignedInt(u_int, 1, 16))
				: _puts(parseUnsignedInt(u_int, 0, 16)));
		case 'c':
			s_int = va_arg(args, int);
			return (_putchar((char) s_int));
		case 's':
			s = va_arg(args, char *);
			return (_puts(s));
		case 'p':
			address = va_arg(args, unsigned int *);
			return (_puts(addressHexToString((long) address)));
		default:
			_putchar('%');
			return (_putchar(*format));
	}
}
