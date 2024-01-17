#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		print_error("Error: malloc failed", "\0");

	while (*stack && (*stack)->next != NULL)
		*stack = (*stack)->next;

	if (!op_arg)
	{
		free(new_node);
		fprintf(stderr, "L%u: usage: push integer", line_number);
	}

	if (*stack)
	{
		(*stack)->next = new_node;
		new_node->prev = *stack;
	}
	else
	{
		new_node->prev = NULL;
		new_node->next = NULL;
	}
			
	new_node->n = *op_arg;

	*stack = new_node;
}
