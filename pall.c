#include "monty.h"
#include <stdio.h>

/**
 * func_pall - prints the stack
 * @head: This parameter is the stack head
 * @line_number: not used
 * Return: void
*/

void func_pall(stack_t **head, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *head;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
