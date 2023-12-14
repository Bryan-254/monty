#include "monty.h"

/**
 * addnode - This function adds node to the head stack
 * @head: This parameter is the head of the stack.
 * @n: This parameter is the new value
 * Return: Void
 */

void addnode(stack_t **head, int n)
{

	stack_t *new_nd, *auxil;

	auxil = *head;
	new_nd = malloc(sizeof(stack_t));

	if (new_nd == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (auxil)
	{
		auxil->prev = new_nd;
	}
	new_nd->n = n;
	new_nd->next = *head;
	new_nd->prev = NULL;
	*head = new_nd;
}
