#include "monty.h"

/**
 * main - start of the function run
 * @argc: the number of arguments provided
 * @argv: list of arguments provided
 * Return: EXIT_SUCCESS and EXIT_FAILURE's
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack;
	char *tokens[MAX_LINE_LEN], line[MAX_LINE_LEN];
	int i = 0, num = 1;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = file_checker(argv[1]);
	while (fgets(line, sizeof(line), file) != NULL)
	{
		void (*command)(stack_t **, char *, unsigned int);

		parser(line, tokens);
		command = get_func(tokens[0]);
		if (command != NULL)
		{
			if (tokens[1] == NULL)
				command(&stack, NULL, num);
			else
				command(&stack, tokens[1], num);
		}
		else
			fprintf(stderr, "Fucked");
		memset(tokens, 0, sizeof(tokens));
	}

	for (i = 0; tokens[i] != NULL; i++)
		free(tokens[i]);

	fclose(file);
	return (0);
}
