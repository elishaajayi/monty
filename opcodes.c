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
	char *endptr;
	long result;

	if (token == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = strtol(token, &endptr, 10);
	if (*endptr != '\0' && *endptr != '\n')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		perror("Error allocating memory");
		exit(EXIT_FAILURE);
	}

	new_node->n = (int)result;
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
	current = *stack;

	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", current->n);
}

/**
 * pop - prints all elements in the stack
 * @stack: pointer to the stack
 * @token: the token to work with
 * @line_number: line number of the opcode
 */
void pop(stack_t **stack, char *token, unsigned int line_number)
{
	stack_t *current, *new_head;

	(void)token;
	current = *stack;

	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_head = current->next;

	if (new_head != NULL)
		new_head->prev = NULL;

	free(current);
	*stack = new_head;
}

