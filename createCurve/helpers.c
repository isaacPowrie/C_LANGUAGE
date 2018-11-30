// Source file for the helper functions
// for outputExcel.c
//
// Isaac Powrie
// helpers.c
// 2018-11-20

#include <stdio.h>
#include <math.h>
#include "helpers.h"

#define PI 3.14159265358979323846

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

// toRads function takes a degree value for an angle 
// and converts it to radians
//
double toRads(double angle)
{
	double rads;

	rads = angle * PI / 180.0;

	return rads;
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

// Get start for x
//
int getStartingX(void)
{
	int x = 0;

	printf("Enter a starting integer for x: ");
	x = option_in_range(-100000, 100000);
	system("cls");

	return x;
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