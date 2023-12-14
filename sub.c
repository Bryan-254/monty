#include "monty.h"

/**
 * func_sub- Function performs subtracts of first two elements of the stack
 * @head: This parameter is the stack head
 * @line_number: This parameter is the counter
 * Return: Void
 */

void func_sub(stack_t **head, unsigned int line_number)
{
	stack_t *auxil;
	int sub_result, node_count;

	auxil = *head;

	for (node_count = 0; auxil != NULL; node_count++)
	{
		auxil = auxil->next;
	}
	if (node_count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(vessel.file);
		free(vessel.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	auxil = *head;
	sub_result = auxil->next->n - auxil->n;
	auxil->next->n = sub_result;
	*head = auxil->next;
	free(auxil);
}
