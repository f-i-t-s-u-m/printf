#include "main.h"
#include <stdlib.h>
/**
 *
 *
 *
 *
 *
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int _putstring(char *str)
{
	int i = 0;

	for(i = 0; str[i]; i++)
	{
		_putchar(str[i]);
	}
	return (i);
}

int _printf(const char *format, ...)
{
	va_list list;
	int count = 0;

	int i = 0, (*t)(char) = &_putchar;

	va_start(list, format);
	for(; format[i]; i++)
	{
		if(format[i] != '%')
		{
			t(format[i]);
			count++;
		}
		else
		{
			i++;
		 	switch(format[i])
			{
				case 'c':
					t(va_arg(list,int));
					count++;
					break;
				case 's':
					count = count + _putstring(va_arg(list, char *));
					break;
				case '%':
					t('%');
					count++;
					break;

			}

		}
	}
	va_end(list);	
	return (count);
}
