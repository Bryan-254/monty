#include "monty.h"

/**
 * free_stack - This funtion frees a doubly linked list.
 * @head: This parameter is the head of the stack.
 */

void free_stack(stack_t *head)
{
	stack_t *auxil;

	auxil = head;
	while (head)
	{
		auxil = head->next;
		free(head);
		head = auxil;
	}
}
