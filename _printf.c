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
	unsigned int n = va_arg(args, unsigned int);
	char binary[33];
	int d = 0;
	int i;
	
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
				case 'b':
					{
						while (n > 0)
						{
							binary[index++] = (num & 1) ? '1' : '0';
							num >>= 1;
						}
						if (d == 0)
						{
							binary[d++] = '0';
						}
						binary[d] = '\0';

						for (i = 0, j = d - 1; i < j; i++, j--)
						{
							p = binary[i];
							binary[i] = binary[j];
							binary[j] = p;
						}
						char_count += printf("%s", binary);
					}
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
