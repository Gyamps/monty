#include "monty.h"

/**
 * process_line - process the monty file token(s)
 * @token_line: pointer to token_line array
 * @top: pointer to head of list
 * @line_number: line number
 */
void process_line(char *token_line, stack_t **top, unsigned int *line_number)
{
	char *comment_start;
	char *token, *delimeters = "\n\t\a\r ;:";

	comment_start = strchr(token_line, '#');
	if (comment_start != NULL)
		*comment_start = '\0';

	token = strtok(token_line, delimeters);
	while (token != NULL)
	{
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, delimeters);
			push(top, *line_number, token);
			token = strtok(NULL, delimeters);
			(*line_number)++;
			continue;
		}
		else
		{
			if (get_op_func(token) != NULL)
				get_op_func(token)(top, (*line_number));
			else
			{
				free_dll(top);
				fprintf(stderr, "L%d: unknown instruction %s\n", (*line_number), token);
				exit(EXIT_FAILURE);
			}
		}
		(*line_number)++;
		token = strtok(NULL, delimeters);
	}
	token_line[0] = '\0';
}
