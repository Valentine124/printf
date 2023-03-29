#include "main.h"
#include <unistd.h>
#include <string.h>
#include <stdarg.h>

void handle_specifier(char ch, va_list args);

/**
 * _printf - a custom printf function
 *
 * @format: the format string
 *
 * Return: the lenght of the string
 */
int _printf(const char *format, ...)
{
	int i, len = 0, c = 0;
	char f;
	va_list ptr;

	if (format == NULL)
		return (-1);

	while (format[c++])
		len++;

	va_start(ptr, format);

	for (i = 0; i < len; i++)
	{
		if (format[i - 1] == '%' && format[i - 2] != '%')
			continue;
		if (format[i] == '%')
		{
			f = format[i + 1];

			handle_specifier(f, ptr);
		}
		else
		{
			write(1, &(format[i]), 1);
		}
	}
	va_end(ptr);
	return (len);
}

/**
 * handle_specifier - handle all specifiers
 *
 * @ch: specifier character
 *
 * @args: the variable argument list
 *
 * Description: this functio handles the specifiers charater entered
 *
 * Return: Nothing
 */
void handle_specifier(char ch, va_list args)
{
	char nc, *ns;
	int per = 37;

	switch (ch)
	{
		case 'c':
			nc = va_arg(args, int);

			write(1, &nc, 1);
			break;
		case 's':
			ns = va_arg(args, char *);

			if (ns == NULL)
				return;

			write(1, ns, strlen(ns));
			break;
		case '%':
			write(1, &per, 1);
			break;
	}
}
