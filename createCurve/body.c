// Source file for the body functions
// for outputExcel.c
//
// Isaac Powrie
// body.c
// 2018-11-20

#include <stdio.h>
#include <math.h>
#include "helpers.h"


// menu function takes no parameters and displays the options list 
// as well as handling option selection.
//
int menu(void)
{
	int selection;
	struct Function function = {
		{ 0 }, 'm', 0, 'b', 0, 'c', 0 
	};

	printf("|---- Enter Number to Select ----|\n\n"
		"1.) Linear\n");
	showLinear(&function, 0);
	printf("2.) Quadratic\n");
	showQuad(&function, 0);
	printf("3.) Sine\n");
	showSine(&function, 0);
	printf("4.) Cosine\n");
	showCosine(&function, 0);
	printf("0.) Exit");

	printf("\n\nEnter your selection: ");
	selection = option_in_range(0, 4);

	switch (selection) {
	case 1:
		function.type = 'L';
		getUserInpt(&function);
		break;
	case 2:
		function.type = 'Q';
		getUserInpt(&function);
		break;
	case 3:
		function.type = 'S';
		getUserInpt(&function);
		break;
	case 4:
		function.type = 'C';
		getUserInpt(&function);
		break;
	}

	return selection;
}

// showMyFunc determines what type of function the user is trying
// to ouput and displays the function with letters for constants in
// a line above a function with the current integer values of
// constants
//
void showMyFunc(struct Function *function) {
	if (function->type == 'L') {
		showLinear(function, 0);
		showLinear(function, 1);
	} else if (function->type == 'Q') {
		showQuad(function, 0);
		showQuad(function, 1);
	} else if (function->type == 'S') {
		showSine(function, 0);
		showSine(function, 1);
	} else if (function->type == 'C') {
		showCosine(function, 0);
		showCosine(function, 1);
	};
}

// getUserInpt function takes a structure function which corresponds to a 
// selection option. The function prints out and the user replaces the 
// the values of the constants with those of their desired curve.
//
void getUserInpt(struct Function *function)
{
	char val = '\0';
	int y_or_n = 0;

	do {
		system("cls");
		printf("|--- Enter Values to Complete Your Function ---|\n\n");

		showMyFunc(function);

		printf("\nSelect a constant to adjust ('m', 'b', or 'c'): ");
		do {
			scanf("%c", &val);
			if (val != 'm' && val != 'b' && val != 'c') {
				clearKeyboard();
				printf("\n<Invalid entry! please enter 'm', 'b', or 'c'> ");
			}
		} while (val != 'm' && val != 'b' && val != 'c');

		switch (val) {
		case 'm':
			system("cls");
			getInt(&function->m_val, 'm');
			showMyFunc(function);
			clearKeyboard();
			printf("\n\nIs your function ready for output to file (y/n)? ");
			y_or_n = yes_or_no();
			break;
		case 'b':
			system("cls");
			getInt(&function->b_val, 'b');
			showMyFunc(function);
			clearKeyboard();
			printf("\n\nIs your function ready for output to file (y/n)? ");
			y_or_n = yes_or_no();
			break;
		case 'c':
			system("cls");
			getInt(&function->c_val, 'c');
			showMyFunc(function);
			clearKeyboard();
			printf("\n\nIs your function ready for output to file (y/n)? ");
			y_or_n = yes_or_no();
			break;
		}
	} while (y_or_n == 0);

	switch (function->type) {
	case 'L':
		printLin(function);
		break;
	case 'Q':
		printQuad(function);
		break;
	case 'S':
		printSin(function);
		break;
	case 'C':
		printCos(function);
		break;
	}

	printf("Your file has been successfully created.\n");
	pause();
	system("cls");
}


// printLin function takes the user appended linear function from getUserInpt 
// and it prints ~10000 x and y coordinate pairs to a CSV file.
//
void printLin(struct Function *function)
{
	char filename[FILENAME_MAX];
	double x = 0;
	double y = 0;
	int i, x_strt;

	x_strt = getStartingX();
	createFileName(filename);

	FILE *csvfp = fopen(filename, "w");
	fprintf(csvfp, "X_VALUES,Y_VALUES\n");
	for (i = 0; i < SHEET_SIZE; i++) {
		x = (double)x_strt + (double)i / 10;
		y = x + (double)function->c_val;
		y *= (double)function->m_val;
		y += (double)function->b_val;

		fprintf(csvfp, "%lf,%lf\n", x, y);
	}
	fclose(csvfp);
}

// printQuad function takes the user appended quadratic function from getUserInpt 
// and it prints ~10000 x and y coordinate pairs to a CSV file.
//
void printQuad(struct Function *function)
{
	char filename[FILENAME_MAX];
	double x = 0;
	double y = 0;
	int i, x_strt;

	x_strt = getStartingX();
	createFileName(filename);

	FILE *csvfp = fopen(filename, "w");
	fprintf(csvfp, "X_VALUES,Y_VALUES\n");
	for (i = 0; i < SHEET_SIZE; i++) {
		x = (double)x_strt + (double)i / 1000;
		y = pow((x + (double)function->c_val), 2);
		y *= (double)function->m_val;
		y += (double)function->b_val;

		fprintf(csvfp, "%lf,%lf\n", x, y);
	}
	fclose(csvfp);
}

// printSin function takes the user appended sine function from getUserInpt 
// and it prints ~10000 x and y coordinate pairs to a CSV file.
//
void printSin(struct Function *function)
{
	char filename[FILENAME_MAX];
	double x = 0;
	double y = 0;
	int i, x_strt;

	x_strt = getStartingX();
	createFileName(filename);

	FILE *csvfp = fopen(filename, "w");
	fprintf(csvfp, "X_VALUES,Y_VALUES\n");
	for (i = 0; i < SHEET_SIZE; i++) {
		x = (double)x_strt + (double)i / 10;
		x = toRads(x);
		y = sin(x + (double)function->c_val);
		y *= (double)function->m_val;
		y += (double)function->b_val;

		fprintf(csvfp, "%lf,%lf\n", x, y);
	}
	fclose(csvfp);
}

// printCos function takes the user appended linear cosine from getUserInpt 
// and it prints ~10000 x and y coordinate pairs to a CSV file.
//
void printCos(struct Function *function)
{
	char filename[FILENAME_MAX];
	double x = 0;
	double y = 0;
	int i, x_strt;

	x_strt = getStartingX();
	createFileName(filename);

	FILE *csvfp = fopen(filename, "w");
	fprintf(csvfp, "X_VALUES,Y_VALUES\n");
	for (i = 0; i < SHEET_SIZE; i++) {
		x = (double)x_strt + (double)i / 10;
		x = toRads(x);
		y = cos(x + (double)function->c_val);
		y *= (double)function->m_val;
		y += (double)function->b_val;

		fprintf(csvfp, "%lf,%lf\n", x, y);
	}
	fclose(csvfp);
}

