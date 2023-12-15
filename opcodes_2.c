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

/**
 * rotl_op - rotates the stack to the top
 * @stack: pointer to the stack
 * @token: unused parameter for this opcode
 * @line_number: unused parameter for this opcode
 */
void rotl_op(stack_t **stack, char *token, unsigned int line_number)
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

		*stack = temp->next;
		(*stack)->prev = NULL;
		last->next = temp;
		temp->next = NULL;
		temp->prev = last;
	}
}

/**
 * pstr_op - prints the string starting at the top of the stack
 * @stack: pointer to the stack
 * @token: unused parameter for this opcode
 * @line_number: line number of the opcode
 */
void pstr_op(stack_t **stack, char *token, unsigned int line_number)
{
	stack_t *current;
	(void)token;

	(void)line_number;

	current = *stack;

	while (current != NULL && current->n != 0 && (current->n >= 0 &&
		current->n <= 127))
	{
		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}

/**
 * pchar_op - prints the char at the top of the stack
 * @stack: pointer to the stack
 * @token: unused parameter for this opcode
 * @line_number: line number of the opcode
 */
void pchar_op(stack_t **stack, char *token, unsigned int line_number)
{
	(void)token;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

