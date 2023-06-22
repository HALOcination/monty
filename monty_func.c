#include "monty.h"
/**
 * _push - add node to the top of the stack
 * @list: stack pnter
 * @indicator: number of the line
 * BY HALO & CHROMA
*/
void _push(stack_t **list, unsigned int indicator)
{
	int n, j = 0, flag = 0;

	if (status.arg)
	{
		if (status.arg[0] == '-')
			j++;
		for (; status.arg[j] != '\0'; j++)
		{
			if (status.arg[j] > 57 || status.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", indicator);
			fclose(status.file);
			free(status.content);
			free_stack(*list);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", indicator);
		fclose(status.file);
		free(status.content);
		free_stack(*list);
		exit(EXIT_FAILURE); }
	n = atoi(status.arg);
	if (status.lifi == 0)
		addnode(list, n);
}

/**
 * _pop - prints the top
 * @list: head of the stack
 * @indicator: line_num
 * BY HALO & CHROMA
*/
void _pop(stack_t **list, unsigned int indicator)
{
	stack_t *h;

	if (*list == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", indicator);
		fclose(status.file);
		free(status.content);
		free_stack(*list);
		exit(EXIT_FAILURE);
	}
	h = *list;
	*list = h->next;
	free(h);
}

#include "monty.h"
/**
 * _swap - The opcode swap swaps the top two elements of the stack.
 * @list: HEAD OF stack
 * @indicator: line number
 * BY HALO & CHROMA
*/
void _swap(stack_t **list, unsigned int indicator)
{
	stack_t *h;
	int len = 0, aux;

	h = *list;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", indicator);
		fclose(status.file);
		free(status.content);
		free_stack(*list);
		exit(EXIT_FAILURE);
	}
	h = *list;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}

#include "monty.h"
/**
 * _add - adds the top two elements of the stack.
 * @list: head of the stack
 * @indicator: line number
 * BY HALO & CHROMA
*/
void _add(stack_t **list, unsigned int indicator)
{
	stack_t *h;
	int len = 0, aux;

	h = *list;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", indicator);
		fclose(status.file);
		free(status.content);
		free_stack(*list);
		exit(EXIT_FAILURE);
	}
	h = *list;
	aux = h->n + h->next->n;
	h->next->n = aux;
	*list = h->next;
	free(h);
}
