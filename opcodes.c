#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to the stack
 * @token: the token to work with
 * @line_number: line number of the opcode
 */
void push(stack_t **stack, char *token, unsigned int line_number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		exit(EXIT_FAILURE);
	if (token == NULL || (atoi(token) == 0 && *token != '0'))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(token);
	new_node->prev = NULL;

	if (*stack == NULL)
		new_node->next = NULL;
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

/**
 * pall - prints all elements in the stack
 * @stack: pointer to the stack
 * @token: the token to work with
 * @line_number: line number of the opcode
 */
void pall(stack_t **stack, char *token, unsigned int line_number)
{
	stack_t *current;

	(void) token;
	(void) line_number;
	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - prints all elements in the stack
 * @stack: pointer to the stack
 * @token: the token to work with
 * @line_number: line number of the opcode
 */
void pint(stack_t **stack, char *token, unsigned int line_number)
{
	stack_t *current;

	(void) token;
	(void) line_number;
	current = *stack;

	if (current == NULL)
	{
		fprintf(stderr, "L<%d>: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", current->n);
}

