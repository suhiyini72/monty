#include "monty.h"

/**
 * monty_pop - Removes the top element of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The line number of a Monty bytecodes file.
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top = (*stack)->next;

	if (top == NULL)
	{
		set_op_tok_error(pop_error(line_number));
		return;
	}

	(*stack)->next = top->next;
	if (top->next != NULL)
		top->next->prev = *stack;
	free(top);
}
