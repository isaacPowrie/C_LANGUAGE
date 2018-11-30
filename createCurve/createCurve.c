/*
This program contains several options of curves to
output to a CSV, which can be connected to an excel 
spreadsheet for graphical analysis
*/
// Isaac Powrie
// outputExcel.c
// 2018-11-20

#include <stdio.h>
#include "helpers.h"

int main(void)
{
	int exit = 0;
	do {
		exit = menu();
		system("cls");
	} while (exit != 0);

	return 0;
}
