#include "monty.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/**
  *add - adds the top two elements of the stack
  *@stack: doubly linked list
  *@line_number: line with the push opcode
  *
  *Return: void
  */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int el_count = 1, sum;

	if (tmp)
	{
		/* Move to the start of the list */
		while (tmp->prev != NULL)
			tmp = tmp->prev;

		/* Move to the end of the list */
		while (tmp->next != NULL)
		{
			el_count++;
			tmp = tmp->next;
		}

		if (el_count < 2)
			print_line_error(line_number, "can't add, stack too short");

		sum = tmp->n + (tmp->prev)->n;
		(tmp->prev)->n = sum;
		(tmp->prev)->next = NULL;
		free(tmp);
	}
}
