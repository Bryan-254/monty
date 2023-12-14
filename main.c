#include "monty.h"
#include <stdio.h>

vessel_t vessel = {NULL, NULL, NULL, 0};

/**
 * main - This function is the monty code interpreter
 * @ac: This parameter is the number of arguments
 * @av: This parameter is the argument vector (monty file location)
 * Return: 0 on success.
 */

int main(int ac, char *av[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_theline = 1;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	vessel.file = file;

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (read_theline > 0)
	{
		content = NULL;
		read_theline = getline(&content, &size, file);
		vessel.content = content;
		line_number++;
		if (read_theline > 0)
		{
			execute(content, &stack, line_number, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
