#include "monty.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/**
  *swap - Swaps the first two elements
  *@stack: doubly linked list
  *@line_number: line with the push opcode
  *
  *Return: void
  */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int el_count = 1, swp_holder;

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
			print_line_error(line_number, "can't swap, stack too short");

		swp_holder = (tmp->prev)->n;
		(tmp->prev)->n = tmp->n;
		tmp->n = swp_holder;
	}
}
