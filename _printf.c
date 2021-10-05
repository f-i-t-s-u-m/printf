#include "main.h"
/**
 *_putchar - print chars to the screen
 *@c: char arg to the print function
 *@p: pointer to get the value of printed chars
 *Return: integer
 */

int _putchar(char c, int *p)
{
	if (c != '\0')
	*p = *p + 1;
	return (write(1, &c, 1));
}
/**
 *_putstring - print chars to the screen
 *@str: string arg to the print function
 *@pc: pointer to get the value of printed chars
 *Return: integer;
 */

int _putstring(char *str, int *pc)
{
	int i = 0;

	for (i = 0; str[i]; i++)
	{
		_putchar(str[i], pc);
	}
	return (i);
}
/**
 *_printf - print function
 *@format: printer format
 *Return: integer;
 */
int _printf(const char *format, ...)
{
	va_list list;
	int count = 0;

	int i, (*t)(char, int *) = &_putchar;

	va_start(list, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			t(format[i], &count);
		}
		else
		{
			i++;
			switch (format[i])
			{
				case 'c':
					t(va_arg(list, int), &count);
					continue;
				case 's':
					_putstring(va_arg(list, char *), &count);
					continue;
				case '%':
					t('%', &count);
					continue;
			}

		}
	}
	va_end(list);
	return (count);
}
