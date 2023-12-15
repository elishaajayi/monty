#include "monty.h"

/**
 * get_func - to get the correct function
 * @opcode: the opcode to find function for
 * Return: the instruction struct needed
 */
void (*get_func(char *opcode))(stack_t **stack, char *token, unsigned int lnum)
{
	int i = 0;

	instruction_t instructions[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", nop}, {"sub", sub}, {"#", com},
		{"div", div_op}, {"mul", mul_op}, {"mod", mod_op}, {"pchar", pchar_op},
		{"pstr", pstr_op}, {"rotl", rotl_op}, {"rotr", rotr_op}, {NULL, NULL}
	};

	if (opcode == NULL)
		return (NULL);

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
			return (instructions[i].f);
		i++;
	}
	return (NULL);
}
