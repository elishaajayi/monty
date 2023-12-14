#ifndef MONTY_H
#define MONTY_H

/* Inclusions */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_TOKENS 64

/* Inbuilt function implementations */
char *_strdup(const char *str);
int is_number(char *str);

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
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function Prototypes */
void parser(const char *line, char *tokens[]);
void push(stack_t **stack, unsigned int line_number);
void pull(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void execute(stack_t **stack, unsigned int line_number, char *tokens[]);

/* Extras */
void _push(stack_t **stack, unsigned int line_number, char *tokens[]);
void _pull(stack_t **stack, unsigned int line_number, char *tokens[]);

#endif
