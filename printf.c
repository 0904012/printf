#include "main.h"

/**
 * _printf - prints according to the format specifier
 * @format: takes the format specifier
 * Return: the formated character
 */
int _printf(const char *format, ...)
{
	va_list list;
	int count;
	format_t get_opt[] = {
		{"c", set_char},
		{"s", set_string},
		{"i", set_decimal},
		{"d", set_decimal},
		{"%", print_percent},
		{"b", print_bin},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_heX},
		{"R", print_rot13},
		{"r", print_rev},
		{NULL, NULL}
	};
	if (!format)
	{
		return (-1);
	}
	va_start(list, format);
	count = parse_format(format, get_opt, list);
	va_end(list);

	return (count);
}
