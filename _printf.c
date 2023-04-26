#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * find_function - Find the function corresponding to the format specifier.
 * @format: The format specifier.
 *
 * Return: A pointer to the corresponding function, or NULL if not found.
 */
int (*find_function(const char *format))(va_list)
{
    code_f formats[] = {
        {"c", print_char},
        {"s", print_string},
        {"i", print_int},
        {"d", print_dec},
        {"r", print_rev},
        {"b", print_bin},
        {"u", print_unsig},
        {"o", print_octal},
        {"x", print_x},
        {"X", print_X},
        {"R", print_rot13},
        {NULL, NULL}
    };
    int i;

    for (i = 0; formats[i].sc != NULL; i++)
    {
        if (*(formats[i].sc) == *format)
            return (formats[i].f);
    }

    return (NULL);
}

/**
 * _printf - Print a formatted string to the standard output.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int (*f)(va_list);
    int count = 0;
    size_t i;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            _putchar(format[i]);
            count++;
        }
        else
        {
            f = find_function(&format[i + 1]);
            if (f != NULL)
            {
                count += f(args);
                i++;
            }
            else if (format[i + 1] == '%')
            {
                _putchar('%');
                count++;
                i++;
            }
            else if (format[i + 1] != '\0')
            {
                _putchar('%');
                count++;
            }
            else
                return (-1);
        }
    }

    va_end(args);

    return (count);
}
