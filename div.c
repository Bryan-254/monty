#include "monty.h"

/**
 * func_div - This function divides the top two elements of the stack.
 * @head: This parameter is the stack head.
 * @line_number: This parameter is the counter.
 * Return: Void
 */

void func_div(stack_t **head, unsigned int line_number)
{
	stack_t *hd;
	int len = 0, auxil;

	hd = *head;
	while (hd)
	{
		hd = hd->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(vessel.file);
		free(vessel.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	if (hd->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(vessel.file);
		free(vessel.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	auxil = hd->next->n / hd->n;
	hd->next->n = auxil;
	*head = hd->next;
	free(hd);
}
