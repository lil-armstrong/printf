#include "main.h"

/**
 * _putchar - Prints a single character to STDOUT
 * @c: The character to print to STDOUT
 * Return: The length of printed character
 */
unsigned int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
