#include "main.h"

/**
 * _printf - Prints output to stdout according to a format.
 * @format: Format string.
 *
 * Return: The number of characters printed (excluding the null byte used
 * to end output to strings),or -1 if there is an invalid conversion specifier.
 */


int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);
int count = 0;
while (*format != '\0')
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
{
int c = va_arg(args, int);
putchar(c);
count++;
break;
}
case 's':
{
char *s = va_arg(args, char *);
while (*s != '\0')
{
putchar(*s);
s++;
count++;
}
break;
}
case '%':
{
putchar('%');
count++;
break;
}
default:
{
va_end(args);
return -1;
}
}
}
else
{
putchar(*format);
count++;
}
format++;
}
va_end(args);
return count;
}
