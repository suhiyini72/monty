#include "monty.h"

/**
 * monty_swap - Swaps the top two elements of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top = (*stack)->next;
	stack_t *second = NULL;

	if (top == NULL || top->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "swap"));
		return;
	}

	second = top->next;

	top->prev = second;
	top->next = second->next;
	if (second->next)
		second->next->prev = top;

	second->prev = *stack;
	second->next = top;

	(*stack)->next = second;
}
