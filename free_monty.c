#include "monty.h"
#include <string.h>
#include <stdio.h>

/**
 * free_tokens - Frees the memory allocated for the tokens array.
 */
void free_tokens(void)
{
	char **tmp = op_toks;

	if (op_toks == NULL)
		return;

	while (*op_toks)
	{
		free(*op_toks);
		op_toks++;
	}

	free(tmp);
}
/**
 * token_arr_len - Calculates the length of the tokens array.
 *
 * Return: The number of tokens in the array.
 */
unsigned int token_arr_len(void)
{
	unsigned int toks_len = 0;
	char **tmp = op_toks;

	if (op_toks == NULL)
		return (0);

	while (*tmp)
	{
		toks_len++;
		tmp++;
	}

	return (toks_len);
}
/**
 * is_empty_line - Checks if a line consists of only delimiter characters.
 *
 * @line: The input line to check.
 * @delims: The delimiter characters to compare against.
 *
 * Return: 1 if the line is empty (consists of only delimiters), 0 otherwise.
 */
int is_empty_line(char *line, char *delims)
{
	int k, l;

	for (k = 0; line[k] != '\0'; k++)
	{
		for (l = 0; delims[l] != '\0'; l++)
		{
			if (line[k] == delims[l])
				return (0);
		}
	}

	return (1);
}
/**
 * get_op_func - Retrieves the function pointer associated with the opcode.
 *
 * @opcode: The opcode to look for.
 *
 * Return: The function pointer corresponding to the opcode
 * or NULL if not found.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"nop", monty_nop},
		{"sub", monty_sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{"stack", monty_stack},
		{"queue", monty_queue},
		{NULL, NULL}
	};
	int z;

	for (z = 0; op_funcs[z].opcode; z++)
	{
		if (strcmp(opcode, op_funcs[z].opcode) == 0)
			return (op_funcs[z].f);
	}

	return (NULL);
}
/**
 * run_monty - Primary function to execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int run_monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t **, unsigned int);
	int exit_status = EXIT_SUCCESS;

	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, script_fd) != -1)
	{
		line_number++;

		op_toks = strtow(line, DELIMS);
		if (op_toks == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			free_stack(&stack);
			exit_status = malloc_error();
			break;
		}

		if (op_toks[0][0] == '#') /* comment line */
		{
			free_tokens();
			continue;
		}

		op_func = get_op_func(op_toks[0]);
		if (op_func == NULL)
		{
			free_stack(&stack);
			exit_status = unknown_op_error(op_toks[0], line_number);
			free_tokens();
			break;
		}

		prev_tok_len = token_arr_len();
		op_func(&stack, line_number);

		if (token_arr_len() != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				exit_status = atoi(op_toks[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_tokens();
			break;
		}

		free_tokens();
	}

	free_stack(&stack);

	if (line != NULL && *line == '\0')
	{
		free(line);
		return (malloc_error());
	}

	free(line);
	return (exit_status);
}
