#include "monty.h"

/**
 * _push - pushes an element to the stack
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 * @tokens: array of tokens
 */
void _push(stack_t **stack, unsigned int line_number, char *tokens[])
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (!is_number(tokens[line_number + 1]))
	{
		fprintf(stderr, "L%d: usage: _push integer\n", line_number);
		free(new_node);
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(tokens[line_number + 1]);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * _pull - removes the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 * @tokens: array of tokens
 */
void _pull(stack_t **stack, unsigned int line_number, char *tokens[])
{
	stack_t *temp;
	(void)tokens;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't _pull, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}
