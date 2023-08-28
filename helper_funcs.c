#include "monty.h"

/**
 * is_number - iterates each character of string to check of isdigit
 * @n: integer
 * Return: 0 if is number, else -1 if not
 */
int is_number(const char *n)
{
	int i = 0;

	/**
	* Account for negative number
	* and increment i if number is
	* indeed negative to work on number
	* not sign
	*/
	if (*n == '-')
		i = 1;

	while (*(n + i) != '\0')
	{
		if (isdigit(*(n + i)) == 0)
			return (-1);
		i++;
	}
	return (0);
}

/**
 * push - adds node to the start of dlinkedlist
 * @top: top of linked list (node at the bottom of stack)
 * @line_number: bytecode line number
 * @n: integer
 */
void push(stack_t **top, unsigned int line_number, const char *n)
{
	if (!top)
		return;

	/*check if n is a number*/
	if (is_number(n) == -1)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_dll(top);
		exit(EXIT_FAILURE);
	}

	if (insert_node_beg(top, atoi(n)) == -1)
	{
		free_dll(top);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop - removes node at front of dlinkedlist
 * @top: top of linked list (node at the bottom of stack)
 * @line_number: bytecode line number
 */
void pop(stack_t **top, unsigned int line_number)
{
	if (top == NULL || *top == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_dll(top);
		exit(EXIT_FAILURE);
	}

	delete_node_beg(top);
}

/**
 * free_dll - frees a doubly linked list with only int data, no strings
 * @top: pointer to head of list
 */
void free_dll(stack_t **top)
{
	if (!top)
		return;

	while (*top && (*top)->next)
	{
		*top = (*top)->next;
		free((*top)->prev);
	}
	free(*top);
}
