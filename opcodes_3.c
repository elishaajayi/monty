#include "monty.h"

/**
 * rotr_op - rotates the stack to the bottom
 * @stack: pointer to the stack
 * @token: unused parameter for this opcode
 * @line_number: unused parameter for this opcode
 */
void rotr_op(stack_t **stack, char *token, unsigned int line_number)
{
	stack_t *temp, *last;

	(void)token;
	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = *stack;
		last = *stack;

		while (last->next != NULL)
			last = last->next;

		last->prev->next = NULL;
		last->prev = NULL;
		last->next = temp;
		temp->prev = last;
		*stack = last;
	}
}

/**
 * com - rotates the stack to the bottom
 * @stack: pointer to the stack
 * @token: unused parameter for this opcode
 * @line_number: unused parameter for this opcode
 */
void com(stack_t **stack, char *token, unsigned int line_number)
{
	(void)*stack;
	(void)token;
	(void)line_number;
}
