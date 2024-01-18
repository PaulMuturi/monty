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
void pint(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	while ((*stack)->next != NULL)
		*stack = (*stack)->next;

	fprintf(stdout, "%d\n", (*stack)->n);
}
