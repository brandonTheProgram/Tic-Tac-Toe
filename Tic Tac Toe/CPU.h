
#ifndef CPU_H_
#define CPU_H_

#include <vector>
#include <cstdlib>        /** srand, rand               **/
#include <time.h>         /** time                      **/

#include "Player.h"

/************************************************************************
* CPU Class
* 	This class represents a CPU in the game
* 	It manages 2 attribute: maxRows and maxCols
*************************************************************************/
class CPU: public Player //Child Class
{
	public:
		/******************************
		 ** CONSTRUCTOR & DESTRUCTOR **
		 ******************************/

		/****************************************************************
		 * CPU ();
		 *
		 *   Constructor; this method initializes a CPU
		 *--------------------------------------------------------------
		 *   Parameters: ROWS (int) - the max amount of rows
		 *   			 COLS (int) - the max amount of columns
		 *--------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		CPU(const int& ROWS, const int& COLS);

		/****************************************************************
		 * ~CPU ();
		 *
		 *   Deconstructor; does nothing special
		 *--------------------------------------------------------------
		 *   Parameters: none
		 *--------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		virtual ~CPU();

		/******************
		 **** MUTATORS ****
		 ******************/

		/****************************************************************
		 * 	void GetTokenCord(std::vector<std::vector<char> >& board);
		 *
		 *   Mutator; this method will get and set the token of the CPU on the
		 *   		   board
		 *--------------------------------------------------------------
		 *   Parameters: board (std::vector<std::vector<char> >) - the board
		 *--------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		void GetTokenCord(std::vector<std::vector<char> >& board);

		/****************************************************************
		 * 	void WinRow(std::vector<std::vector<char> >& board,
		 *								   		   bool& placedToken);
		 *
		 *   Mutator; this method will checks if it is possible to win across a
		 *   		  row and does so if possible
		 *--------------------------------------------------------------
		 *   Parameters: board (std::vector<std::vector<char> >) - the board
		 *   			 placedToken(bool) - the condition for if a token has
		 *   			 					 been placed
		 *--------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		void WinRow(std::vector<std::vector<char> >& board,
											   bool& placedToken);

		/****************************************************************
		 * 	void WinCol(std::vector<std::vector<char> >& board,
		 *									       bool& placedToken);
		 *
		 *   Mutator; this method will checks if it is possible to win down a
		 *   		   column and does so if possible
		 *--------------------------------------------------------------
		 *   Parameters: board (std::vector<std::vector<char> >) - the board
		 *   			 placedToken(bool) - the condition for if a token has
		 *   			 					 been placed
		 *--------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		void WinCol(std::vector<std::vector<char> >& board,
											   bool& placedToken);

		/****************************************************************
		 * 	void WinDiag(std::vector<std::vector<char> >& board,
		 *									        bool& placedToken);
		 *
		 *   Mutator; this method will checks if it is possible to win across
		 *   		  diagonally and does so if possible
		 *--------------------------------------------------------------
		 *   Parameters: board (std::vector<std::vector<char> >) - the board
		 *   			 placedToken(bool) - the condition for if a token has
		 *   			 					 been placed
		 *--------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		void WinDiag(std::vector<std::vector<char> >& board,
												bool& placedToken);

		/****************************************************************
		 * 	void BlockRow(std::vector<std::vector<char> >& board,
		 *									         bool& placedToken);
		 *
		 *   Mutator; this method will checks if it is possible to block across
		 *   		  a row and does so if possible
		 *--------------------------------------------------------------
		 *   Parameters: board (std::vector<std::vector<char> >) - the board
		 *   			 placedToken(bool) - the condition for if a token has
		 *   			 					 been placed
		 *--------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		void BlockRow(std::vector<std::vector<char> >& board,
												 bool& placedToken);

		/****************************************************************
		 * 	void BlockCol(std::vector<std::vector<char> >& board,
		 *									         bool& placedToken);
		 *
		 *   Mutator; this method will checks if it is possible to block down a
		 *   		   column and does so if possible
		 *--------------------------------------------------------------
		 *   Parameters: board (std::vector<std::vector<char> >) - the board
		 *   			 placedToken(bool) - the condition for if a token has
		 *   			 					 been placed
		 *--------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		void BlockCol(std::vector<std::vector<char> >& board,
												 bool& placedToken);

		/****************************************************************
		 * 	void BlockDiag(std::vector<std::vector<char> >& board,
		 *									          bool& placedToken);
		 *
		 *   Mutator; this method will checks if it is possible to block across
		 *   		   diagonally and does so if possible
		 *--------------------------------------------------------------
		 *   Parameters: board (std::vector<std::vector<char> >) - the board
		 *   			 placedToken(bool) - the condition for if a token has
		 *   			 					 been placed
		 *--------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		void BlockDiag(std::vector<std::vector<char> >& board,
												  bool& placedToken);

	private:
		int  maxRows;		//The max amount of rows present
		int  maxCols;		//The max amount of columns present
};

#endif /* CPU_H_ */
