#include "monty.h"

/**
 * func_pint - Prints the value at the top of the stack, followed by new line.
 * @head: This parameter is the stack head.
 * @line_number: This parameter is the counter.
 * Return: Void.
 */

void func_pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(vessel.file);
		free(vessel.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
