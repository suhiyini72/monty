#include "monty.h"

/**
 * monty_rotl - Rotates the stack to the top.
 * @stack: Double pointer to the stack.
 * @line_number: Line number being executed.
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;

	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_number;
}
/**
 * monty_rotr - Rotates the stack to the bottom.
 * @stack: Double pointer to the stack.
 * @line_number: Line number being executed.
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
	 stack_t *top = (*stack)->next;
	 stack_t *bottom = top;

	 if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	while (bottom->next != NULL)
		bottom = bottom->next;

	(*stack)->next = bottom;
	bottom->prev->next = NULL;
	bottom->prev = NULL;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;
}
/**
 * monty_stack - Sets the stack mode for Monty.
 * @stack: Double pointer to the stack.
 * @line_number: Line number being executed.
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}
/**
 * monty_queue - Sets the queue mode for Monty.
 * @stack: Double pointer to the stack.
 * @line_number: Line number being executed.
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
