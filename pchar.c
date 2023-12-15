#include "monty.h"

/**
 * func_pchar - This function prints the char at the top of the stack,
 * followed by a new line.
 * @head: This parameter is the stack head.
 * @line_number: This parameter is the counter.
 * Return: Void.
 */

void func_pchar(stack_t **head, unsigned int line_number)
{
	stack_t *hd;

	hd = *head;

	if (hd == NULL)
	{
		fprintf(stderr, "L%d: cannot pchar, stack empty\n", line_number);
		fclose(vessel.file);
		free(vessel.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (hd->n > 127 || hd->n < 0)
	{
		fprintf(stderr, "L%d: cannot pchar, value out of range\n", line_number);
		fclose(vessel.file);
		free(vessel.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", hd->n);
}
