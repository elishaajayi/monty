#ifndef MONTY_H
#define MONTY_H

/* Inclusions */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LEN 1024
#define MAX_TOKENS 64

/* Inbuilt functions */
char *_strdup(const char *str);

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, char *token, unsigned int line_number);
} instruction_t;

/* Function Prototypes */
void parser(const char *line, char *tokens[]);
void push(stack_t **stack, char *token, unsigned int line_number);
void pall(stack_t **stack, char *token, unsigned int line_number);
void pint(stack_t **stack, char *token, unsigned int line_number);
void pop(stack_t **stack, char *token, unsigned int line_number);
void swap(stack_t **stack, char *token, unsigned int line_number);
void add(stack_t **stack, char *token, unsigned int line_number);
void nop(stack_t **stack, char *token, unsigned int line_number);
void sub(stack_t **stack, char *token, unsigned int line_number);
void div_op(stack_t **stack, char *token, unsigned int line_number);
void mul_op(stack_t **stack, char *token, unsigned int line_number);
void mod_op(stack_t **stack, char *token, unsigned int line_number);

/* Utility Functions */
FILE *file_checker(char *filename);
void (*get_func(char *opcode))(stack_t **stack, char *token, unsigned int lnum);
void cleanup(stack_t *stack, char *tokens[]);
bool _atoi(const char *str, int *result);

#endif
