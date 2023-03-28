#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * print_address - prints address arguments
 * @args: passed arguments
 * Return: Numbet of chars printed
 */

int print_pointer(va_list args)
{
	char *ptr, c;
	int n;
	unsigned long int i;

	ptr = va_arg(args, char *);

	for (i = 0; i < sizeof(ptr); i++)
	{
		c = va_arg(args, int);
		write(1, &c, 1);
	}

	n = i;
	return (n);
}
