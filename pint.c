#include "monty.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/**
  * pint- prints all the value at the top of the stack
  *@stack: doubly linked list
  *@line_number: line with the push opcode
  *
  *Return: void
  */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		print_line_error(line_number, "can't pint, stack empty");

	while ((*stack)->next != NULL)
		*stack = (*stack)->next;

	fprintf(stdout, "%d\n", (*stack)->n);
}
