
#ifndef TICTACTOE_H_
#define TICTACTOE_H_

#include "CPU.h"

/**************************************************************************
 * CONSTANTS
 * ------------------------------------------------------------------------
 * USED FOR MAX/MIN VALUES
 * ------------------------------------------------------------------------
 * MAX_ROWS    : the maximum amount of rows
 * MAX_COLUMNS : the maximum amount of cols
 *************************************************************************/
const int MAX_ROWS 		= 3;
const int MAX_COLUMNS  	= 3;

/************************************************************************
* TicTacToe Class
* 	This class represents a Tic Tac Toe game
* 	It manages 4 attribute: playerOne, cpu, winner, and foundWinner
*************************************************************************/
class TicTacToe //Base Class
{
	public:
		/******************************
		 ** CONSTRUCTOR & DESTRUCTOR **
		 ******************************/

		/****************************************************************
		 * TicTacToe ();
		 *
		 *   Constructor; this method initializes a game
		 *--------------------------------------------------------------
		 *   Parameters: none
		 *--------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		TicTacToe();

		/****************************************************************
		 * ~TicTacToe ();
		 *
		 *   Deconstructor; does nothing special
		 *--------------------------------------------------------------
		 *   Parameters: none
		 *--------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		virtual ~TicTacToe();

		/******************
		 **** MUTATORS ****
		 ******************/

		/****************************************************************
		 * 	void Play();
		 *
		 *   Mutator; this method controls the entire game
		 *--------------------------------------------------------------
		 *   Parameters: none
		 *--------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		void Play();

		/****************************************************************
		 * 	void InitializeBoard();
		 *
		 *   Mutator; this method initializes the board
		 *--------------------------------------------------------------
		 *   Parameters: none
		 *--------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		void InitializeBoard();

		/****************************************************************
		 * 	void GetAndSetToken();
		 *
		 *   Mutator; this method will ask the user where to place the token
		 *   			and places it accordingly
		 *--------------------------------------------------------------
		 *   Parameters: none
		 *--------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		void GetAndSetToken();

		/****************************************************************
		 * 	void CheckWin();
		 *
		 *   Mutator; this method checks to see if a winner has been found
		 *--------------------------------------------------------------
		 *   Parameters: none
		 *--------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		void CheckWin();

		/****************************************************************
		 * 	void CheckRows();
		 *
		 *   Mutator; this method checks the rows for a winner
		 *--------------------------------------------------------------
		 *   Parameters: none
		 *--------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		void CheckRows();

		/****************************************************************
		 * 	void CheckCols();
		 *
		 *   Mutator; this method checks the columns for a winner
		 *--------------------------------------------------------------
		 *   Parameters: none
		 *--------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		void CheckCols();

		/****************************************************************
		 * 	void CheckDiag();
		 *
		 *   Mutator; this method checks diagonally for a winner
		 *--------------------------------------------------------------
		 *   Parameters: none
		 *--------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		void CheckDiag();

		/*******************
		 **** ACCESSORS ****
		 *******************/

		/****************************************************************
		 * void DisplayWinner() const;
		 *
		 *   Accessor; This method display who won the game
		 *-----------------------------------------------------------------
		 *   Parameters: none
		 *-----------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		void DisplayWinner() const;

		/****************************************************************
		 * void DisplayBoard() const;
		 *
		 *   Accessor; This method display the game board
		 *-----------------------------------------------------------------
		 *   Parameters: none
		 *-----------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		void DisplayBoard() const;

	private:
		std::vector<std::vector<char> >  board;		 //The game board
		Player 						   	*playerOne;	 //The user
		CPU    							*cpu;		 //The cpu
		char   							 winner;	 //The winner of the game
		bool   							 foundWinner;//The condition for if a
													 //winner has been found
};

#endif /* TICTACTOE_H_ */
