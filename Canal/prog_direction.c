/*
File: prog_direction.c
Creator: Isaac Powrie
Date: 2019-01-04

This file contains the functions which control the
flow of activity, like parent body functions which
call and organize more specific functionality
*/

#include <time.h>
#include <stdio.h>

#include "window.h"
#include "prog_direction.h"
#include "prog_math.h"
#include "helpers.h"

// check if id is valid and associated with statistics,
// return a negative if no valid id selected
int chk_id(struct Packet* packet) {
	int i, id;


	printf("\nPlease enter an ID ('0' to exit): ");
 	scanf("%d", &id);
	clearKeyboard();

	if (id == 0) {
		id = -1;
	} else {
		for (i = 0; i < 4; i++) {
			if (packet->files[i].id == id) {
				i = 4;
			} else if (i == 3) {
				id = 0;
			}
		}
	}

	return id;
}

// intro display shows opening graphic and waits for
// enter to continue
void intro_display(void) {
	char start_scrn[20][81] = {
		"================================================================================",
		"|8|                      WELCOME TO CANAL - VERSION 1.0                      |8|",
		"|8|==========================================================================|8|",
		"|8|--------------------------------------------------------------------------|8|",
		"|8|                                     __                                   |8|",
		"|8|                    /////////////////||////////////////                   |8|",
		"|8|                    +++++++++++++++++||++++++++++++++++                   |8|",
		"|8|  _____             \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\||\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\                   |8|",
		"|8|  |^^^|             +++++++++++++++++||++++++++++++++++            _____  |8|",
		"|8|  | ||              ///////////(o)///||////////////////            |^^^|  |8|",
		"|8|    ||                          \\\\   ||                             // |  |8|",
		"|8|    ||===========================\\\\===============================///     |8|",
		"|8|    \\\\++o++o++o++o++o++o++o++o++o+\\\\++o++o++o++o++o++o++o++o++o+//^^      |8|",
		"|8|     \\\\============================\\\\=========================///         |8|",
		"|8|~^~^~^\\\\____________________________\\\\____________________\\\\//~^~^~^~^~^~^|8|",
		"|8|~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~\\\\^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^|8|",
		"|8|~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^|8|",
		"|8|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|8|",
		"|8 ========================================================================== 8|",
		"================================================================================"
		};
	display(start_scrn, 20);
	pause();
	clear();
}

// main menu displays the main selection menu for canal,
// also initializes session Packet
void main_menu(void) {
	struct Packet packet = { 0 };
	int choice = 0;
	int exit = 0;
	
	packet.date = time(NULL);
	do {
		do {
			// modify display
			change_window(&packet, 1);
			display(packet.cur_win.window, 20);
			// get user selection
			if (choice < 0) {
				printf("<Selection invalid, please select from the list above>\n");
			}
			choice = chk_int_range(0, 4);
		} while (choice < 0);

		// route user to selected action
		switch (choice) {
		case 1:
			clear();
			add_file(&packet);
			break;
		case 2:
			clear();
			remove_file(&packet);
			break;
		case 3:
			clear();
			view_stats(&packet);
			break;
		case 4:
			clear();
			create_report(&packet);
			break;
		case 0:
			clear();
			do {
				printf("Are you sure that you want to exit? ");
				exit = y_or_n();
			} while (exit == 2);
			clear();
			break;
		}
	} while (exit == 0);
}

// add file to packet
void add_file(struct Packet* packet) {
	int i = 0;
	int flag = 0;
	int index;
	FILE *csvfp = NULL;

	// check to find empty file in files array
	while (flag == 0) {
		if (packet->files[i].id == 0) {
			index = i;
			flag = 1;
		} else if (i == 4) {
			printf("Your file storage array is full.\n"
				"A file must be removed before a\n"
				"new one can be added.\n");
			flag = 2;
		} else {
			printf("%d", packet->files[i].id);
			i++;
		}
	}

	// load data from file into array in memory
	if (flag != 2) {
		printf("Enter the name of your CSV file: ");
		scanf("%s", packet->files[index].filename);
		clearKeyboard();
		printf("\nLoading file...  ");
		csvfp = fopen(packet->files[index].filename, "r");
		if (csvfp) {
			// populate file id and load data array
			packet->files[index].id = index + 1;
			i = 0;
			do {
				fscanf(csvfp, "%lf,%lf%*[]\n", 
					&packet->files[index].data[0][i], 
					&packet->files[index].data[1][i]);
				i++;
			} while (feof(csvfp) != 1);
			packet->files[index].n = i;
			printf("Completed.\n");
			pause();

			// calculate statistics for relevant variable data
			clear();
			collect_stats(&packet->files[index]);
			fclose(csvfp);
		} else {
			printf("File not found.\n");
		}
	}
	pause();
	clear();
}

// calculate statistics for CSV being loaded
void collect_stats(struct File* file) {
	int size = file->n;
	int col = -1;
	// determine which column contains relevant variable data
	while (col != 0 && col != 1) {
		printf("Which column contains variable data for\n"
			"statistics creation (1 or 2)? ");
		scanf("%d", &col);
		col -= 1;
		clearKeyboard();
		if (col != 0 && col != 1) {
			clear();
			printf("Please enter either '1' or '2'\n");
		}
	}

	// calculate the stats for selected column
	printf("\nMIN PRIOR: %lf\n\n", file->stats.min);
	file->stats.min = min(&file->data[col][0], size);
	printf("MIN RETURNED: %lf\n\n", file->stats.min);
	file->stats.max = max(&file->data[col][0], size);
	printf("MAX RETURNED: %lf\n\n", file->stats.max);
	file->stats.range = range(file->stats.max, file->stats.min);
	printf("RANGE RETURNED: %lf\n\n", file->stats.range);
	file->stats.mean = mean(file->data[col], size);
	printf("MEAN RETURNED: %lf\n\n", file->stats.mean);
	file->stats.median = median(file->data[col], size);
	printf("MEDIAN RETURNED: %lf\n\n", file->stats.median);
	file->stats.mode = mode(file->data[col], size);
	printf("MODE RETURNED: %lf\n", file->stats.mode);
	file->stats.stddev = stddev(file->data[col], size);
	file->stats.s_stddev = s_stddev(file->data[col], size);
	file->stats.variance = variance(file->data[col], size);
	file->stats.s_variance = s_variance(file->data[col], size);
}

// remove the statistics of a loaded CSV given an ID
void remove_file(struct Packet* packet) {
	int id = 1;
	int i, j;

	do {
		// modify display
		change_window(packet, 2);
		display(packet->cur_win.window, 20);

		if (id == 0) {
			printf("<Last ID entry invalid, please select from the list above>\n");
		}

		printf("Which file would you like to remove?\n");
		id = chk_id(packet);
		clear();
	} while (id == 0);

	if (id > 0) {
		// remove statistics
		struct Stats empty = { 0 };
		packet->files[id - 1].stats = empty;
		// remove data array
		for (i = 0; i < 2; i++) {
			for (j = 0; j < 15000; j++) {
				packet->files[id - 1].data[i][j] = 0;
			}
		}
		// remove filename
		i = 0;
		while (packet->files[id - 1].filename[i] != '\0') {
			packet->files[id - 1].filename[i] = '\0';
			i++;
		}
		// remove remaining data
		packet->files[id - 1].id = 0;
		packet->files[id - 1].n = 0;
		display(packet->cur_win.window, 20);
		printf("File information has been removed from program memory.\n");
		pause();
		clear();
	} else {
		// guide user back to main menu
		clear();
		display(packet->cur_win.window, 20); 
		printf("No action taken, all files left in program memory.\n");
		pause();
		clear();
	}
	
}

// display the statistics calculated for a loaded CSV
void view_stats(struct Packet* packet) {
	int id = 1;

	do {
		// modify display
		change_window(packet, 2);
		display(packet->cur_win.window, 20);

		if (id == 0) {
			printf("<Last ID entry invalid, please select from the list above>\n");
		}

		printf("Which file would you like to view?\n");
		id = chk_id(packet);
		clear();
	} while (id == 0);

	if (id > 0) {
		packet->fl_idx = id - 1;
		// display statistics
		change_window(packet, 3);
		display(packet->cur_win.window, 20);
		pause();
		clear();
	} else {
		// guide user back to main menu
		display(packet->cur_win.window, 20);
		printf("No action taken, you have selected to view no summaries.\n");
		pause();
		clear();
	}
}

// display user options for statistical file outputs and
// execute the user's selection
void create_report(struct Packet* packet) {
	int choice = 0;

	do {
		// modify display
		change_window(packet, 4);
		display(packet->cur_win.window, 20);
		// get user selection
		if (choice < 0) {
			printf("<Selection invalid, please select from the list above>\n");
		}
		choice = chk_int_range(0, 5);
		clear();
	} while (choice < 0);

	// route user to selected report output
	switch (choice) {
	case 3:
		printf("Yo wait here just a sec...\n");
		pause();
		clear();
		break;
	default:
		printf("Yo wait here just a sec...\n");
		pause();
		clear();
		break;
	}
}
