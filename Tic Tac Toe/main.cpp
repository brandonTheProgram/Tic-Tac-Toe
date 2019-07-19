
#include "TicTacToe.h"

/******************************************************************************
 * TIC TAC TOE
 *-----------------------------------------------------------------------------
 * This program will emulates a game of Tic Tac Toe
 *****************************************************************************/
int main()
{
	srand(time(NULL));	//PROC 			  - The seed for the random generator

	TicTacToe game;		//IN, PROC, & OUT - The Tic Tac Toe game

	//PROCESSING - Start the game
	game.Play();

	return 0;
}
