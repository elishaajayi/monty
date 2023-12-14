#include "monty.h"

/**
 * parser - the function to parse and tokenize a line into commands
 * @line: the line to parse into commands
 * @tokens: the array housing the tokens
 * Return: void
 */
void parser(const char *line, char *tokens[])
{
	char *start, *token;
	int tokenCount = 0;

	start = _strdup(line);
	if (start == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(start, " \t\n");

	while (token != NULL)
	{
		tokens[tokenCount] = _strdup(token);
		if (tokens[tokenCount] == NULL)
		{
			fprintf(stderr, "Error: Unable to allocate memory\n");
			exit(EXIT_FAILURE);
		}

		token = strtok(NULL, " \t\n");
		tokenCount++;

		if (tokenCount >= MAX_LINE_LEN - 1)
		{
			fprintf(stderr, "Error: Too many tokens\n");
			exit(EXIT_FAILURE);
		}
	}

	tokens[tokenCount] = NULL;
	free(start);
}
