#include "monty.h"
#include <stdio.h>
#include <stddef.h>

/**
  *pall - prints all values of n in the linked list
  *@stack: doubly linked list
  *@line_number: line with the push opcode
  *
  *Return: void
  */
void pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	if (*stack)
	{
		while ((*stack)->next != NULL)
			*stack = (*stack)->next;

		while ((*stack)->prev != NULL)
		{
			printf(stdout, "%d\n", (*stack)->n);
			*stack = (*stack)->prev;
		}

		fprintf(stdout, "%d\n", (*stack)->n);
	}
}
