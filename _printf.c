#include "main.h"

/**
 * _printf - Prints output to stdout according to a format.
 * @format: Format string.
 *
 * Return: The number of characters printed (excluding the null byte used
 * to end output to strings), or -1 if there is an invalid conversion specifier.
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
count++;
}
break;
}
case 's':
{
char *s = va_arg(args, char*);
int len = 0;
while (s[len] != '\0')
{
len++;
}
if (left_justify)
{
for (int i = 0; i < len; i++)
{
putchar(s[i]);
count++;
}
for (int i = 0; i < width - len; i++)
{
putchar(' ');
count++;
}
}
else
{
for (int i = 0; i < width - len; i++)
{
putchar(' ');
count++;
}
for (int i = 0; i < len; i++)
{
putchar(s[i]);
count++;
}
}
break;
}
case 'd':
case 'i':
{
int num = va_arg(args, int);
if (num < 0)
{
putchar('-');
count++;
num = -num;
}
int digits[20];
int i = 0;
if (num == 0)
{
digits[i++] = 0;
}
while (num > 0)
{
digits[i++] = num % 10;
num /= 10;
}
if (left_justify)
{
for (int j = i - 1; j >= 0; j--)
{
putchar(digits[j] + '0');
count++;

}
for (int j = 0; j < width - i; j++)
{
if (pad_zero)
{
putchar('0');
count++;
}
else
{
putchar(' ');
count++;
}
}
}
else
{
for (int j = 0; j < width - i; j++)
{
if (pad_zero)
{
putchar('0');
count++;
}
else
{
putchar(' ');
count++;
}
}
for (int j = i - 1; j >= 0; j--)
{
putchar(digits[j] + '0');
count++;
}
}
break;
}
case '%':
{
if (left_justify)
{
putchar('%');
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
putchar('%');
count++;
}
break;
}
default:
{
va_end(args);
return (-1);
}
}
format++;
}
else
{
putchar(*format);
format++;
count++;
}
}

va_end(args);

return (count);
}
