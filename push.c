#include <stdlib.h>
#include "monty.h"


void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
int validate_integer(char *str, unsigned int line_number);

/**
 * validate_integer - Validates if a string is a valid integer.
 * @str: The string to validate.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Return: 1 if the string is a valid integer, 0 otherwise.
 */
int validate_integer(char *str, unsigned int line_number)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9') && !(i == 0 && str[i] == '-'))
		{
			set_op_tok_error(no_int_error(line_number));
			return (0);
		}
		i++;
	}

	return (1);
}

/**
 * create_new_node - Creates a new node with the specified value.
 * @value: The value to assign to the new node.
 *
 * Return: A pointer to the newly created node.
 */
stack_t *create_new_node(int value)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		set_op_tok_error(malloc_error());
		return (NULL);
	}

	new->n = value;
	new->prev = NULL;
	new->next = NULL;

	return (new);
}

/**
 * monty_push - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;
	char *token;

	new = create_new_node(0);
	if (new == NULL)
		return;

	if (op_toks[1] == NULL)
	{
		set_op_tok_error(no_int_error(line_number));
		return;
	}

	token = op_toks[1];
	if (!validate_integer(token, line_number))
	{
		free(new);
		return;
	}

	new->n = atoi(token);

	if (check_mode(*stack) == STACK) /* STACK mode insert at front */
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else /* QUEUE mode insert at end */
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}
/**
 * monty_pall - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top node of a stack_t list.
 * @line_number: The line number of a Monty bytecodes file.
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}

	(void)line_number;
}
/**
 * monty_pint - Prints value at the top of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The line number of a Monty bytecodes file.
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top = (*stack)->next;

	if (top == NULL)
	{
		set_op_tok_error(pint_error(line_number));
		return;
	}

	printf("%d\n", top->n);
}
