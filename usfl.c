#include "monty.h"
/**
* execute - exec opcode whene called
* @list: head of stack
* @indicator: line number
* @file: monty file
* @content: line content
* BY HALO & CHROMA
* Return: int
*/
int execute(char *content, stack_t **list, unsigned int indicator, FILE *file)
{
	instruction_t opst[] = {
				{"push", _push}, {"pall", _pall}, {"pint", _pint},
				{"pop", _pop},
				{"swap", _swap},
				{"add", _add},
				{"nop", _nop},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	status.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(list, indicator);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", indicator, op);
		fclose(file);
		free(content);
		free_stack(*list);
		exit(EXIT_FAILURE); }
	return (1);
}

/**
 * addnode - add node to a stack
 * @list: stack to add to
 * @n: data value
 * BY HALO & CHROMA
*/
void addnode(stack_t **list, int n)
{

	stack_t *new_node, *aux;

	aux = *list;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *list;
	new_node->prev = NULL;
	*list = new_node;
}

/**
* free_stack - frees a list
* @list: pnt to list
* BY HALO & CHROMA
*/
void free_stack(stack_t *list)
{
	stack_t *aux;

	aux = list;
	while (list)
	{
		aux = list->next;
		free(list);
		list = aux;
	}
}
