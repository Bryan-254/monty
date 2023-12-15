#include "monty.h"

/**
 * func_rotl- This function rotates the stack to the top.
 * @head: This parameter is the stack head.
 * @line_number: This parameter is the counter.
 * Return: Void.
 */

void func_rotl(stack_t **head, unsigned int line_number)
{
	stack_t *last_element = *head, *auxil;
	(void)line_number;

	if (!*head || (*head)->next == NULL)
	{
		return;
	}
	auxil = (*head)->next;
	auxil->prev = NULL;

	while (last_element->next != NULL)
	{
		last_element = last_element->next;
	}
	last_element->next = *head;
	(*head)->next = NULL;
	(*head)->prev = last_element;
	(*head) = auxil;
}
