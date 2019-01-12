/*
File: window.h
Creator: Isaac Powrie
Date: 2019-01-04

This file contains the header information for functionality
specific to the window.c file, containing the Window
structure definition
*/

#ifndef WINDOW_H
#define WINDOW_H

#define WIN_LEN 20
#define WIN_WIDTH 81

///////////////////////////
/* Structure Definitions */
///////////////////////////

// Window contains information which will be displayed 80 x (Length)
struct Window {
	char window[WIN_LEN][WIN_WIDTH];
};

////////////////////////////////////
/* Functions Headers for window.c */
////////////////////////////////////

// take in Window struct and selection int and 
// alter the window according to the selection
void change_window(struct Packet* packet, int selection);

#endif