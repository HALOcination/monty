#include "monty.h"

/**
* _pint -  prints the value at the top of the stack
* @list: stack
* @indicator: indic
*
* BY: HALO and CHROMA
* Return: void
*/

void _pint(stack_t **list, unsigned int indicator)
{
	if (*list == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", indicator);
		fclose(status.file);
		free(status.content);
		free_stack(*list);
		exit(EXIT_FAILURE);
}

	printf("%d\n", (*list)->n);
}
