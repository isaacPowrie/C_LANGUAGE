// Helper functions for hangman
// Isaac Powrie
// 2018-11-09
// helpers.c

#include <stdio.h>

#include "hangman.h"

// checks if letter is in alphabet
//
int in_alpha(char *character) {
	char alpha[DBL_ALPHA + 1] = { "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ" };
	int check = 0;
	int i;

	for (i = 0; i < 52; i++) {
		if (*character == alpha[i]) {
			check = 1;
		}
	}
	return check;
}

// make letter lowercase
//
void mk_low(char *character) {
	char alpha[DBL_ALPHA + 1] = { "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ" };
	int i;

	for (i = 0; i < 52; i++) {
		if (*character == alpha[i] && (i % 2) != 0) {
			*character = alpha[i - 1];
		}
	}
}

// update a string
//
void chng_img(char *original, char *change) {
	int i;
	for (i = 0; i < IMG_W; i++) {
		original[i] = change[i];
	}
}

// check to see if value is in range
//
int isInRange(int *choice, int max)
{
	int check = 0;
	if (*choice < 1 || *choice > max) {
		clearKeyboard();
		system("cls");
		//system("clear");
		printf("%d is not between 1 and %d!\n\n", *choice, max);
	} else {
		clearKeyboard();
		system("cls");
		//system("clear");
		check = 1;
	}

	return check;
}