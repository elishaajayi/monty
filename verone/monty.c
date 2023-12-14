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
	char *tokens[MAX_LINE_LEN], line[MAX_LINE_LEN];
	unsigned int i = 0, j = 0, line_number = 1, found = 0;
	stack_t *stack = NULL;
	instruction_t instructions[] = {
		{"push", push}, {"pull", pull}, {"pall", pall}, {NULL, NULL}
	};

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		parser(line, tokens);
		while (tokens[i] != NULL)
		{
			for (j = 0; instructions[j].opcode != NULL; j++)
			{
				if (strcmp(tokens[i], instructions[j].opcode) == 0)
				{
					execute(&stack, line_number, tokens);
					found = 1;
					break;
				}
			}
			if (!found)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, tokens[i]);
				exit(EXIT_FAILURE);
			}

			i++;
			line_number++;
			memset(tokens, 0, sizeof(tokens));
		}
	}

	printf("File successfully opened\n");
	fclose(file);
	return (0);
}
