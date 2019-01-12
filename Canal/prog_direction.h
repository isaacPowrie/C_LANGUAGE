/*
File: prog_direction.h
Creator: Isaac Powrie
Date: 2019-01-04

This file contains the header information for functionality
specific to the progr_direction.c file, spanning functionality in
prog_direction.c and containing the Stats, and Packet structure 
definitions
*/

#ifndef PROG_DIR_H
#define PROG_DIR_H

#include <time.h>
#include <stdio.h>

#include "window.h"

#define FILENAME_S 100

///////////////////////////
/* Structure Definitions */
///////////////////////////

// Stats contains summary stats for each CSV loaded into Canal
struct Stats {
	double mean;
	double median;
	double mode;
	double stddev;
	double variance;
	double s_stddev;
	double s_variance;
	double max;
	double min;
	double range;
};

// File contains the information associated with a specific loaded CSV
struct File {
	int id;
	char filename[FILENAME_S];
	struct Stats stats;
	int n;
	double data[2][15000];
};

// Packet contains the (max 4) files loaded into Canal
struct Packet {
	int session_id;				// used to help identify files created during same session, not implemented
	int fl_idx;			// used to track selection between funcs
	time_t date;
	struct File files[4];
	struct Window cur_win;
};

///////////////////////////////////////////
/* Function Headers for prog_direction.c */
///////////////////////////////////////////


// check if id is valid and associated with statistics
int chk_id(struct Packet* packet);

// intro display shows opening graphic and waits for
// enter to continue
void intro_display(void);

// main menu displays the main selection menu for canal,
// also initializes session Packet
void main_menu(void);

// add file to packet
void add_file(struct Packet* packet);

// calculate statistics for CSV being loaded
void collect_stats(struct File* file);

// remove the statistics of a loaded CSV given an ID
void remove_file(struct Packet* packet);

// display the statistics calculated for a loaded CSV
void view_stats(struct Packet* packet);

// display user options for statistical file outputs and
// execute the user's selection
void create_report(struct Packet* packet);

////////////////////////////////////
/* Functions Headers for window.c */
////////////////////////////////////

// take in Window struct and selection int and 
// alter the window according to the selection
void change_window(struct Packet* packet, int selection);

#endif