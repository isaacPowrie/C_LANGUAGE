/*
File: window.c
Creator: Isaac Powrie
Date: 2019-01-04

This file contains the function which affects changes to
windows in the canal program.
*/

#include <stdio.h>
#include "window.h"
#include "prog_direction.h"
#include "prog_math.h"
#include "helpers.h"

// take in Window struct and selection int and 
// alter the window according to the selection
/*
	1.) Main Menu
	2.) Lists Loaded Files
	3.) Display Stats Report
	4.) Display Report Options
*/
void change_window(struct Packet* packet, int selection) {
	int i, j;
	char chng_win[WIN_LEN][WIN_WIDTH] = {
			{"================================================================================"},
			{"|8|                                                                         |8|"},
			{"|8|                                                                         |8|"},
			{"|8|                                                                         |8|"},
			{"|8|                                                                         |8|"},
			{"|8|                                                                         |8|"},
			{"|8|                                                                         |8|"},
			{"|8|                                                                         |8|"},
			{"|8|                                                                         |8|"},
			{"|8|                                                                         |8|"},
			{"|8|                                                                         |8|"},
			{"|8|                                                                         |8|"},
			{"|8|                                                                         |8|"},
			{"|8|                                                                         |8|"},
			{"|8|                                                                         |8|"},
			{"|8|                                                                         |8|"},
			{"|8|                                                                         |8|"},
			{"|8|                                                                         |8|"},
			{"|8|                                                                         |8|"},
			{"================================================================================"},
	};

	switch (selection) {
	case 1:
		snprintf(chng_win[5], 81,
			"|8|                                MAIN MENU                                |8|");
		snprintf(chng_win[7], 81, 
			"|8|                       1.) Add a File                                    |8|");
		snprintf(chng_win[8], 81,
			"|8|                       2.) Remove a File                                 |8|");
		snprintf(chng_win[9], 81,
			"|8|                       3.) View Statistics                               |8|");
		snprintf(chng_win[10], 81,
			"|8|                       4.) Create a Report                               |8|");
		snprintf(chng_win[12], 81,
			"|8|                       (0 to exit program)                               |8|");
		break;
	case 2:
		snprintf(chng_win[5], 81,
			"|8|                              YOUR PROFILES                              |8|");
		snprintf(chng_win[7], 81,
			"|8|                       ID    FILENAME                                    |8|");
		for (i = 0; i < 4; i++) {
			snprintf(chng_win[i + 8], 81,
				"|8|                       %-6d%-14s...                           |8|",
				packet->files[i].id, packet->files[i].filename);
		}
		break;
	case 3:
		snprintf(chng_win[5], 81,
			"|8|                         STATS FOR %10s...                         |8|",
			packet->files[packet->fl_idx].filename);
		snprintf(chng_win[7], 81,
			"|8|               min:%13.2lf          max:%13.2lf              |8|",
			packet->files[packet->fl_idx].stats.min, packet->files[packet->fl_idx].stats.max);
		snprintf(chng_win[8], 81,
			"|8|               range:%11.2lf          mean:%12.2lf              |8|",
			packet->files[packet->fl_idx].stats.range, packet->files[packet->fl_idx].stats.mean);
		snprintf(chng_win[9], 81,
			"|8|               median:%10.2lf          mode:%12.2lf              |8|",
			packet->files[packet->fl_idx].stats.median, packet->files[packet->fl_idx].stats.mode);
		snprintf(chng_win[10], 81,
			"|8|               var:%13.2lf          stdev:%11.2lf              |8|",
			packet->files[packet->fl_idx].stats.variance, packet->files[packet->fl_idx].stats.stddev);
		snprintf(chng_win[11], 81,
			"|8|               s_var:%11.2lf          s_stdev:%9.2lf              |8|",
			packet->files[packet->fl_idx].stats.s_variance, packet->files[packet->fl_idx].stats.s_stddev);
		break;
	case 4:
		snprintf(chng_win[5], 81,
			"|8|                              REPORTS MENU                               |8|");
		snprintf(chng_win[7], 81,
			"|8|                       1.) Not Yet Designed                              |8|");
		snprintf(chng_win[8], 81,
			"|8|                       2.) Not Yet Designed                              |8|");
		snprintf(chng_win[9], 81,
			"|8|                       3.) Not Yet Designed                              |8|");
		snprintf(chng_win[10], 81,
			"|8|                       4.) Not Yet Designed                              |8|");
		snprintf(chng_win[11], 81,
			"|8|                       5.) Not Yet Designed                              |8|");
		snprintf(chng_win[13], 81,
			"|8|                       (0 to exit program)                               |8|");
		break;
	}

	for (i = 0; i < WIN_LEN; i++) {
		for (j = 0; j < WIN_WIDTH; j++) {
			packet->cur_win.window[i][j] = chng_win[i][j];
		}
	}
}