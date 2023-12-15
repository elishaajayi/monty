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

	strncpy(dup_str, str, len);
	return (dup_str);
}

/**
 * _atoi - just like inbuilt
 * @str: to convert
 * @result: the result as stated
 * Return: the result
 */
bool _atoi(const char *str, int *result)
{
	int res = 0;
	int sign = 1;

	if (*str == '-')
	{
		sign = -1;
		++str;
	}

	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		++str;
	}

	if (*str != '\0' && *str != '\n')
		return (false);

	*result = res * sign;
	return (true);
}
