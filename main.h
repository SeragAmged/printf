#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);
int print_dec(va_list args);
int print_rev(va_list args);
int print_bin(va_list args);
int print_unsig(va_list args);
int print_octal(va_list args);
int print_x(va_list args);
int print_X(va_list args);
int print_rot13(va_list args);

/**
 * struct code_format - Struct for format specifier and corresponding function.
 *
 * @sc: The format specifier.
 * @f: The function corresponding to the format specifier.
 */
typedef struct code_format
{
    char *sc;
    int (*f)(va_list);
} code_f;

#endif /* MAIN_H */
