#include "monty.h"

void monty_nop(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);

/**
 * monty_nop - Does nothing for the Monty opcode 'nop'.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * monty_pchar - Prints the character at the top of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number being executed.
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	 int value = (*stack)->next->n;
	 
	 if ((*stack)->next == NULL)
	{
		set_op_tok_error(pchar_error(line_number, "stack empty"));
		return;
	}

	if (value < 0 || value > 127)
	{
		set_op_tok_error(pchar_error(line_number, "value out of range"));
		return;
	}

	putchar(value);
	putchar('\n');
}
/**
 * monty_pstr - Prints the string starting at the top of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number being executed.
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		putchar(tmp->n);
		tmp = tmp->next;
	}

	putchar('\n');

	(void)line_number;
}
