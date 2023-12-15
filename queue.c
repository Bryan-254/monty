#include "monty.h"

/**
 * func_queue - This function prints the top.
 * @head: This parameter is the stack head.
 * @line_number: This is the counter.
 * Return: Void.
*/
void func_queue(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	vessel.lifi = 1;
}

/**
 * addqueue - This function add node to the tail stack.
 * @n: This parameter is the new_value.
 * @head: This parameter is the head of the stack.
 * Return: Void.
 */

void addqueue(stack_t **head, int n)
{
	stack_t *new_nd, *auxil;

	auxil = *head;
	new_nd = malloc(sizeof(stack_t));

	if (new_nd == NULL)
	{
		printf("Error\n");
	}
	new_nd->n = n;
	new_nd->next = NULL;

	if (auxil)
	{
		while (auxil->next)
			auxil = auxil->next;
	}
	if (!auxil)
	{
		*head = new_nd;
		new_nd->prev = NULL;
	}
	else
	{
		auxil->next = new_nd;
		new_nd->prev = auxil;
	}
}
