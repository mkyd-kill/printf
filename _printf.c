#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - custom printf function
 *
 * @format: format string
 *
 * Return: number of chars printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	char buffer[BUFF_SIZE];
        int buff_ind = 0;
        int printed_chars = 0;
        int i;
        int printed = handle_print(format, &i, args, buffer);

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			i++;
			if (format[i] == '\0')
				break;

			if (printed == -1)
			{
				va_end(args);
				return (-1);
			}
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);
	va_end(args);

	return (printed_chars);
}

/**
 * print_buffer - prints the contents of the buffer if it exists
 *
 * @buffer: array
 * @buff_ind: index
 */

 void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, &buffer[0], *buff_ind);
		*buff_ind = 0;
	}
}

