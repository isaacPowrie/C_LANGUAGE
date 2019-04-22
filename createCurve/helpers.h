// Header file for the helper functions
// for outputExcel.c
//
// Isaac Powrie
// helpers.h
// 2018-11-20

#ifndef FUNCSHELPS
#define FUNCSHELPS
#include <stdio.h>
#include "body.h"

#define PI 3.14159265358979323846

/*
	The Following "Show" function display the text of the
	functions which will be executed and written to files.
	The option parameter allows for the caller to
	determine to display the letter values for constants
	(by passing 0) or to display the integer values in
	which will be passed through (any non zero argument)
*/
// Show Linear function when given a
// Function struct
//
void showLinear(struct Function*, int option);

// Show Quadratic function when given a
// Function struct
//
void showQuad(struct Function*, int option);

// Show Sine function when given a
// Function struct
//
void showSine(struct Function*, int option);

// Show Cosine function when given a
// Function struct
//
void showCosine(struct Function*, int option);

// clearKeyboard
// Clear the standard input buffer
//
void clearKeyboard(void);

// Loop for a yes or no response.
// Returns 1 for yes and 0 for no.
//
int yes_or_no(void);

// Loop for an option in range of ints.
// Returns the selected option.
//
int option_in_range(int min, int max);

// Allows user to enter float into function,
// displays constant signifier (char) and takes
// float to be changed (float *)
//
void getInt(float *, char);

// Get name for file, takes an empty string and
// obtains user input for filename
//
void createFileName(char filename[]);

// Pause, pauses action until user enters a key
//
void pause(void);

// Print graph image svg
//
void printGraph(FILE * svg);

// Print units legend
//
void printLegend(FILE *svg, struct Function *function);

#endif //FUNCSHELPS
