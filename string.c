#include <stdlib.h>
#include "monty.h"
#include <string.h>

/**
 * strtow - Splits a string into an array of words.
 * @str: The string to split.
 * @delims: The string of delimiters.
 *
 * Return: An array of words or NULL on failure.
 */
char **strtow(char *str, char *delims)
{
	int wc = get_word_count(str, delims);
	char **words = malloc((wc + 1) * sizeof(char *));
	int i = 0;

	if (str == NULL || !*str)
		return (NULL);

	if (wc == 0)
		return (NULL);

	if (words == NULL)
		return (NULL);

	while (i < wc)
	{
		int wordLen = get_word_length(str, delims);

		if (is_delim(*str, delims))
			str = get_next_word(str, delims);

		words[i] = malloc((wordLen + 1) * sizeof(char));

		if (words[i] == NULL)
		{
			while (i > 0)
				free(words[--i]);
			free(words);
			return (NULL);
		}

		strncpy(words[i], str, wordLen);

		words[i][wordLen] = '\0';
		str = get_next_word(str, delims);
		i++;
	}
	words[i] = NULL;
	return (words);
}
/**
 * is_delim - Checks if a character is a delimiter.
 * @ch: The character to check.
 * @delims: The string of delimiters.
 *
 * Return: 1 if the character is a delimiter, 0 otherwise.
 */
int is_delim(char ch, char *delims)
{
	while (*delims)
	{
		if (ch == *delims)
			return (1);
		delims++;
	}

	return (0);
}
/**
 * get_word_length - Computes the length of the next word in a string.
 * @str: The string to analyze.
 * @delims: The string of delimiters.
 *
 * Return: The length of the next word.
 */
int get_word_length(char *str, char *delims)
{
	int word_len = 0;
	int i = 0;

	while (str[i] && !is_delim(str[i], delims))
	{
		word_len++;
		i++;
	}

	return (word_len);
}
/**
 * get_word_count - Computes the number of words in a string.
 * @str: The string to analyze.
 * @delims: The string of delimiters.
 *
 * Return: The number of words.
 */
int get_word_count(char *str, char *delims)
{
	int word_count = 0;
	int i = 0;

	if (str == NULL || delims == NULL)
		return (0);

	while (str[i])
	{
		while (str[i] && is_delim(str[i], delims))
			i++;

		if (str[i] && !is_delim(str[i], delims))
		{
			word_count++;

			while (str[i] && !is_delim(str[i], delims))
				i++;
		}
	}

	return (word_count);
}
/**
 * get_next_word - Retrieves a pointer to the next word in a string.
 * @str: The string to analyze.
 * @delims: The string of delimiters.
 *
 * Return: A pointer to the next word.
 */
char *get_next_word(char *str, char *delims)
{
	int i = 0;

	while (str[i] && !is_delim(str[i], delims))
		i++;

	while (str[i] && is_delim(str[i], delims))
		i++;

	return (str + i);
}
