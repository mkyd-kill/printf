#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
const char *get_next_string(va_list args);
int handle_r_specifier(const char *str);

#endif
