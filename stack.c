#include "monty.h"
#include <string.h>

/**
 * free_stack - Frees a stack_t stack.
 * @stack: A pointer to the top
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*stack = NULL; /* Reset the stack pointer to NULL */
}
#include <stdlib.h>

/**
 * init_stack - Initializes a stack by creating a new node.
 *
 * @stack: Pointer to the top of the stack.
 *
 * Return: EXIT_SUCCESS on success, or malloc_error() on failure.
 */
int init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_error());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}
/**
 * check_mode - Checks if a stack_t linked list is in stack or queue mode.
 * @stack: A pointer to the top (stack) or bottom (queue)
 *         of a stack_t linked list.
 *
 * Return: If the stack_t is in stack mode - STACK (0).
 *         If the stack_t is in queue mode - QUEUE (1).
 *         Otherwise - 2.
 */
int check_mode(stack_t *stack)
{
	int mode = 2;  /* Default value for unrecognized mode */

	if (stack->n == STACK)
		mode = STACK;
	else if (stack->n == QUEUE)
		mode = QUEUE;

	return (mode);
}
