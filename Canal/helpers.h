/*
File: modular_funcs_header.h
Creator: Isaac Powrie
Date: 2019-01-04

This file contains the header information for functionality
within the canal program which can be used by other programs, 
spanning functionality in helpers.c
*/

#ifndef HELPERS_H
#define HELPERS_H

////////////////////////////////////
/* Function headers for helpers.c */
////////////////////////////////////

// display window
void display(char window[][81], int scrn_depth);

// pause execution and wait for "enter" to continue
void pause(void);

// clear standard input buffer of all characters
void clearKeyboard(void);

// check if integer selection in range
int chk_int_range(int min, int max);

// clear screen
void clear(void);

#endif