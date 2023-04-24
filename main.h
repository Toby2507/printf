#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * struct fmt - struct for format specifiers details
 * @type: data type of specifier
 * @width: minimum width
 * @endidx: index of the next string char after the fmt has been read
 * @left: left justify
 * @dp: precision
 * @base_prefix: should there be a base prefix
 * @i_plus: should there be an invisible plus
 * @p_plus: should the plus be printed
 * @leading: leading char
 * @printer: function to handle formatting
 *
 * Description: This struct holds the details for each format speci
 */
typedef struct fmt
{
	char type[3];
	int width;
	int endidx;
	int left;
	int dp;
	int base_prefix;
	int i_plus;
	int p_plus;
	char leading;
	char (*printer)(void *, struct fmt *);
} FMT;
typedef char (*FMT_FUNC)(void *, FMT *);

int _printf(const char *format, ...);
FMT *get_specifiers(const char *);
char *int_fmt(void *, FMT *);
char *printable_str(void *, FMT *);
char *pointer_fmt(void *, FMT *);
void base_convert(long, int, int, int, int *, char **);
char *char_fmt(void *data, FMT *fmt);
char *str_fmt(void *data, FMT *fmt);
char *prcnt_fmt(void *data , FMT *fmt);
int p_w_int(int, int, int, int, int, char, char **);
void print_buffer(char *);
char *rev_fmt(void *data, FMT *fmt);

#endif /* MAIN_H */
