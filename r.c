#include "main.h"

/**
 * get_next_string - ...
 * @args:...
 *
 * Return: ...
 */

const char *get_next_string(va_list args)
{
	return (va_arg(args, const char *));
}

/**
 * handle_r_specifier - custom 'r'specifier
 * @str: ...
 *
 * Return: char count
 */

int handle_r_specifier(const char *str)
{
	int char_count = 0;
	int length = 0;
	int i;

	while (str[length] != '\0')
	{
		length++;
	}

	for (i = length - 1; i >= 0; i--)
	{
		_putchar(str[i]);
		char_count++;
	}
	return (char_count);
}

