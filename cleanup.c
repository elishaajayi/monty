#include "monty.h"

/**
 * cleanup - as name suggests
 * @stack: the stack
 * @tokens: the tokens
 * Return: void as in none
 */
void cleanup(stack_t *stack, char *tokens[])
{
	int i;
	stack_t *temp;

	for (i = 0; tokens[i] != NULL; i++)
		free(tokens[i]);

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
