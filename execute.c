#include "monty.h"
/**
 * execute - This function executes the opcode
 * @stack: This is the head linked list - stack
 * @counter: This is the line_counter
 * @file: This is the pointer to monty file
 * @content: This is the line content
 * Return: No return
 */

int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", func_push}, {"pall", func_pall},
				{"add", func_add}, {"pchar", func_pchar},
				{"nop", func_nop}, {"pstr", func_pstr},
				{"stack", func_stack}, {"rotl", func_rotl},
				{"queue", func_queue}, {"rotr", func_rotr},
				{"div", func_div},
				{"pop", func_pop},
				{"mul", func_mul},
				{"pint", func_pint},
				{"swap", func_swap},
				{"sub", func_sub},
				{"mod", func_mod},
				{NULL, NULL}
				};
	unsigned int x = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	vessel.arg = strtok(NULL, " \n\t");
	while (opst[x].opcode && op)
	{
		if (strcmp(op, opst[x].opcode) == 0)
		{	opst[x].f(stack, counter);
			return (0);
		}
		x++;
	}
	if (op && opst[x].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
