// Source file for the helper functions
// for outputExcel.c
//
// Isaac Powrie
// helpers.c
// 2018-11-20

#include <stdio.h>
#include <math.h>
#include "helpers.h"
#include "body.h"

/*
DETAILED DESCRIPTIONS OF FUNCTIONS IN HEADER FILES
*/

// Show Linear function when given a
// Function struct
//
void showLinear(struct Function* function, int option)
{
	if (option == 0) {
		printf("\ty = %c(x + %c) + %c\n",
			function->m, function->c, function->b);
	} else {
		char b_sign = '+';
		char c_sign = '+';
		if (function->b_val < 0) {
			b_sign = '-';
		}
		if (function->c_val < 0) {
			c_sign = '-';
		}
		printf("\ty = %d(x %c %d) %c %d\n",
			function->m_val, c_sign, abs(function->c_val), b_sign, abs(function->b_val));
	}
}

// Show Quadratic function when given a
// Function struct
//
void showQuad(struct Function* function, int option)
{
	if (option == 0) {
		printf("\ty = %c(x + %c)^2 + %c\n",
			function->m, function->c, function->b);
	} else {
		char b_sign = '+';
		char c_sign = '+';
		if (function->b_val < 0) {
			b_sign = '-';
		}
		if (function->c_val < 0) {
			c_sign = '-';
		}
		printf("\ty = %d(x %c %d)^2 %c %d\n",
			function->m_val, c_sign, abs(function->c_val), b_sign, abs(function->b_val));
	}
}

// Show Sine function when given a
// Function struct
//
void showSine(struct Function* function, int option)
{
	if (option == 0) {
		printf("\ty = %csin(x + %c) + %c\n",
			function->m, function->c, function->b);
	} else {
		char b_sign = '+';
		char c_sign = '+';
		if (function->b_val < 0) {
			b_sign = '-';
		}
		if (function->c_val < 0) {
			c_sign = '-';
		}
		printf("\ty = %dsin(x %c %d) %c %d\n",
			function->m_val, c_sign, abs(function->c_val), b_sign, abs(function->b_val));
	}
}

// Show Cosine function when given a
// Function struct
//
void showCosine(struct Function* function, int option)
{
	if (option == 0) {
		printf("\ty = %ccos(x + %c) + %c\n",
			function->m, function->c, function->b);
	} else {
		char b_sign = '+';
		char c_sign = '+';
		if (function->b_val < 0) {
			b_sign = '-';
		}
		if (function->c_val < 0) {
			c_sign = '-';
		}
		printf("\ty = %dcos(x %c %d) %c %d\n",
			function->m_val, c_sign, abs(function->c_val), b_sign, abs(function->b_val));
	}
}

// clearKeyboard
// Clear the standard input buffer
void clearKeyboard(void)
{
	// empty execution code block on purpose
	while (getchar() != '\n');
}

// yes or no function
//
int yes_or_no(void)
{
	char y_or_n = '\0';
	int val = 0;

	do {
		scanf(" %c", &y_or_n);
		clearKeyboard();

		switch (y_or_n) {
		case 'y':
		case 'Y':
			val = 1;
			break;
		case 'n':
		case 'N':
			val = 0;
			break;
		default:
			printf("\n<please enter either 'y' or 'n'> ");
			val = -1;
		}
	} while (val < 0);

	return val;

}

// option in range function
//
int option_in_range(int min, int max)
{
	int choice = 0;
	do {
		scanf("%d", &choice);
		clearKeyboard();
		if (choice < min || choice > max) {
			printf("\n<value must be in range %d - %d> ", min, max);
		}
	} while (choice < min || choice > max);

	return choice;
}

// Allows user to enter integer into function
//
void getInt(int *chng_var, char constant)
{
	printf("Enter a new value for '%c': ", constant);
	scanf("%d", chng_var);
	system("cls");
}

// Get name for file
//
void createFileName(char filename[])
{
	printf("What would you like to name your file? ");
	scanf("%s", filename);
	clearKeyboard();

	system("cls");
}

// Pause
//
void pause(void)
{
	printf("<press enter to continue> ");
	scanf("*%[]");
}

// Print graph image svg
//
void printGraph(FILE * svg)
{
	int i = 0;
	fprintf(svg, 
		"<path fill=\"none\" stroke=\"grey\" stroke-width=\"1px\" d=\"M 0 300 L 900 300 Z M 450 0 L 450 600 Z\" />\n"
		"<path fill=\"none\" stroke=\"grey\" stroke-width=\"1px\" d=\" \n"
		"M 50 298 l 0 4\n");
	for (i = 0; i < 16; i++) {
		fprintf(svg, "m 50 -4 l 0 4\n");
	}
	fprintf(svg, "\"/>\n");
	fprintf(svg, "<path fill=\"none\" stroke=\"grey\" stroke-width=\"1px\" d=\" \n"
		"M 448 50 l 4 0\n");
	for (i = 0; i < 10; i++) {
		fprintf(svg, "m -4 50 l 4 0\n");
	}
	fprintf(svg, "\"/>\n");
}
