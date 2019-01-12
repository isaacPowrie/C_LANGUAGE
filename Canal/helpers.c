/*
File: helpers.c
Creator: Isaac Powrie
Date: 2019-01-04

This file contains functions which facilitate common menu
and validation activity. These functions are modular and
are used throughout the canal program
*/

#include <stdio.h>
#include "window.h"
#include "prog_direction.h"
#include "prog_math.h"
#include "helpers.h"

// display window
void display(char window[][81], int scrn_depth) {
	int i;
	for (i = 0; i < scrn_depth; i++) {
		printf("%s\n", window[i]);
	}
}

// pause execution and wait for "enter" to continue
void pause(void) {
	printf("\n<Press 'ENTER' to continue>");
	clearKeyboard();
}

// clear standard input buffer of all characters
void clearKeyboard(void) {
	while (getchar() != '\n');
}

// check if integer selection in range of positive, returns negative if error
int chk_int_range(int min, int max) {
	int choice;
	int exit = 1;

	if (max >= min && min >= 0) {
		printf("Enter a selection between %d and %d: ", min, max);
		scanf("%d", &choice);
		clearKeyboard();

		if (choice < min || choice > max) {
			clear();
			choice = -1;
		}
	} else {
		printf("Your min (%d) and max (%d) values are not consistent with functional logic.\n"
			"Please ensure that max is greater than min and that both are positive!\n");
		choice = -1;
		pause();
	}

	return choice;
}

// retrieve yes or no response, returns negative on error
int y_or_n(void) {
	char y_or_n;
	int choice = 2;
	scanf("%c", &y_or_n);
	clearKeyboard();
	switch (y_or_n) {
	case 'Y':
	case 'y':
		choice = 1;
		break;
	case 'N':
	case 'n':
		choice = 0;
		break;
	default:
		clear();
		printf("Please enter either 'y' or 'n'\n");
	}

	return choice;
}

// clear screen
void clear(void) {
	system("cls");
	//system("clear");
}