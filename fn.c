/*fn.c*/
#include "main.h"



/**
 * parseInt - Parses signed int to string
 * @num: number to parse
 * @is_uppercase: inidcates whether to use uppercase for HEX
 * @base: Indicates which numerical base to convert with
 * Return: resulting string
 */
char *parseInt(int num, int is_uppercase, int base)
{
	static char buffer[50];
	char *rep;
	char *ptr;
	int negative = 0;

	if (is_uppercase)
	{
		rep = UPPER_CASE;
	}
	else
		rep = LOWER_CASE;

	if (num < 0)
	{
		negative = 1;
		num = -(num);
	}

	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);

	if (negative)
		*--ptr = '-';

	return (ptr);
}
/**
 * parseUnsignedInt - Parses unsigned int to string
 * @num: number to parse
 * @is_uppercase: inidcates whether to use uppercase for HEX
 * @base: Indicates which numerical base to convert with
 * Return: resulting string
 */
char *parseUnsignedInt(unsigned int num, int is_uppercase, int base)
{
	static char buffer[50];
	char *ptr;
	char *rep;

	if (is_uppercase)
	{
		rep = UPPER_CASE;
	}
	else
		rep = LOWER_CASE;


	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}

/**
 * addressHexToString - Converts an address value to string
 * @value: address value
 * Return: resulting string
 */
char *addressHexToString(long value)
{
	static char buffer[50];
	char *string;
	char *char_set = LOWER_CASE;

	string = &buffer[49];
	*string = '\0';

	do {
		*--string = char_set[value % 16];
		value /= 16;
	} while (value != 0);

	*(--string) = 'x';
	*(--string) = '0';
	return (string);
}

