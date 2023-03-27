#include "main.h"
#include <unistd.h>

/**
 * print_percent - prints a percent sign when it is
 *		   specified after another %
 * @args: Empty variable
 * Return: The number of bytes(1)
 */

int print_percent(va_list args)
{
	char percent_sign;
	int n;

	percent_sign = '%';
	(void) args;

	n = write(1, &percent_sign, 1);
	return (n);
}
