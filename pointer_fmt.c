#include "main.h"

/**
 * pointer_fmt - converts a pointer address to a string
 * @data: pointer to the integer
 * @fmt: specifier details
 *
 * Return: the string
 */
char *pointer_fmt(void *data, FMT *fmt)
{
	long ptr = *(long *)data;
	int i = 1, factor;
	char *num = malloc(i + 1);

	base_convert(ptr, 16, 0, 0, &i, &num);
	num[i] = '\0';
	i += 2;
	num = realloc(num, i + 1);
	memmove(&num[2], &num[0], i + 1);
	num[0] = '0';
	num[1] = 'x';
	if (i < fmt->width)
	{
		num = realloc(num, (sizeof(char) * (fmt->width + 1)));
		if (!fmt->left)
		{
			factor = fmt->width - i + 1;
			memmove(&num[factor], &num[0], i);
			memset(num, fmt->leading, factor);
		}
		else
			for (; i <= fmt->width; i++)
				num[i - 1] = ' ';
		num[fmt->width] = '\0';
	}
	return (num);
}
