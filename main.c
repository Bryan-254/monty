#include "monty.h"
#include <stdio.h>

vessel_t vessel = {NULL, NULL, NULL, 0};

/**
 * main - This function is the monty code interpreter
 * @argc: This parameter is the number of arguments
 * @argv: This parameter is the argument vector (monty file location)
 * Return: 0 on success.
 */

int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_theline = 1;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	vessel.file = file;

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
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
