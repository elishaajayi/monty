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

/**
 * sub - subtracts the top element of the stack from the second top element
 * @stack: pointer to the stack
 * @token: unused parameter for this opcode
 * @line_number: line number of the opcode
 */
void sub(stack_t **stack, char *token, unsigned int line_number)
{
	stack_t *temp;

	(void)token;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n -= temp->n;
	(*stack)->prev = NULL;

	free(temp);
}

/**
 * div_op - divides the second top element of the stack by the top element
 * @stack: pointer to the stack
 * @token: unused parameter for this opcode
 * @line_number: line number of the opcode
 */
void div_op(stack_t **stack, char *token, unsigned int line_number)
{
	stack_t *temp;

	(void)token;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n /= temp->n;
	(*stack)->prev = NULL;

	free(temp);
}

/**
 * mul_op - multiplies the second top element of the stack with the top element
 * @stack: pointer to the stack
 * @token: unused parameter for this opcode
 * @line_number: line number of the opcode
 */
void mul_op(stack_t **stack, char *token, unsigned int line_number)
{
	stack_t *temp;

	(void)token;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n *= temp->n;
	(*stack)->prev = NULL;

	free(temp);
}
