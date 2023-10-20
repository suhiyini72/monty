#include <stdlib.h>

char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
		char *buff, int buff_size);

/**
 * get_int - Converts an integer to a string.
 * @num: The number to convert.
 *
 * Return: Pointer to the newly created string. NULL if malloc fails.
 */
char *get_int(int num)
{
	unsigned int temp = _abs(num);
	int length = get_numbase_len(temp, 10);
	char *ret = malloc((length + 1) * sizeof(char));

	if (ret == NULL)
		return (NULL);

	fill_numbase_buff(temp, 10, ret, length);
	if (num < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * _abs - Computes the absolute value of an integer.
 * @i: The integer to get the absolute value of.
 *
 * Return: The absolute value as an unsigned integer.
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return ((unsigned int)(-i));
	return ((unsigned int)i);
}

/**
 * get_numbase_len - Computes the length of a number in a given base.
 * @num: The number to get the length for.
 * @base: The base of the number representation.
 *
 * Return: The length of the number (excluding the null byte).
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num >= base)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_numbase_buff - Fills a buffer with characters representing
 *                      a number in a given base.
 * @num: The number to convert to a string.
 * @base: The base of the number representation.
 * @buff: The buffer to fill with the converted string.
 * @buff_size: The size of the buffer in bytes.
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
		char *buff, int buff_size)
{
	buff[buff_size] = '\0';
	while (buff_size > 0)
	{
		if (num % base > 9)
			buff[--buff_size] = (num % base) + 87;
		else
			buff[--buff_size] = (num % base) + '0';
		num /= base;
	}
}
