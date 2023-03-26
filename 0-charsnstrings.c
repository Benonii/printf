#include "main.h"
#include <unistd.h>
#include <stdio.h>

/**
 * print_char - printd a single character
 * @args: The inputted char
 * Return: Nothign
 */

void print_char(va_list args)
{

	char ch;

	ch = va_arg(args, int);

	printf("%c", ch);
}

/**
 * print_string - prints a string
 * @args: The inputted string
 * Return: None
 */

void print_string(va_list args)
{
	char *str;

	int len;

	while(args)
		len++;
	
	str = va_arg(args, char *);
	write(1, &str, len);
}

/**
 * _printf - produces an output according to a format
 * @format: the format specifier
 * Return: The number of chars printed
 */

void _printf(const char *format, ...)
{
	int i = 0, j = 0;
	va_list args;

	print funcs[] = {
		{"%c", print_char},
		{"%s", print_string}
	};

	va_start(args, format);

	while (format && (*(format + i)))
	{
		j = 0;

		while (j < 2 && (*(format + i) != *(funcs[j].symbol)))
			j++;

		if (j < 2)
			funcs[j].print(args);

		i++;
	}
}
