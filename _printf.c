#include "main.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
  * convert - converts to string
  * @num: number to convert
  * @base: base to conver to
  * Return: char pointer
  */
char *convert(unsigned int num, int base)
{
	static const char Representation[] = "0123456789ABCDEF";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = Representation[num % base];
		num /= base;
	} while (num != 0);
	return (ptr);
}

/**
  * decimal_helper - helper founct for decimal writ
  * @d: signed int
  * @len: lenght
  */
void decimal_helper(int d, int *len)
{
	char *s, c = '-';

	int size;

	if (d < 0)
	{
		d *= -1;
		write(1, &c, 1);
	}
	s = convert(d, 10);
	size = strlen(s);
	write(1, s, size);
	*len += size;
}
/**
  * helper - helper function to reduce lines
  * @s: string
  * @len: lenght
  */

void helper(const char *s, int *len)
{
	write(1, s, strlen(s));
	*len += strlen(s);
}
/**
  * _printf - my own printf function
  * @fmt: format string
  * @...: multiple args
  * Return: number of char printed, except /0
  */
int _printf(const char *fmt, ...)
{
	const char *temp, c = '%';

	int i, len = 0;

	va_list ap;

	va_start(ap, fmt);
	for (temp = fmt; *temp != '\0'; temp++)
	{
		len++;
		if (*temp == '%')
		{
			temp++;
			switch (*temp)
			{
				case 'c':
					i = va_arg(ap, int);
					write(1, &i, 1);
					len++;
					break;
				case 's':
					helper(va_arg(ap, char *), &len);
					break;
				case 'i':
					helper(convert(va_arg(ap, int), 10), &len);
					break;
				case 'd':
					decimal_helper(va_arg(ap, int), &len);
					break;
				default:
					write(1, &c, 1);
					write(1, temp, 1);
					break;
			}
			temp++;
		}
		write(1, temp, 1);
	}
	va_end(ap);
	return (len);
}
