// Funcionality for hangman game
// Isaac Powrie
// 2018-11-09
// funcs.c

#include <stdio.h>

#include "hangman.h"

// Clear Keyboard for new input
//
void clearKeyboard(void)
{
	while (getchar() != '\n');
}

// Introduce user options for gameplay
//
void intro_display(void)
{
	int option = 0;

	do {
		printf("|-- Hello! Welcome to HANGMAN --|"
			"\n================================"
			"\n1.) User Generated Puzzle"
			"\n2.) Computer Generated Puzzle"
			"\n0.) Exit HANGMAN");
		printf("\n\n(Enter a Number to Select) ");
		scanf("%d", &option);

		switch (option) {
		case 1:
			system("cls");
			//system("clear");
			strt_dub_game();
			break;
		case 2:
			system("cls");
			//system("clear");
			strt_sing_game();
			break;
		case 0:
			system("cls");
			//system("clear");
			printf("Thanks for playing!");
			break;
		default:
			system("cls");
			//system("clear");
			printf("%d is not a valid option!"
				"\nPlease select from the list below:\n\n", option);
		}
	} while (option != 0);
}

// Start two player mode
//
void strt_dub_game(void) {
	struct Game n_game = { 0 };
	char image[IMG_L][IMG_W] = {
		{"==================================="},
		{"|          ________________       |"},
		{"|                        | |      |"},
		{"|                        | |      |"},
		{"|                        | |      |"},
		{"|                        | |      |"},
		{"|                        | |      |"},
		{"|                        | |      |"},
		{"|                        | |      |"},
		{"|                        | |      |"},
		{"|                        | |      |"},
		{"|                        | |      |"},
		{"|                        | |      |"},
		{"|                  ===============|"},
		{"==================================="}
	};

	get_puzzle(&n_game);
	game_display(&n_game, image);
	
}

// Start single player mode
//
void strt_sing_game(void) {
	struct Game n_game = { 0 };
	char image[IMG_L][IMG_W] = {
		{"==================================="},
		{"|          ________________       |"},
		{"|                        | |      |"},
		{"|                        | |      |"},
		{"|                        | |      |"},
		{"|                        | |      |"},
		{"|                        | |      |"},
		{"|                        | |      |"},
		{"|                        | |      |"},
		{"|                        | |      |"},
		{"|                        | |      |"},
		{"|                        | |      |"},
		{"|                        | |      |"},
		{"|                  ===============|"},
		{"==================================="}
	};

	load_puzzle(&n_game);
	game_display(&n_game, image);

}

// Load user defined puzzle input
//
void get_puzzle(struct Game *n_game)
{
	char YorN;

	do {
		printf("|------ INITIALIZE PUZZLE ------|"
			"\n================================");

		printf("\n\nPlease enter a n_game below: "
			"\n(%d characters max: <ENTER> to continue)\n\n", SIZE);
		scanf(" %50[^\n]", n_game->answer);

		clearKeyboard();
		system("cls");
		//system("clear");

		printf("%s\n\n", n_game->answer);
		printf("Is this the puzzle you would like to submit (y/n)? ");
		scanf(" %c", &YorN);
		if (YorN == 'Y' || YorN == 'y') {
			clearKeyboard();
			system("cls");
			//system("clear");
			load_unsolved(&(*n_game));
		} else {
			clearKeyboard();
			system("cls");
			//system("clear");
		}
	} while (YorN != 'Y' && YorN != 'y');

}

// Load computer puzzle input
//
void load_puzzle(struct Game *n_game)
{
	int choice, check, i;
	char puzzles[PZL_NUM][SIZE + 1] = { 0 };
	load_comp_puzzles(puzzles);

	do {
		printf("|------ INITIALIZE PUZZLE ------|"
			"\n================================");
		printf("\n\nEnter a number between 1 and %d  (INCLUSIVE) -> ", PZL_NUM);
		scanf("%d", &choice);
		check = isInRange(&choice, PZL_NUM);
	} while (check == 0);

	for (i = 0; i < SIZE; i++) {
		n_game->answer[i] = puzzles[choice - 1][i];
	}
	load_unsolved(n_game);
}

//Initialize unsolved for start of game
//
void load_unsolved(struct Game *n_game)
{
	int i;
	int check = 0;

	for (i = 0; i < SIZE; i++) {
		mk_low(&n_game->answer[i]);

		check = in_alpha(&n_game->answer[i]);

		if (check == 1) {
			n_game->hidden[i] = '_';
			n_game->is_alpha[i] = 1;
		} else {
			n_game->hidden[i] = n_game->answer[i];
		}
	}
}

// Print Screen
//
void game_display(struct Game *n_game, char image[][IMG_W])
{
	char msg[M_LEN] = "Welcome to hangman! Complete the challenge below:";
	int i;
	int exit = 1;

	while (exit != 0) {
		printf("|----------- HANGMAN!! -----------|"
			"\n===================================\n");
		for (i = 0; i < IMG_L; i++) {
			printf("%s\n", image[i]);
		}
		printf("\n%s\n\n", msg);

		for (i = 0; i < SIZE; i++) {
			if (n_game->hidden[i] == '\0') {
				i = SIZE;
			} else if (n_game->is_alpha[i] == 1) {
				printf("%c/", n_game->hidden[i]);
			} else {
				printf("%c", n_game->hidden[i]);
			}
		}
		printf("\n\n");

		if (n_game->gm_ovr != 1) {
			printf("LETTERS GUESSED: "
				"\n---------------\n");
			for (i = 0; i < SIZE; i++) {
				if (n_game->guesses[i] != '\0') {
					printf("%c ", n_game->guesses[i]);
				}
			}
			printf("\n\nEnter any single character to guess -> ");
			scanf(" %c", &n_game->guess);
			proccess_inpt(&(*n_game), msg, image);
		} else {
			printf("Enter '0' to return to main menu -> ");
			scanf("%d", &exit);
		}

		system("cls");
		//system("clear");
		clearKeyboard();
	}
}

// Proccess input
//
void proccess_inpt(struct Game *n_game, char *msg, char image[][IMG_W])
{
	int i;
	int check = 0;
	int guessed = 0;
	int win = 0;
	for (i = 0; i < SIZE; i++) {
		if (n_game->guess == n_game->guesses[i]) {
			guessed = 1;
		}
	}
	for (i = 0; i < SIZE; i++) {
		if (n_game->guess == n_game->answer[i]) {
			n_game->hidden[i] = n_game->answer[i];
			check = 1;
		}
	}
	if (guessed == 1) {
		char new_msg[M_LEN] = "You have already guessed that letter!";
		for (i = 0; i < M_LEN; i++) {
			msg[i] = new_msg[i];
		}
		check = 2;
	} else {
		for (i = 0; i < SIZE; i++) {
			if (n_game->guesses[i] == '\0') {
				n_game->guesses[i] = n_game->guess;
				n_game->guesses[i + 1] = '\0';
				i = SIZE;
			}
		}
	}
	if (check == 1) {
		for (i = 0; i < SIZE; i++) {
			if (n_game->answer[i] == n_game->hidden[i]) {
				win = 1;
			} else {
				win = 0;
				i = SIZE;
			}
		}
		if (win == 0) {
			char new_msg[M_LEN] = "Correct! Your choice has revealed new clues!";
			for (i = 0; i < M_LEN; i++) {
				msg[i] = new_msg[i];
			}
		} else {
			char new_msg[M_LEN] = "CONGRATULATIONS! YOU SOLVED THE PUZZLE!!";
			for (i = 0; i < M_LEN; i++) {
				msg[i] = new_msg[i];
			}
			n_game->gm_ovr = 1;
		}
	} else if (check == 0) {
		char new_msg[M_LEN] = "Incorrect! Your choice is not in the answer.";
		for (i = 0; i < M_LEN; i++) {
			msg[i] = new_msg[i];
		}

		n_game->count += 1;

		switch (n_game->count) {
		case 1:
			chng_img(image[2], "|          __            | |      |");
			chng_img(image[3], "|         /oo\\           | |      |");
			chng_img(image[4], "|         \\__/           | |      |");
			break;
		case 2:
			chng_img(image[5], "|           |            | |      |");
			chng_img(image[6], "|           |            | |      |");
			chng_img(image[7], "|           |            | |      |");
			chng_img(image[8], "|           |            | |      |");
			break;
		case 3:
			chng_img(image[6], "|          /|            | |      |");
			chng_img(image[7], "|         / |            | |      |");
			break;
		case 4:
			chng_img(image[6], "|          /|\\           | |      |");
			chng_img(image[7], "|         / | \\          | |      |");
			break;
		case 5:
			chng_img(image[9], "|          /             | |      |");
			chng_img(image[10], "|          |             | |      |");
			chng_img(image[11], "|         _|             | |      |");
			break;
		case 6:
			chng_img(image[9], "|          / \\           | |      |");
			chng_img(image[10], "|          | |           | |      |");
			chng_img(image[11], "|         _| |_          | |      |");
			break;
		case 7:
			chng_img(image[3], "|         /xx\\           | |      |");
			char new_msg[M_LEN] = "GAME OVER! You have used up all of your guesses";
			for (i = 0; i < M_LEN; i++) {
				msg[i] = new_msg[i];
			}
			n_game->gm_ovr = 1;
			break;
		}
	}
}



