#include "monty.h"

/**
 * func_pop - This function prints the top
 * @head: This parameter is stack head
 * @line_number: This is the counter
 * Return: Void
 */

void func_pop(stack_t **head, unsigned int line_number)
{
	stack_t *hd;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(vessel.file);
		free(vessel.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	*head = hd->next;
	free(hd);
}
