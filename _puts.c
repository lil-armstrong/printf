/*_puts.c*/
#include "main.h"

/**
 * _puts - Prints a null terminated string to STDOUT
 * @s: NULL terminated string to print to STDOUT
 * Return: The length of printed string
 */
unsigned int _puts(char *s)
{
	unsigned int len = 0;

	while (s[len] != '\0')
	{
		len += _putchar(s[len]);
	}
	return (len);
}
