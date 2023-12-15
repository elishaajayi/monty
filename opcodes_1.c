#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @token: unused parameter for this opcode
 * @line_number: line number of the opcode
 */
void add(stack_t **stack, char *token, unsigned int line_number)
{
	stack_t *temp;

	(void)token;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n += temp->n;
	(*stack)->prev = NULL;

	free(temp);
}

/**
 * nop - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @token: unused parameter for this opcode
 * @line_number: line number of the opcode
 */
void nop(stack_t **stack, char *token, unsigned int line_number)
{
	(void)*stack;
	(void)token;
	(void)line_number;
}

