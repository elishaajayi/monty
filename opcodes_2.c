#include "monty.h"

/**
 * mod_op - computes the rest of the division of the second top element
 * @stack: pointer to the stack
 * @token: unused parameter for this opcode
 * @line_number: line number of the opcode
 */
void mod_op(stack_t **stack, char *token, unsigned int line_number)
{
	stack_t *temp;

	(void)token;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n %= temp->n;
	(*stack)->prev = NULL;

	free(temp);
}
