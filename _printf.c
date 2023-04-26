#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - prints output according to a format
 * @format: character string containing format specifiers
 *
 * Return: number of characters printed (excluding null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	const char *str;
	va_list arg;
	int printed_chars = 0;

	va_start(arg, format);

	for (str = format; str && *str; str++)
	{
		if (*str != '%')
		{
			_putchar(*str);
			printed_chars++;
		}
		else if (*str == '%' && *(str + 1) == '%')
		{
			_putchar('%');
			printed_chars++;
			str++;
		}
		else if (*str == '%' && *(str + 1) != '\0')
		{
			switch (*(str + 1))
			{
			case 'c':
				_putchar(va_arg(arg, int));
				printed_chars++;
				break;
			case 's':
				printed_chars += print_string(va_arg(arg, char *));
				break;
			default:
				_putchar(*str);
				printed_chars++;
				break;
			}
			str++;
		}
		else
		{
			_putchar(*str);
			printed_chars++;
		}
	}
	va_end(arg);

	return (printed_chars);
}

/**
 * print_string - prints a string
 * @str: the string to print
 *
 * Return: the number of characters printed
 */
int print_string(char *str)
{
	int i;

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i]; i++)
		_putchar(str[i]);

	return (i);
}
