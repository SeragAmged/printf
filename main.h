#ifndef __MAIN_H__
#define __MAIN_H__

int _printf(const char *format, ...);
int _putchar(int c);
char *convert(unsigned int num, int base);
void decimal_helper(int d, int *len);

void helper(const char *s, int *len);
#endif