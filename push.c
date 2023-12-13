#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * func_push -  pushes an element to the stack
 * @stack: This is the stack head
 * @value: integer value that you want to push onto the stack
 * @line_number: line number of current line being processed in input file
 * Return: Void
 */

void func_push(stack_t **stack, int value, unsigned int line_number)
{
	if (!stack)
	{
		fprintf(stderr, "L%u: Stack is NULL\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!value)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "L%u: Error: malloc failed\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}
