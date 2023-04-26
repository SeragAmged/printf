#include "main.h"

/**
 * _printf - Prints output to stdout according to a format.
 * @format: Format string.
 *
 * Return: The number of characters printed (excluding the null byte used
 * to end output to strings), or -1 if there is an invalid conversion specifier.
 * 
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

va_start(args, format);

while (*format != '\0')
{
if (*format == '%')
{
format++;
int left_justify = 0;
int pad_zero = 0;
int width = 0;
while (1)
{
if (*format == '-')
{
left_justify = 1;
}
else if (*format == '0')
{
pad_zero = 1;
}
else if (*format >= '1' && *format <= '9')
{
width = width * 10 + (*format - '0');
}
else
{
break;
}
format++;
}

switch (*format)
{
case 'c':
{
int c = va_arg(args, int);
if (left_justify)
{
putchar(c);
count++;
for (int i = 0; i < width - 1; i++)
{
putchar(' ');
count++;
}
}
else
{
for (int i = 0; i < width - 1; i++)
{
putchar(' ');
count++;
}
putchar(c);
