#include "monty.h"

/**
* _pall - prints all the values on the stack
* @list: stack
* @indicator: indic
*
* BY: HALO and CHROMA
* Return: void
*/
void _pall(stack_t **list, unsigned int indicator)
{
	stack_t *n;
	(void)indicator;

	n = *list;
	while (n != NULL)
	{
		printf("%d\n", n->n);
		n = n->next;
	}
}
