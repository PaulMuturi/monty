#include "monty.h"
#include <stdio.h>
#include <stddef.h>

void pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	while ((*stack)->next != NULL)
		*stack = (*stack)->next;

	while (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->prev;
	}
}
