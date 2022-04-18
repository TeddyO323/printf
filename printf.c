#include "main.h"
/**
 * _printf - function tha call a surutine to print different format
 * of data types
 * @format: string to be printed with parameters and variables
 * Return: 0 Succes
 */
int _printf(const char *format, ...)
{
	select_op modulo[] = {{"s", print_s}, {"c", print_c}, {"%", print_per},
	{"i", prin_i}, {"u", prin_ui}, {"d", prin_i}, {"b", prin_bin},
	{"o", print_oct}, {"r", print_rev}, {NULL, NULL}};
	va_list ap; /* points to each unnamed arg in turn */
	unsigned int i = 0, j = 0, len = 0;

	va_start(ap, format); /* make ap point to 1st unnamed arg */
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			len++;
		}
		else
		{
			for (j = 0; modulo[j].f != NULL; j++)
			{
				if (modulo[j].id[0] == format[i + 1])
				{
					len += modulo[j].f(ap);
					i++;
					break;
				}
			}
			if (modulo[j].id == NULL)
				_putchar('%'), len++;
		}
	}

	va_end(ap); /* clean up when done */
	return (len);

}
