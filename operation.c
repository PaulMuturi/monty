#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
  *print_line_error - prints error encountered at a certain line
  *@line_number: line where error occured
  *@msg: error message to print
  *
  *Return: void
  */
void print_line_error(unsigned int line_number, char *msg)
{
	fprintf(stderr, "L%u: %s\n", line_number, msg);
	exit(EXIT_FAILURE);
}

/**
  *print_error - prints error and exits program
  *@msg: error message for display
  *@cat_arg: string to concatenate to error msg
  *
  *Return: void
  */
void print_error(char *msg, char *cat_arg)
{
	if (cat_arg)
		fprintf(stderr, "%s %s\n", msg, cat_arg);
	else
		fprintf(stderr, "%s\n", msg);
	exit(EXIT_FAILURE);
}
