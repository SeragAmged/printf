#include "main.h"
/**
 * _printf - Produces output according to a format
 * @format: A character string containing zero or more directives
 *
 * Return: The number of characters printed (excluding the null byte used to
 *         end output to strings), or -1 on failure
 */

int _printf(const charformat, ...)
{
int count = 0;
va_list args;
char c, s;

va_start(args, format);

while (format)
{
if (format == '%')
{
format++;

switch (format)
{
case 'c':
c = (char) va_arg(args, int);
putchar(c);
count++;
break;

case 's':
s = va_arg(args, char );
while (s)
{
putchar(s);
s++;
count++;
}
break;

case '%':
putchar('%');
count++;
break;

default:
putchar('%');
putchar(format);
count += 2;
break;
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
