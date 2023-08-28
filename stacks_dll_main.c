#include "monty.h"

/**
 * main - entry into interpreter
 * @argc: argc counter
 * @argv: arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd;
	unsigned int line_number = 1;
	char buffer[1], token_line[1024];
	ssize_t bytes_read;
	stack_t *top = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	token_line[0] = '\0';

	while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
	{
		if (buffer[0] == '\n')
			process_line(token_line, &top, &line_number);
		else
			strncat(token_line, buffer, 1);
	}

	if (strlen(token_line) > 0)
		process_line(token_line, &top, &line_number);

	free_dll(&top);
	close(fd);
	return (0);
}
