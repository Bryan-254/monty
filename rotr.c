#include "monty.h"

/**
 * func_rotr- This function rotates the stack to the bottom.
 * @head: This parameter is the stack head.
 * @line_number: This parameter is the counter.
 * Return: Void.
 */

void func_rotr(stack_t **head, unsigned int line_number)
{
	stack_t *tempo;
	(void)line_number;

	tempo = *head;

	if (!*head || (*head)->next == NULL)
	{
		return;
	}
	while (tempo->next)
	{
		tempo = tempo->next;
	}
	tempo->next = *head;
	tempo->prev->next = NULL;
	tempo->prev = NULL;
	(*head)->prev = tempo;
	(*head) = tempo;
}
