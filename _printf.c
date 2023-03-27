#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/**
 * print_char - printd a single character
 * @args: The inputted char
 * Return: the number of chars printed(1)
 */

int print_char(va_list args)
{
	int o;

	char ch;

	ch = va_arg(args, int);

	o = write(1, &ch, 1);

	return (o);
}

/**
 * print_string - prints a string
 * @args: The inputted string
 * Return: The numebr of chars printed
 */

int print_string(va_list args)
{
	char *str;
	int n;

	str = va_arg(args, char *);

	n = write(1, str, strlen(str));

	return (n);
}

/**
 * _printf - produces an output according to a format
 * @format: the format specifier
  Return: The number of chars printed
 */

int _printf(const char *format, ...)
{
	int i = 0, j = 0, k = 0;
	char str[100] = {0};
	va_list args;

	print funcs[] = {
		{"c", print_char},
		{"s", print_string}
	};

	va_start(args, format);

	while (format && format[i])
	{
		j = 0;

		if (format[i] == '%')
		{
			i++;
			while (j < 2 && format[i] != *(funcs[j].symbol))
				j++;

			if (j < 2)
			{
				funcs[j].print(args);
			}
		}
		else
		{
			str[j] = format[i];
			k = write(1, str, strlen(str));
			j++;
		}
		i++;
	}

	return (k);
}
