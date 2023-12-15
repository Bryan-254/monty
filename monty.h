#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct vessel_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct vessel_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  vessel_t;
extern vessel_t vessel;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void func_push(stack_t **head, unsigned int number);
void func_pall(stack_t **head, unsigned int number);
void func_pint(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void func_pop(stack_t **head, unsigned int line_number);
void func_swap(stack_t **head, unsigned int line_number);
void func_add(stack_t **head, unsigned int line_number);
void func_nop(stack_t **head, unsigned int line_number);
void func_sub(stack_t **head, unsigned int line_number);
void func_div(stack_t **head, unsigned int line_number);
void func_mul(stack_t **head, unsigned int line_number);
void func_mod(stack_t **head, unsigned int line_number);
void func_pchar(stack_t **head, unsigned int line_number);
void func_pstr(stack_t **head, unsigned int line_number);
void func_rotl(stack_t **head, unsigned int line_number);
void func_rotr(stack_t **head, unsigned int line_number);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void func_queue(stack_t **head, unsigned int line_number);
void func_stack(stack_t **head, unsigned int line_number);

#endif
