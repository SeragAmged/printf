#include "main.h"

/**
 * _printfunc - get the right function corresponding to format specified
 * @fi: input format
 * Return:pointer to function that corresponds with specified format
 *
 */
int (*_printfunc(char fi))(va_list)
{
	int i = 0;
	print_f f[] = {
		{'c', printchar},
		{'s', printstr},
		{'d', printint},
		{'i', printint},
		{'\0', NULL}
	};
	while (f[i].type)
	{
		if (fi == f[i].type)
		{
			return (f[i].funct);
		}
		i++;

	}
	return (NULL);
}

/**
 * _printf - function that produces output according to format passed
 * @format: character string containing 0 or more directive
 * Return: number of chars printed exluding null byte
 */
int _printf(const char *format, ...)
{
	int i, counter;

	int (*fn)(va_list);

	va_list a_list;

	if (format == NULL)
		return (-1);

	va_start(a_list, format);
	i = counter = 0;

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			fn = _printfunc(format[i + 1]);
			if (fn == NULL)
				counter += printNaN(format[i], format[i + 1]);
			else
				counter += fn(a_list);
			i++;
		}
		else
		{
			_putchar(format[i]);
			counter++;
		}
		i++;
	}
	va_end(a_list);
	return (counter);
}
