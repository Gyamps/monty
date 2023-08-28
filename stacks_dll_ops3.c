#include "monty.h"

/**
 * _mod - mod second node from top node
 * @top: top of list
 * @line_number: line of command
 */
void _mod(stack_t **top, unsigned int line_number)
{
	stack_t *ptr;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	ptr = *top;

	if (ptr->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	/*Add value to stack on top and store in (top-1)*/
	ptr->next->n %= ptr->n;

	ptr->next->prev = NULL; /*Set top of stack to NULL*/

	/*Update the top pointer to next element on stack ie.(top-1)*/
	*top = ptr->next;

	free(ptr); /*Free the old top element*/
}

/**
 * pchar - print top node in stack as ascii letter
 * @top: head of list
 * @line_number: bytecode line number
 */
void pchar(stack_t **top, unsigned int line_number)
{
	stack_t *ptr = *top;

	if (top == NULL || *top == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((ptr->n >= 0 && ptr->n <= 127))
		fprintf(stdout, "%c\n", ptr->n);
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - print top nodes in stack as ascii letter
 * and stop only if end of stack, node is 0, or not in ascii table
 * @top: head of list
 * @line_number: bytecode line number
 */
void pstr(stack_t **top, unsigned int line_number)
{
	stack_t *ptr = *top;

	(void)line_number;
	while ((top != NULL) && (*top != NULL))
	{
		if (ptr->n == 0)
			return;

		if ((ptr->n >= 0 && ptr->n <= 127))
			fprintf(stdout, "%c", ptr->n);
		else
			return;

		ptr = ptr->next;
	}
	fprintf(stdout, "\n");
}

/**
 * rotl - rotate so top of stack becomes last one, second becomes first one
 * @top: node to be rotated
 * @line_number: node number
 */
void rotl(stack_t **top, unsigned int line_number)
{
	stack_t *ptr;

	if (top == NULL || *top == NULL)
		return;

	if ((*top)->next != NULL)
	{
		ptr = *top;

		(void)line_number;
		while (ptr->next != NULL)
			ptr = ptr->next;

		(*top)->prev = ptr;
		ptr->next = *top;

		(*top)->next->prev = NULL;
		*top = (*top)->next;
		ptr->next->next = NULL;
	}
}

/**
 * rotr - rotate so only bottom node of stack becomes first one
 * @top: node to be rotated
 * @line_number: node number
 */
void rotr(stack_t **top, unsigned int line_number)
{
	stack_t *ptr;

	(void)line_number;

	if (top == NULL || *top == NULL)
		return;

	if ((*top)->next != NULL)
	{
		ptr = *top;

		while (ptr->next != NULL)
			ptr = ptr->next;

		ptr->prev->next = NULL;
		(*top)->prev = ptr;
		ptr->next = *top;
		ptr->prev = NULL;
		*top = (*top)->prev;
	}
}
