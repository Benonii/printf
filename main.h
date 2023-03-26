#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>

void _printf(const char *format, ...);
void print_char(va_list args);
void print_string(va_list args);

typedef struct printer {
	char *symbol;
	void(*print)(va_list arg);
} print;

#endif	
