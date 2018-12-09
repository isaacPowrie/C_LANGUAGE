/*
Isaac Powrie
2018-12-08
numTblMagic.c
*/

/*
Performs a magic trick based off of tables of numbers.
*/

#include <stdio.h>
#include "numTblMagic.h"

int main(void)
{
	// Initialize the store-place for table metadata
	struct TablesMeta tbls = { 0 };
	fillTblMeta(&tbls);

	// Play the game
	playGame(&tbls);

	return 0;
}
