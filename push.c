#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
  *push - pushes an item at the end of doubly linked list
  *@stack: doubly linked list
  *@line_number: line with the push opcode
  *
  *Return: void
  */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		print_error("Error: malloc failed", "\0");

	while (*stack && (*stack)->next != NULL)
		*stack = (*stack)->next;

	if (*op_arg == 0)
	{
		free(new_node);
		print_line_error(line_number, "usage: push integer");
	}

	new_node->next = NULL;
	if (*stack)
	{
		(*stack)->next = new_node;
		new_node->prev = *stack;
	}
	else
		new_node->prev = NULL;

	new_node->n = *op_arg;

	*stack = new_node;
}
