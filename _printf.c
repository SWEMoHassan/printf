#include "main.h"
#include <stdio.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
va_start(args, format);
while (*format)
{
if (*format == '%' && (*(format + 1) == 'c' || *(format + 1) == 's' || *(format + 1) == '%'))
{
switch (*(format + 1))
{
case 'c':
count += putchar(va_arg(args, int));
break;
case 's':
count += printf("%s", va_arg(args, char *));
break;
case '%':
count += putchar('%');
break;
default:
break;
}
format += 2;
}
else
{
putchar(*format);
count++;
format++;
}
}
va_end(args);
return (count);
}
