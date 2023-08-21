#include "main.h"
#include <unistd.h>

/**
 * _printf - prints to stout format text
 * @format: format specifier
 * Return: number of bytes printed
 */

int _printf(const char *format, ...)
{
	unsigned int i;
	int s_count;
	int count = 0;
	va_list list_of_args;

	va_start(list_of_args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
		}
		else if (format[i + 1] == 'c')
		{
			_putchar(va_arg(list_of_args, int));
			i++;
		}
		else if (format[i + 1] == 's')
		{
			s_count = putss(va_arg(list_of_args, char *));
			i++;
			count += (s_count - 1);
		}
		else if (format[i + 1] == '%')
		{
			_putchar('%');

		}
		count += 1;
	}

	va_end(list_of_args);
	return (count);
}
