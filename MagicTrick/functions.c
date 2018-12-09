/*
Isaac Powrie
2018-12-08
numTblMagic.c
*/

/*
Functionality of numTblMagic, more detailed high-level
description of functions in "numTblMagic.h" header file.
*/

#include <stdio.h>
#include "numTblMagic.h"

#define MAX_TBLS 50

void fillTblMeta(struct TablesMeta* tbls)
{
	int i;

	// Look for numTbls input
	printf("How many cards would you like to produce? ");
	scanf("%d", &tbls->numTbls);
	while (getchar() != '\n');

	// Determine row length
	tbls->numColumns = tbls->numTbls <= 4 ? 4 : 8;

	// Calculate the number of places per card
	i = 1;
	tbls->numPlaces = 1;
	while (i < tbls->numTbls) {
		i++;
		tbls->numPlaces = tbls->numPlaces * 2;
	}

	system("cls");
}

void playGame(struct TablesMeta* tbls)
{
	int tlbNum = 1;
	int userChoices[MAX_TBLS] = { 0 };

	// Set up the display of tables for user choice
	userChoice(userChoices, tbls);

	// Determine the user's secret number
	determineAnswer(userChoices);
}

void displayTable(int tblNum, struct TablesMeta* tbls)
{
	int start, next, last, i;

	// Determine start value from tblNum
	start = 1;
	while (tblNum != 1) {
		start *= 2;
		tblNum -= 1;
	}

	// Calculate table
	next = start;
	last = start;

	for (i = 1; i <= tbls->numPlaces; i++) {
		if ((next + 1) % (start * 2) == 0) {
			printf("%d	", next);
			next += (start + 1);
		} else {
			printf("%d	", next);
			next += 1;
		}

		if (i % tbls->numColumns == 0)
			printf("\n");
	}
}

void userChoice(int* userChoices, struct TablesMeta* tbls)
{
	int i, check, index;
	int curTbl = 1;
	char com = '0';

	// Display which allows the user to slide through
	// the tables and select those which contain their
	// secret number
	while (com != 'd') {
		printf("Choose a number from one of the tables and then\n"
			"'select' each table which contains that number.\n");
		printf("_______________________________\n");
		printf("|==|--- TABLE NUMBER %d ---|==|\n\n", curTbl);
		displayTable(curTbl, tbls);
		printf("_______________________________\n");
		printf("YOUR CURRENT CHOICES (DOUBLE ENTRY REMOVES FROM LIST):\n");

		// Display the tables the user has indicated containts
		// their number
		for (i = 0; i < MAX_TBLS; i++) {
			if (userChoices[i] > 0)
				printf("%-4d", userChoices[i]);
		}
		// Navigation options
		printf("\n\nNavigation:\n");
		printf("'b' -- back one table\n");
		printf("'f' -- forward one table\n");
		printf("'s' -- select this table for list\n");
		printf("'d' -- when all tables added\n");
		printf("\nENTER COMMAND: ");
		scanf("%c", &com);
		while (getchar() != '\n');

		// Execute the user selection 
		switch (com) {
		case 'b':
			if (curTbl > 1)
				curTbl -= 1;
			system("cls");
			break;
		case 'f':
			if (curTbl < tbls->numTbls)
				curTbl += 1;
			system("cls");
			break;
		case 's':
			check = 0;
			for (i = 1; i <= tbls->numTbls; i++) {
				if (curTbl == userChoices[i]) {
					check = 1;
					index = i;
				}
			}
			if (check == 1) {
				userChoices[index] = 0;
			} else {
				for (i = 1; i <= tbls->numTbls; i++) {
					if (userChoices[i] == 0) {
						userChoices[i] = curTbl;
						i += tbls->numTbls;
					}
				}
			}
			system("cls");
			break;
		}
	};
	system("cls");
}

void determineAnswer(int* userChoices)
{
	int i, j, power, sum = 0;

	// Determine user number by finding the power of 2
	// raised to each table number selected
	for (i = 0; i < MAX_TBLS; i++) {
		if (userChoices[i] != 0) {
			power = 1;
			for (j = 1; j < userChoices[i]; j++) {
				power *= 2;
			}
			sum += power;
		}
	}
	printf("|==============================|\n");
	printf("|==    Your Number: %5d    ==|\n", sum);
	printf("|==============================|\n");
}
