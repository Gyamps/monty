#include "monty.h"

/**
 * insert_node_beg - add node to front of doubly linked list
 * @top: pointer to head of list
 * @val: node data
 * Return: 0 if success, -1 if failed
 */
int insert_node_beg(stack_t **top, int val)
{
	stack_t *new_stack;

	if (!top)
		return (-1);

	new_stack = (stack_t *)malloc(sizeof(stack_t));
	if (new_stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_stack->n = val;

	/**
	* Check if node is first node in list
	* else add before first node in list
	*/
	if (*top == NULL)
	{
		new_stack->prev = NULL;
		new_stack->next = NULL;
		*top = new_stack;
	}
	else
	{
		(*top)->prev = new_stack;
		new_stack->next = *top;
		*top = new_stack;
	}
	return (0);
}

/**
 * delete_node_beg - deletes node at end of doubly linked list
 * @top: pointer to head of doubly linked list
 */
void delete_node_beg(stack_t **top)
{
	stack_t *ptr;

	ptr = *top;

	if ((*top)->next != NULL)
	{
		*top = (*top)->next;
		(*top)->prev = NULL;
	}
	else
		*top = NULL;

	free(ptr);
}

/**
 * pall - print all nodes in stack
 * @top: head of list
 * @line_number: bytecode line number
 */
void pall(stack_t **top, unsigned int line_number)
{
	stack_t *ptr;

	ptr = *top;

	if (top == NULL || *top == NULL)
		return;

	(void)line_number;
	while (ptr != NULL)
	{
		fprintf(stdout, "%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * pint - print top node in stack
 * @top: head of list
 * @line_number: bytecode line number
 */
void pint(stack_t **top, unsigned int line_number)
{
	if (top == NULL || *top == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", (*top)->n);
}

/**
 * nop - do nothing
 * @top: head of list
 * @line_number: bytecode line number
 */
void nop(stack_t **top, unsigned int line_number)
{
	(void)top;
	(void)line_number;
}
