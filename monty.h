#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Top of stack global variable */
extern stack_t *top;

/* ops related prototypes */
void (*get_op_func(char *s))(stack_t **top, unsigned int line_number);
void push(stack_t **top, unsigned int line_number, const char *n);
void pop(stack_t **top, unsigned int line_number);
void pint(stack_t **top, unsigned int line_number);
void pall(stack_t **top, unsigned int line_number);
void swap(stack_t **top, unsigned int line_number);
void nop(stack_t **top, unsigned int line_number);
void pchar(stack_t **top, unsigned int line_number);
void pstr(stack_t **top, unsigned int line_number);
void rotl(stack_t **top, unsigned int line_number);
void rotr(stack_t **top, unsigned int line_number);

/* calculator prototypes */
void _add(stack_t **top, unsigned int line_number);
void _sub(stack_t **top, unsigned int line_number);
void _mul(stack_t **top, unsigned int line_number);
void _div(stack_t **top, unsigned int line_number);
void _mod(stack_t **top, unsigned int line_number);

/* doubly linked list related prototypes */
int insert_node_beg(stack_t **top, int n);
void delete_node_beg(stack_t **top);
void free_dll(stack_t **top);

/* process tokens */
void process_line(char *token_line, stack_t **top, unsigned int *line_number);

#endif
