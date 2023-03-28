#include <stdarg.h>
#include <unistd.h>
#include <string.h>

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
	char f, nc, *ns;

	va_list ptr;

	while (format[c++])
		len++;

	va_start(ptr, format);

	for (i = 0; i < len; i++)
	{
		if (format[i - 1] == '%')
			continue;
		if (format[i] == '%')
		{
			f = format[i + 1];

			switch (f)
			{
				case 'c':
					nc = va_arg(ptr, int);

					write(1, &nc, 1);
					break;
				case 's':
					ns = va_arg(ptr, char *);

					write(1, ns, strlen(ns));
					break;
			}
		}
		else
		{
			write(1, &(format[i]), 1);
		}
	}
	va_end(ptr);
	return (len);
}
