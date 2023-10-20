#include "monty.h"

/**
 * set_op_tok_error - Sets last element of op_toks to be an error code.
 * @error_code: Integer to store as a string in op_toks.
 */
void set_op_tok_error(int error_code)
{
	int toks_len = token_arr_len();
	char **new_toks = malloc(sizeof(char *) * (toks_len + 2));
	int u;
	char *exit_str = get_int(error_code);

	if (!new_toks)
	{
		malloc_error();
		return;
	}

	for (u = 0; u < toks_len; u++)
		new_toks[u] = op_toks[u];

	if (!exit_str)
	{
		free(new_toks);
		malloc_error();
		return;
	}

	new_toks[toks_len] = exit_str;
	new_toks[toks_len + 1] = NULL;

	free(op_toks);
	op_toks = new_toks;
}
