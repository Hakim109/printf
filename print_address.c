#include "main.h"
/**
 * print_address - prints address
 * @l: va_list arguments
 * @f: pointer to the struct
 * Return: number of chars
 */
int print_address(va_list l, flags_t *f)
{
	char *str;
	unsigned long int p = va_arg(l, unsigned long int);

	register int count = 0;

	(void)f;

	if (!p)
		return (_puts("(nil)"));
	str = convert(p, 16, 1);
	count += _puts("0x");
	count += _puts(str);
	return (count);
}

/**
 * print_bigS - Non printable char
 * @l: va_list arguments
 * @f: pointer to the struct
 * Return: number of char
 */
int print_bigS(va_list l, flags_t *f)
{
	int i, count = 0;
	char *res;
	char *s = va_arg(l, char *);

	(void)f;
	if (!s)
		return (_puts("(null)"));

	for (i = 0; s[i]; i++)
	{
		if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
		{
			_puts("\\x");
			count += 2;
			res = convert(s[i], 16, 0);
			if (!res[1])
				count += _putchar('0');
			count += _puts(res);
		}
		else
			count += _putchar(s[i]);
	}
	return (count);
}

/**
 * print_rev - reverse str
 * @l: argument
 * @f: pointer to the struct
 * Return: length string
 */
int print_rev(va_list l, flags_t *f)
{
	int i = 0, j;
	char *s = va_arg(l, char *);

	(void)f;
	if (!s)
		s = "(null)";

	while (s[i])
		i++;

	for (j = i - 1; j >= 0; j--)
		_putchar(s[j]);

	return (i);
}

/**
 * print_rot13 - using rot13
 * @l: list of arguments from _printf
 * @f: pointer to the struct flags that determines
 * Return: count
 */
int print_rot13(va_list l, flags_t *f)
{
	char *s = va_arg(l, char *);
	int count;

	(void)f;

	if (s == NULL)
		return (0);

	count = 0;

	while (*s)
	{
		char c = *s;

		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		{
			char base = (c >= 'a' && c <= 'z') ? 'a' : 'A';
			*s = (c - base + 13) % 26 + base;
			}
			_putchar(*s);
			s++;
			count++;
			}
			return (count);
}

/**
 * print_percent - prints a percent
 * @l: va_list args
 * @f: pointer to the struct
 * Return: number of char
 */
int print_percent(va_list l, flags_t *f)
{
	(void)l;
	(void)f;
	return (_putchar('%'));
}
