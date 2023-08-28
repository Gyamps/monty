#include "monty.h"

/**
 * swap - swap locations of previous stack with the top stack
 * @top: node to be swapped
 * @line_number: node number
 */
void swap(stack_t **top, unsigned int line_number)
{
	stack_t *tmp_ptr;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp_ptr = (*top)->next;
	if (tmp_ptr->next != NULL)
	{
		(*top)->next = tmp_ptr->next;
		(*top)->next->prev = *top;
	}
	else
	{
		tmp_ptr->prev->prev = tmp_ptr;
		tmp_ptr->prev->next = NULL;
	}
	tmp_ptr->prev = NULL;
	tmp_ptr->next = *top;
	(*top) = tmp_ptr;
}

/**
 * _add - adds the top two elements in stack
 * @top: top node
 * @line_number: node number
 */
void _add(stack_t **top, unsigned int line_number)
{
	stack_t *ptr;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	ptr = *top;

	ptr->next->n += ptr->n; /*Add value to stack on top and store in (top-1)*/
	ptr->next->prev = NULL; /*Set top of stack to NULL*/

	/*Update the top pointer to next element on stack ie.(top-1)*/
	*top = ptr->next;

	free(ptr); /*Free the old top element*/
}

/**
 * _sub - subtract second node from top node
 * @top: top of list
 * @line_number: line of command
 */
void _sub(stack_t **top, unsigned int line_number)
{
	stack_t *ptr;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	ptr = *top;

	ptr->next->n -= ptr->n; /*Add value to stack on top and store in (top-1)*/
	ptr->next->prev = NULL; /*Set top of stack to NULL*/

	/*Update the top pointer to next element on stack ie.(top-1)*/
	*top = ptr->next;

	free(ptr); /*Free the old top element*/
}

/**
 * _div - divide second node from top node
 * @top: top of list
 * @line_number: line of command
 */
void _div(stack_t **top, unsigned int line_number)
{
	stack_t *ptr;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	ptr = *top;

	if (ptr->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	ptr->next->n /= ptr->n; /*Add value to stack on top and store in (top-1)*/
	ptr->next->prev = NULL; /*Set top of stack to NULL*/

	/*Update the top pointer to next element on stack ie.(top-1)*/
	*top = ptr->next;

	free(ptr); /*Free the old top element*/
}

/**
 * _mul - multiply second node and top node
 * @top: top of list
 * @line_number: line of command
 */
void _mul(stack_t **top, unsigned int line_number)
{
	stack_t *ptr;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	ptr = *top;

	ptr->next->n *= ptr->n; /*Add value to stack on top and store in (top-1)*/
	ptr->next->prev = NULL; /*Set top of stack to NULL*/

	/*Update the top pointer to next element on stack ie.(top-1)*/
	*top = ptr->next;

	free(ptr); /*Free the old top element*/
}
