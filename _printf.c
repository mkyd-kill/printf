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
				case 'd':
				case 'i':
					char_count += printf("%d", va_arg(args, int));
					break;
				case 'u':
					char_count += printf("%u", va_arg(args, unsigned int));
					break;
				case 'o':
					char_count += printf("%o", va_arg(args, unsigned int));
					break;
				case 'x':
					char_count += printf("%x", va_arg(args, unsigned int));
					break;
				case 'X':
					char_count += printf("%X", va_arg(args, unsigned int));
					break;
				case 'p':
					char_count += printf("%p", va_arg(args, void *));
					break;
				case 'r':
					char_count += handle_r_specifier(get_next_string(args));
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
