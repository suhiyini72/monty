#include "monty.h"

void monty_add(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);

/**
 * monty_add - Adds the top two values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second node
 *              from top and the top is removed.
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	stack_t *top1, *top2;
	int sum;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "add"));
		return;
	}

	top1 = (*stack)->next;
	top2 = top1->next;
	sum = top1->n + top2->n;

	top2->n = sum;
	monty_pop(stack, line_number);
}
/**
 * monty_sub - Subtracts the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second  node
 *              from the top and the tois removed.
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top1, *top2;
	int difference;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "sub"));
		return;
	}

	top1 = (*stack)->next;
	top2 = top1->next;
	difference = top2->n - top1->n;

	top2->n = difference;
	monty_pop(stack, line_number);
}
/**
 * monty_div - Divides the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second node
 *              from the top and the top is removed.
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	stack_t *top1, *top2;
	int divisor, dividend;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "div"));
		return;
	}

	top1 = (*stack)->next;
	top2 = top1->next;
	divisor = top1->n;
	dividend = top2->n;

	if (divisor == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	top2->n = dividend / divisor;
	monty_pop(stack, line_number);
}
/**
 * monty_mod - Computes the modulus of the second value from the
 *             top of a stack_t linked list  by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from top the top value is removed.
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top1, *top2;
	int divisor, dividend, remainder;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mod"));
		return;
	}

	top1 = (*stack)->next;
	top2 = top1->next;
	divisor = top1->n;
	dividend = top2->n;

	if (divisor == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	remainder = dividend % divisor;
	top2->n = remainder;
	monty_pop(stack, line_number);
}
/**
 * monty_mul - Multiplies the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current line number of a Monty bytecodes file.
 *
 * Description: result is stored in the second value node
 *              from top and the top value is removed.
 */

void monty_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top1, *top2;
	int fac1, fac2, product;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mul"));
		return;
	}

	top1 = (*stack)->next;
	top2 = top1->next;
	fac1 = top1->n;
	fac2 = top2->n;
	product = fac1 * fac2;

	top2->n = product;
	monty_pop(stack, line_number);
}
