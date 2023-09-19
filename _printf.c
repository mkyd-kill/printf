#include "main.h"

/**
 * _printf - custom function
 * @t: format
 *
 * Return: printed chars
 */

int _printf(const char *t, ...)
{
	va_list args;
	int char_count = 0;

	va_start(args, t);

	while (*t)
	{
		if (*t == '%')
		{
			t++;

			switch (*t)
			{
				case 'c':
					char_count += _putchar(va_arg(args, int));
					break;
				case 's':
					char_count += printf("%s", va_arg(args, const char *));
					break;
				case '%':
					char_count += _putchar('%');
					break;
				default:
					_putchar('%');
					char_count++;
					break;
			}
		}
		else
		{
			_putchar(*t);
			char_count++;
		}
		t++;
	}

	va_end(args);
	return (char_count);
}
