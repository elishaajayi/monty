#include "monty.h"

/**
 * file_checker - check if the input is correct
 * @filename: the name of the file
 * Return: the file opened
 */
FILE *file_checker(char *filename)
{
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", filename);
		exit(EXIT_FAILURE);
	}

	return (file);
}
