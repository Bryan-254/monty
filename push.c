#include "monty.h"

/**
 * func_push - This function add node to the stack
 * @head: This parameter is the stack head
 * @line_number: This is the counter
 * Return: Void
 */

void func_push(stack_t **head, unsigned int line_number)
{
	int n, y = 0, flag = 0;

	if (vessel.arg)
	{
		if (vessel.arg[0] == '-')
			y++;
		for (; vessel.arg[y] != '\0'; y++)
		{
			if (vessel.arg[y] > 57 || vessel.arg[y] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(vessel.file);
			free(vessel.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(vessel.file);
		free(vessel.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(vessel.arg);
	if (vessel.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
