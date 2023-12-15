#include "monty.h"

/**
 * func_pstr - Function prints the string starting at the top of the stack,
 * followed by a new.
 * @head: This parameter is a stack head.
 * @line_number: This parameter is a counter but not used.
 * Return: Void.
 */

void func_pstr(stack_t **head, unsigned int line_number)
{
	stack_t *hd;
	(void)line_number;

	hd = *head;

	while (hd)
	{
		if (hd->n > 127 || hd->n <= 0)
		{
			break;
		}
		printf("%c", hd->n);
		hd = hd->next;
	}
	printf("\n");
}
