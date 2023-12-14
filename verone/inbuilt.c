#include "monty.h"
#include <stdlib.h>
#include <string.h>

/**
 * _strdup - my implementation of duplication
 * @str: the string to duplicate
 * Return: the duplicated string
 */
char *_strdup(const char *str)
{
	size_t len = strlen(str) + 1;
	char *dup_str = malloc(len);

	if (dup_str == NULL)
	{
		perror("Error allocating memory");
		exit(EXIT_FAILURE);
	}

	strcpy(dup_str, str);
	return (dup_str);
}
