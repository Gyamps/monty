#include "monty.h"

/**
 * get_op_func - selects the correct opcode to perform
 *
 * @s: opcode passed
 *
 * Return: pointer to the function that executes the opcode
 */
void (*get_op_func(char *s))(stack_t **top, unsigned int line_number)
{
	int i = 0;

	instruction_t instruction_s[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", _add},
		{"nop", nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}};

	while (instruction_s[i].f != NULL)
	{
		if (strcmp(s, instruction_s[i].opcode) == 0)
			return (instruction_s[i].f);
		i++;
	}
	return (NULL);
}
