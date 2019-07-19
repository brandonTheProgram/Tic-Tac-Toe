
#include "CPU.h"

/************************************************************************
* Method CPU: Class CPU
*----------------------------------------------------------------------
* 	 This method creates the CPU object
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
* 		ROWS (int) - the max amount of rows
* 		COLS (int) - the max amount of cols
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
CPU::CPU(const int& ROWS, const int& COLS)
{
	this->maxRows 	  = ROWS;
	this->maxCols 	  = COLS;
}

/************************************************************************
* Method ~CPU: Class CPU
*----------------------------------------------------------------------
* 	 This method deletes the object
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
CPU::~CPU(){}

/************************************************************************
* Method GetTokenCord: Class CPU
*----------------------------------------------------------------------
* 	 This method will get and set the token of the CPU on the board
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
* 		board (std::vector<std::vector<char> >) - the board
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void CPU::GetTokenCord(std::vector<std::vector<char> >& board)
{
	int row;          		  //PROC - the row in the array
	int col;          		  //PROC - the column in the array
	bool placedToken = false; //PROC - the condition for if a token has
							  //       already been placed

	//The CPU will first attempt to win the game
	WinCol(board, placedToken);

	//If no token has been placed yet, then move on
	if(placedToken == false)
	{
		WinRow(board, placedToken);

		//If no token has been placed yet, then move on
		if(placedToken == false){WinDiag(board, placedToken);}
	}

	//If the CPU can not win, then find a move to block the user
	if(placedToken == false)
	{
		BlockCol(board, placedToken);

		//If no token has been placed yet, then move on
		if(placedToken == false)
		{
			BlockRow(board, placedToken);

			//If no token has been placed yet, then move on
			if(placedToken == false){BlockDiag(board, placedToken);}
		}
	}

	//If the CPU still can't calculate a move, then randomize a move
	if(placedToken == false)
	{
		row = rand() % this->maxRows;
		col = rand() % this->maxCols;

		//If the spot is occupied, then restart the entire function
		if(!isspace(board[row][col])){GetTokenCord(board);}

		//If the spot is empty, place the CPU's token
		else{board[row][col] = GetToken();}
	}
}

/************************************************************************
* Method WinRow: Class CPU
*----------------------------------------------------------------------
* 	 This method will checks if it is possible to win across a row and does so
* 	 	if possible
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
* 		board (std::vector<std::vector<char> >) - the board
* 		placedToken(bool) - the condition for if a token has been placed
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void CPU::WinRow(std::vector<std::vector<char> >& board, bool& placedToken)
{
	int  col;                 //PROC - the column in the array
	int  row;                 //PROC - the row in the array
	int  consecCPUToken;      //PROC - the counter for consecutive CPU tokens
	int  emptySpotRow;        //PROC - the row on the board where an empty spot
	                          //       is located
	int  emptySpotCol;        //PROC - the column on the board where an empty
    						  //       spot is located

	//Initialize the counter
	consecCPUToken = 0;

	//Make the CPU win down across the row if a spot is available and a spot
	//has not been picked yet
	if(placedToken == false)
	{
		for(row = 0; row < this->maxRows; row++)
		{
			//If a token has not been placed yet, proceed with checking
			if(placedToken == false)
			{
				for(col = 0; col < this->maxCols; col++)
				{
					//If an empty spot is found, then store it
					if(isspace(board[row][col]))
					{
						emptySpotRow = row;
						emptySpotCol = col;
					}
					//If the CPU's token is in the spot, increment
					else if(board[row][col] == GetToken()){consecCPUToken++;}
				}
				//If the CPU can win, place a token
				if(consecCPUToken == (this->maxCols - 1))
				{
					row		    	  = emptySpotRow;
					col 			  = emptySpotCol;
					board[row][col]   = GetToken();
					placedToken = true;
				}
				//Reinitialize for the next check
				else{consecCPUToken = 0;}
			}
		}
	}
}

/************************************************************************
* Method WinCol: Class CPU
*----------------------------------------------------------------------
* 	 This method will checks if it is possible to win down a column and does so
* 	 	if possible
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
* 		board (std::vector<std::vector<char> >) - the board
* 		placedToken(bool) - the condition for if a token has been placed
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void CPU::WinCol(std::vector<std::vector<char> >& board, bool& placedToken)
{
	int  col;                 //PROC - the column in the array
	int  row;                 //PROC - the row in the array
	int  consecCPUToken;      //PROC - the counter for consecutive CPU tokens
	int  emptySpotRow;        //PROC - the row on the board where an empty spot
	                          //       is located
	int  emptySpotCol;        //PROC - the column on the board where an empty
    						  //       spot is located

	//Initialize the counter
	consecCPUToken = 0;

	//Make the CPU win down a column if a spot is available and a spot
	//has not been picked yet
	if(placedToken == false)
	{
		for(col = 0; col < this->maxCols; col++)
		{
			//If a token has not been placed yet, proceed with checking
			if(placedToken == false)
			{
				for(row = 0; row < this->maxRows; row++)
				{
					//If an empty spot is found, then store it
					if(isspace(board[row][col]))
					{
						emptySpotRow = row;
						emptySpotCol = col;
					}
					//If the CPU's token is in the spot, increment
					else if(board[row][col] == GetToken()){consecCPUToken++;}
				}
				//If the CPU can win, place a token
				if(consecCPUToken == (this->maxCols - 1))
				{
					row		    	  = emptySpotRow;
					col 			  = emptySpotCol;
					board[row][col]   = GetToken();
					placedToken = true;
				}
				//Reinitialize for the next check
				else{consecCPUToken = 0;}
			}
		}
	}
}

/************************************************************************
* Method WinDiag: Class CPU
*----------------------------------------------------------------------
* 	 This method will checks if it is possible to win diagonally and does so
* 	 	if possible
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
* 		board (std::vector<std::vector<char> >) - the board
* 		placedToken(bool) - the condition for if a token has been placed
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void CPU::WinDiag(std::vector<std::vector<char> >& board, bool& placedToken)
{
	int  col;                 //PROC - the column in the array
	int  row;                 //PROC - the row in the array
	int  consecCPUToken;      //PROC - the counter for consecutive CPU tokens
	int  emptySpotRow;        //PROC - the row on the board where an empty spot
	                          //       is located
	int  emptySpotCol;        //PROC - the column on the board where an empty
    						  //       spot is located

	//Initialize the counter
	consecCPUToken = 0;

	//Make the CPU win from the top left to bottom right diagonally if a
	//spot is available and a spot has not been picked yet
	if(placedToken == false)
	{
		for(row = 0; row < this->maxRows; row++)
		{
			//Initialize the start of the check
			if(row == 0){col = 0;}

			//If an empty spot is found, then store it
			if(isspace(board[row][col]))
			{
				emptySpotRow = row;
				emptySpotCol = col;
			}
			//If the CPU's token is in the spot, increment
			else if(board[row][col] == GetToken()){consecCPUToken++;}

			col++;
		}

		//If the CPU can win, place a token
		if(consecCPUToken == (this->maxCols - 1))
		{
			row		    	  = emptySpotRow;
			col 			  = emptySpotCol;
			board[row][col]   = GetToken();
			placedToken = true;
		}
		//Reset back to default for next check
		else{consecCPUToken = 0;}
	}

	//Make the CPU win from the top right to bottom left diagonally if a
	//spot is available and a spot has not been picked yet
	if(placedToken == false)
	{
		for(col = (this->maxCols - 1); col >= 0; col--)
		{
			//Initialize the start of the check
			if(col == this->maxCols - 1){row = 0;}

			//If an empty spot is found, then store it
			if(isspace(board[row][col]))
			{
				emptySpotRow = row;
				emptySpotCol = col;
			}
			//If the CPU's token is in the spot, increment
			else if(board[row][col] == GetToken()){consecCPUToken++;}

			row++;
		}

		//If the CPU can win, place a token
		if(consecCPUToken == (this->maxCols - 1))
		{
			row		    	  = emptySpotRow;
			col 			  = emptySpotCol;
			board[row][col]   = GetToken();
			placedToken = true;
		}
	}
}

/************************************************************************
* Method BlockRow: Class CPU
*----------------------------------------------------------------------
* 	 This method will checks if it is possible to block across a row and does so
* 	 	if possible
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
* 		board (std::vector<std::vector<char> >) - the board
* 		placedToken(bool) - the condition for if a token has been placed
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void CPU::BlockRow(std::vector<std::vector<char> >& board, bool& placedToken)
{
	int  col;                 //PROC - the column in the array
	int  row;                 //PROC - the row in the array
	int  consecOpponentToken; //PROC - the counter for consecutive opponent
	                          //       tokens
	int  emptySpotRow;        //PROC - the row on the board where an empty spot
	                          //       is located
	int  emptySpotCol;        //PROC - the column on the board where an empty
    						  //       spot is located

	char opponentToken;       //PROC - the oppponet's token

	//Initialize the counter
	consecOpponentToken = 0;

	//Assign the opponents token
	if(GetToken() == 'O'){opponentToken = 'X';}
	else				 {opponentToken = 'O';}

	//Block the user from winning across the rows if a spot has not been
	//picked yet
	if(placedToken == false)
	{
		for(row = 0; row < this->maxRows; row++)
		{
			//If a token has not been placed yet, proceed with checking
			if(placedToken == false)
			{
				for(col = 0; col < this->maxCols; col++)
				{
					//If an empty spot is found, then store it
					if(isspace(board[row][col]))
					{
						emptySpotRow = row;
						emptySpotCol = col;
					}
					//If the opponent's token is in the spot, increment
					else if(board[row][col] == opponentToken)
						consecOpponentToken++;
				}
				//If the user is about to win, block them
				if(consecOpponentToken == (this->maxCols - 1))
				{
					row		    	  = emptySpotRow;
					col 			  = emptySpotCol;
					board[row][col]   = GetToken();
					placedToken = true;
				}
				//Reinitialize for the next check
				else{consecOpponentToken = 0;}
			}
		}
	}
}

/************************************************************************
* Method BlockCol: Class CPU
*----------------------------------------------------------------------
* 	 This method will checks if it is possible to block down a column and does
* 	 	so if possible
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
* 		board (std::vector<std::vector<char> >) - the board
* 		placedToken(bool) - the condition for if a token has been placed
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void CPU::BlockCol(std::vector<std::vector<char> >& board, bool& placedToken)
{
	int  col;                 //PROC - the column in the array
	int  row;                 //PROC - the row in the array
	int  consecOpponentToken; //PROC - the counter for consecutive opponent
	                          //       tokens
	int  emptySpotRow;        //PROC - the row on the board where an empty spot
	                          //       is located
	int  emptySpotCol;        //PROC - the column on the board where an empty
    						  //       spot is located

	char opponentToken;       //PROC - the oppponet's token

	//Initialize the counter
	consecOpponentToken = 0;

	//Assign the opponents token
	if(GetToken() == 'O'){opponentToken = 'X';}
	else				 {opponentToken = 'O';}

	//Block the user from winning down the columns if a spot has not been
	//picked yet
	if(placedToken == false)
	{
		for(col = 0; col < this->maxCols; col++)
		{
			//If a token has not been placed yet, proceed with checking
			if(placedToken == false)
			{
				for(row = 0; row < this->maxRows; row++)
				{
					//If an empty spot is found, then store it
					if(isspace(board[row][col]))
					{
						emptySpotRow = row;
						emptySpotCol = col;
					}
					//If the opponent's token is in the spot, increment
					else if(board[row][col] == opponentToken)
						consecOpponentToken++;
				}
				//If the user is about to win, block them
				if(consecOpponentToken == (this->maxCols - 1))
				{
					row		    	  = emptySpotRow;
					col 			  = emptySpotCol;
					board[row][col]   = GetToken();
					placedToken = true;
				}
				//Reinitialize for the next check
				else{consecOpponentToken = 0;}
			}
		}
	}
}

/************************************************************************
* Method BlockDiag: Class CPU
*----------------------------------------------------------------------
* 	 This method will checks if it is possible to block diagonally and does so
* 	 	if possible
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
* 		board (std::vector<std::vector<char> >) - the board
* 		placedToken(bool) - the condition for if a token has been placed
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void CPU::BlockDiag(std::vector<std::vector<char> >& board, bool& placedToken)
{
	int  col;                 //PROC - the column in the array
	int  row;                 //PROC - the row in the array
	int  consecOpponentToken; //PROC - the counter for consecutive opponent
	                          //       tokens
	int  emptySpotRow;        //PROC - the row on the board where an empty spot
	                          //       is located
	int  emptySpotCol;        //PROC - the column on the board where an empty
    						  //       spot is located

	char opponentToken;       //PROC - the oppponet's token

	//Initialize the counter
	consecOpponentToken = 0;

	//Assign the opponents token
	if(GetToken() == 'O'){opponentToken = 'X';}
	else				 {opponentToken = 'O';}

	//Block the user from winning from the top left to bottom right diagonally
	//if a spot has not been picked yet
	if(placedToken == false)
	{
		for(row = 0; row < this->maxRows; row++)
		{
			if(row == 0){col = 0;}

			//If an empty spot is found, then store it
			if(isspace(board[row][col]))
			{
				emptySpotRow = row;
				emptySpotCol = col;
			}
			//If the opponent's token is in the spot, increment
			else if(board[row][col] == opponentToken){consecOpponentToken++;}

			col++;
		}

		//If the user is about to win, block them
		if(consecOpponentToken == (this->maxCols - 1))
		{
			row		    	  = emptySpotRow;
			col 			  = emptySpotCol;
			board[row][col]   = GetToken();
			placedToken 	  = true;
		}
		//Reset back to default for next check
		else{consecOpponentToken = 0;}
	}

	//Block the user from winning from the top right to bottom left diagonally
	//if a spot has not been picked yet
	if(placedToken == false)
	{
		for(col = (this->maxCols - 1); col >= 0; col--)
		{
			if(col == (this->maxCols - 1)){row = 0;}

			//If an empty spot is found, then store it
			if(isspace(board[row][col]))
			{
				emptySpotRow = row;
				emptySpotCol = col;
			}
			//If the opponent's token is in the spot, increment
			else if(board[row][col] == opponentToken){consecOpponentToken++;}

			row++;
		}

		//If the user is about to win, block them
		if(consecOpponentToken == (this->maxCols - 1))
		{
			row		    	  = emptySpotRow;
			col 			  = emptySpotCol;
			board[row][col]   = GetToken();
			placedToken = true;
		}
	}
}
