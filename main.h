#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

int _putchar(char c);
int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_ind);
int handle_print(const char *format, int *i, va_list args, char buffer[]);

#endif
