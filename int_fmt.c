#include "main.h"

/**
 * int_fmt - converts an integer to a string
 * @data: pointer to the integer
 * @fmt: specifier details
 *
 * Return: the string
 */
char *int_fmt(void *data, FMT *fmt)
{
	long n = *(long *)data;
	int neg = n < 0, i = 1, j, factor;
	char *num = malloc(i + 1);

	if (neg)
	{
		n *= -1;
		num[0] = '-';
		i++;
	}
	base_convert(n, 10, 0, neg, &i, &num);
	num[i] = '\0';
	if (i < fmt->width)
	{
		num = realloc(num, (sizeof(char) * (fmt->width + 1)));
		if (!fmt->left)
		{
			factor = fmt->width - i + 1;
			memmove(&num[neg ? factor + 1 : factor], &num[neg ? 1 : 0], i);
			memset(neg ? &num[1] : num, fmt->leading, factor);
		}
		else
			for (j = i; j <= fmt->width; j++)
				num[j - 1] = ' ';
		num[fmt->width] = '\0';
	}
	if ((fmt->p_plus || fmt->i_plus) && !neg)
	{
		i = (i >= fmt->width) ? i + 1 : fmt->width;
		num = realloc(num, i + 1);
		if (i > fmt->width || fmt->left)
			memmove(&num[1], &num[0], fmt->left ? --i : i);
		num[0] = (fmt->i_plus) ? ' ' : '+';
	}
	return (num);
}
