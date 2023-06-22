#ifndef MONTY_H
#define MONTY_H

#define  _POSIX_C_SOURCE 200809L
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

/**
 * struct status_s - store information about the interpreter's state
 * @arg: data value
 * @file: monty file
 * @content: line
 * @lifi: flag
 */
typedef struct status_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  status_t;
extern status_t status;

/*monty func*/
void _nop(stack_t **list, unsigned int indicator);
void _pall(stack_t **list, unsigned int indicator);
void _push(stack_t **list, unsigned int indicator);
void _pint(stack_t **list, unsigned int indicator);
void _pop(stack_t **list, unsigned int indicator);
void _swap(stack_t **list, unsigned int indicator);
void _add(stack_t **list, unsigned int indicator);

/*usfulfuncs*/
int execute(char *content, stack_t **list, unsigned int indicator, FILE *file);
void free_stack(stack_t *list);
void addnode(stack_t **list, int n);

#endif
