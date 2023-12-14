#include "monty.h"

/**
 * is_number - checks if a string is a number
 * @str: the string to check
 * Return: 1 if it is a number, 0 otherwise
 */
int is_number(char *str)
{
	int i;

	if (str == NULL)
		return (0);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			continue;
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (1);
}

/**
 * execute - performs operations based on the opcode
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 * @tokens: array of tokens
 */
void execute(stack_t **stack, unsigned int line_number, char *tokens[])
{
	char *opcode = tokens[0];

	if (strcmp(opcode, "push") == 0)
	{
		_push(stack, line_number, tokens);
	}
	else if (strcmp(opcode, "pull") == 0)
	{
		_pull(stack, line_number, tokens);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * push - pushes an element to the stack
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 */
void push(stack_t **stack, unsigned int line_number)
{
	execute(stack, line_number, NULL);
}

/**
 * pull - prints all the values on the stack
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 */
void pull(stack_t **stack, unsigned int line_number)
{
	execute(stack, line_number, NULL);
}

/**
 * pall - prints all values on the stack
 * @stack: pointer to the stack
 * @line_number: line number of the opcode
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
