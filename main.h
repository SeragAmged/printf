#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>

typedef struct op
{
	char *c;
	int (*f)(va_list);
} op_t;

int _printf(const char *format, ...);
int _putchar(char c);
#endif
