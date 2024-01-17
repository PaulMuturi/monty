#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <string.h>
/**
  *main - entry point to the program
  *@argv: array of strings arguments
  *@argc: arguments count
  *
  *Return: 0 if successiful
 */
int main(int argc, char **argv)
{
	FILE *fl;
	char *line = NULL;
	char *opc = NULL;
	unsigned int i;
	size_t n = 0;	

	if (argc < 2)
		print_error("USAGE: monty file", '\0');

	fl = fopen(argv[1], "r");
	if (fl == NULL)
		print_error("Error: Can't open file", argv[1]);

	for (i = 1; getline(&line, &n, fl) != -1; i++)
	{
		opc = extractOpcode(line, opc);
		
		printf("%d\n", *op_arg);
		if (opc)
			getFunction(opc, i);
	}
	free(line);
	return (0);
}
/**
  *
  *
  */
void getFunction(char *op_code, unsigned int line_number)
{
	instruction_t *instruction = malloc(sizeof(instruction_t));
	if (instruction == NULL)
		print_error("Error: malloc failed", "\0");

	instruction->opcode = op_code;
	
	printf("line_number: %u\n", line_number);
/*	switch (op_code)
	{
		case "push":
			instruction.f = pushItem;
			break;
		case "pall":
			instruction.f = pallItems;
			break;
		default:
			free(instruction);
			fprintf(stderr, "L%u: unknown instruction %s", line_number, op_code);
			exit(EXIT_FAILURE);
	}
*/
	/*executeCode(instruction, line_number)*/



}


/**
  *extractOpcode - checks if a string is valid opcode structure
  *@line: string to check
  *@opc_ptr: pointer for storing opcode
  *
  *Return: opcode if valid, NULL invalid
  */
char *extractOpcode(char *line, char *opc_ptr)
{
	char opc[200] = "\0", ch, val[200] = "\0";
	int idx_opc = 0, idx_val = 0, i = 0, intval;

/*	printf("line: %s\n", line);*/
	while (line[i] != '\n' && line[i] != '\0')
	{
		ch = line[i];
		if (ch != ' ' && idx_opc >= 0)
		{
			opc[idx_opc] = ch;
			idx_opc++;
		}
		else
		{
			/* Reset opc to -1 to mean the opcode is complete*/
			if (idx_opc > 0)
			{
				opc[idx_opc] = '\0';
				idx_opc = -1;
			}
		}
		if (ch != ' ' && idx_opc == -1 && idx_val >= 0)
		{
			val[idx_val] = ch;
			idx_val++;
		}
		else
		{
			if (idx_val > 0)
			{
				val[idx_val] = '\0';
				idx_val = -1;
			}
		}
		i++;
	}
	opc_ptr = strdup(opc);
	intval = atoi(val);
	op_arg = &intval;
	return (opc_ptr);
}


/**
  *print_error - prints error and exits program
  *@msg: error message for display
  *@cat_arg: string to concatenate when print
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
