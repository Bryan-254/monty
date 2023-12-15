#include "monty.h"

/**
 * func_pall - This function prints the stack.
 * @head: This parameter is the stack head.
 * @line_number: This parameter is not used.
 * Return: Void.
 */

void func_pall(stack_t **head, unsigned int line_number)
{
	stack_t *hd;
	(void)line_number;

	hd = *head;

	if (hd == NULL)
	{
		return;
	}
	while (hd)
	{
		printf("%d\n", hd->n);
		hd = hd->next;
	}
}
