#include "monty.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/**
  *pop- removes the top element of the stack
  *@stack: doubly linked list
  *@line_number: line with the push opcode
  *
  *Return: void
  */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if ((*stack) == NULL)
		print_line_error(line_number, "can't pop an empty stack");

	while (tmp->next != NULL)
		tmp = tmp->next;

	if (tmp->prev != NULL)
	{
		tmp = tmp->prev;
		free(tmp->next);
		tmp->next = NULL;
	}
	else
	{
		free(tmp);
		*stack = NULL;
	}
}
