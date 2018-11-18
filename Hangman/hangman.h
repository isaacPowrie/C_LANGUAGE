// Header file for hangman game
// contains structs, prototypes and macros
// Isaac Powrie
// 2018-11-09
// hangman.h

#define SIZE 50
#define PZL_NUM 100
#define IMG_L 15
#define IMG_W 37
#define M_LEN 100
#define DBL_ALPHA 52

struct Game {
	char answer[SIZE + 1];
	char hidden[SIZE + 1];
	char guesses[SIZE + 1];
	int is_alpha[SIZE + 1];
	char guess;
	int count;
	int gm_ovr;
};

// funcs.c
//
void clearKeyboard(void);
void intro_display(void);
void strt_dub_game(void);
void strt_sing_game(void);
void load_puzzle(struct Game *n_game);
void get_puzzle(struct Game *n_game);
void load_unsolved(struct Game *n_game);
void game_display(struct Game *n_game, char image[][IMG_W]);
void proccess_inpt(struct Game *n_game, char *msg, char image[][IMG_W]);

// helpers.c
//
int in_alpha(char *character);
void mk_low(char *character);
void chng_img(char *original, char *change);
int isInRange(int *choice, int max);

// comp_puzzles.c
//
void load_comp_puzzles(char puzzles[][SIZE + 1]);