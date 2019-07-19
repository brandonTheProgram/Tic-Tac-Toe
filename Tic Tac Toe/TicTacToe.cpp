
#include "TicTacToe.h"

/************************************************************************
* Method TicTacToe: Class TicTacToe
*----------------------------------------------------------------------
* 	 This method creates the Tic Tac Toe game object
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
TicTacToe::TicTacToe()
{
	InitializeBoard();
	playerOne   = new Player;
	cpu 	    = new CPU(MAX_ROWS, MAX_COLUMNS);
	winner 		= ' ';
	foundWinner = false;
}

/************************************************************************
* Method ~TicTacToe: Class TicTacToe
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
TicTacToe::~TicTacToe()
{
	delete playerOne;
	delete cpu;
}

/************************************************************************
* Method Play: Class TicTacToe
*----------------------------------------------------------------------
* 	 This method controls the entire game
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void TicTacToe::Play()
{
	int turnCounter = 1;	//PROC - the turn counter

	//INPUT - Get the name and token from the user
	playerOne->GetAndSetPlayerStats();

	//PROCESSING - Set the opposite stats for the CPU
	if(playerOne->GetToken() == 'X'){cpu->SetPlayer("CPU", 'O');}
	else						    {cpu->SetPlayer("CPU", 'X');}

	//PROCESSING - the main loop, will continue until a winner has been found
	while(winner == ' ')
	{

		//OUTPUT - Display the board
		DisplayBoard();

		//INPUT & PROCESSING - Get where the user wants to place the token
		//					   and do so accordingly
		GetAndSetToken();

		//PROCESSING - If a winner can be determined, than check otherwise
		//			   increment the turn counter
		if(turnCounter != 5){++turnCounter;}
		else{CheckWin();}

		//PROCESSING - If the user has not won the game, then have the CPU
		//			   make thier turn
		if(foundWinner == false){cpu->GetTokenCord(board);}

		//PROCESSING - If a winner can be determined, than check otherwise
		//			   increment the turn counter
		if(turnCounter != 5){++turnCounter;}
		else			    {CheckWin();}
	}

	//OUTPUT - Display who the winner is
	DisplayWinner();
}

/************************************************************************
* Method InitializeBoard: Class TicTacToe
*----------------------------------------------------------------------
* 	 This  method initializes the board
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void TicTacToe::InitializeBoard()
{
	for(int i = 0; i < MAX_ROWS; i++)
	{
		std::vector<char> temp;

		for(int j = 0; j < MAX_COLUMNS; j++){temp.push_back(' ');}

		board.push_back(temp);
	}
}

/************************************************************************
* Method GetAndSetToken: Class TicTacToe
*----------------------------------------------------------------------
* 	 This method will ask the user where to place the token and places
* 	 	it accordingly
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void TicTacToe::GetAndSetToken()
{
	int row;          //PROC - the row in the array
	int col;          //PROC - the column in the array

	bool invalid;     //PROC - the condition for invalid inputs
	bool invalidRow;  //PROC - the condition for invalid rows
	bool invalidCol;  //PROC - the condition for invalid columns
	bool inputFail;   //PROC - the condition for failed input

	do
	{
		cout << "Enter the row and column(ex: 1 1): ";
		cin  >> row >> col;

		//Initialize the invalid conditions
		invalid    = ((col < 1 || col > MAX_COLUMNS) &&
					  (row < 1 || row > MAX_ROWS   ));

		invalidRow =  (row < 1 || row > MAX_ROWS);

		invalidCol =  (col < 1 || col > MAX_COLUMNS);

		inputFail  = cin.fail();

		//If the input is invalid, then state what was invalid for the user
		if(invalidRow)
		{
			cout << "\nERROR! Row is incorrect, please input a "
				 << "number between 1 - " << MAX_ROWS << ".\n\n";
		}
		else if(invalidCol)
		{
			cout << "\nERROR! Column is incorrect, please input a "
				 << "number between 1 - " << MAX_COLUMNS << ".\n\n";
		}
		else if(invalid)
		{
			cout << "\nERROR! Row and Column are incorrect, please "
				 << "input a number between 1 - "
				 << MAX_ROWS << ".\n\n";
		}
		else if(inputFail)
		{
			cout << "\nERROR! please input a number between 1 - " << MAX_ROWS
				 << ".\n\n";
		}
	}while(invalidCol || invalidRow || invalid || inputFail);


	//If the spot is occupied, then restart the entire function
	if(!isspace(board[row - 1][col - 1]))
	{
		cout << "\nERROR! This spot has already been taken\n";
		GetAndSetToken();
	}
	//If the spot is empty, place the token in that spot
	else{board[row - 1][col - 1] = playerOne->GetToken();}
}

/************************************************************************
* Method CheckWin: Class TicTacToe
*----------------------------------------------------------------------
* 	 This method will check if a winner has been found
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void TicTacToe::CheckWin()
{
	int row;          //PROC - the row on the board
	int col;          //PROC - the column on the board
 	int tieCounter;   //PROC - the counter to determine a tie


	//Initialize the default values
	tieCounter  = 0;

	//PROCESSING - Check to see if there is a winner across the rows
	CheckRows();

	//PROCESSING - Check to see if there is a winner down the columns

	if(!foundWinner)
	{
		CheckCols();

		//PROCESSING - Check to see if there is a winner diagonally
		if(!foundWinner){CheckDiag();}
	}

	//Check to see if the board is full and there is a tie
	if(foundWinner == false)
	{
		for(row = 0; row < MAX_ROWS; row++)
		{
			for(col = 0; col < MAX_COLUMNS; col++)
				if(!isspace(board[row][col])){tieCounter++;}
		}

		//If the entire board if full with no winner, then it is a tie
		if(tieCounter == (MAX_ROWS * MAX_COLUMNS)){winner = 'T';}
	}
}

/************************************************************************
* Method CheckCols: Class TicTacToe
*----------------------------------------------------------------------
* 	 This method will check if a winner has been found down the columns
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void TicTacToe::CheckCols()
{
	int  col;                 //PROC - the column in the array
	int  row;                 //PROC - the row in the array
	int  consecX;             //PROC - the counter for X tokens
	int  consecO;             //PROC - the counter for O tokens

	//Initialize the default values
	consecX     = 0;
	consecO     = 0;

	//Check down the columns if no winner has been found yet
	if(foundWinner == false)
	{
		for(col = 0; col < MAX_COLUMNS; col++)
		{
			for(row = 0; row < MAX_ROWS; row++)
			{
				if     (board[row][col] == 'X'){consecX++;}
				else if(board[row][col] == 'O'){consecO++;}
			}
			//Check if there is a winner
			if(consecX == MAX_ROWS)
			{
				winner 		= 'X';
				foundWinner = true;
			}
			else if(consecO == MAX_ROWS)
			{
				winner 		= 'O';
				foundWinner = true;
			}
			//If there is not winner, then reset back to default for the next
			//check
			else
			{
				consecX = 0;
				consecO = 0;
			}
		}
	}
}

/************************************************************************
* Method CheckRows: Class TicTacToe
*----------------------------------------------------------------------
* 	 This method will check if a winner has been found across the rows
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void TicTacToe::CheckRows()
{
	int  col;                 //PROC - the column in the array
	int  row;                 //PROC - the row in the array
	int  consecX;             //PROC - the counter for X tokens
	int  consecO;             //PROC - the counter for O tokens

	//Initialize the default values
	consecX     = 0;
	consecO     = 0;

	//Check across the rows if no winner has been found yet
	if(foundWinner == false)
	{
		for(row = 0; row < MAX_ROWS; row++)
		{
			for(col = 0; col < MAX_COLUMNS; col++)
			{
				if     (board[row][col] == 'X'){consecX++;}
				else if(board[row][col] == 'O'){consecO++;}
			}
			//Check if there is a winner
			if(consecX == MAX_ROWS)
			{
				winner = 'X';
				foundWinner = true;
			}
			else if(consecO == MAX_ROWS)
			{
				winner = 'O';
				foundWinner = true;
			}
			//If there is not winner, then reset back to default for the next
			//check
			else
			{
				consecX = 0;
				consecO = 0;
			}
		}
	}
}

/************************************************************************
* Method CheckDiag: Class TicTacToe
*----------------------------------------------------------------------
* 	 This method will check if a winner has been found diagonally
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void TicTacToe::CheckDiag()
{
	int  col;                 //PROC - the column in the array
	int  row;                 //PROC - the row in the array
	int consecX;              //PROC - the counter for X tokens
	int consecO;              //PROC - the counter for O tokens

	//Initialize the default values
	consecX     = 0;
	consecO     = 0;

	//Check from the top left to bottom right diagonally if no winner has
	//been found yet
	if(foundWinner == false)
	{
		for(row = 0; row < MAX_ROWS; row++)
		{
			if(row == 0){col = 0;}

			if     (board[row][col] == 'X'){consecX++;}
			else if(board[row][col] == 'O'){consecO++;}

			col++;
		}
		//Check if there is a winner
		if(consecX == MAX_ROWS)
		{
			winner = 'X';
			foundWinner = true;
		}
		else if(consecO == MAX_ROWS)
		{
			winner = 'O';
			foundWinner = true;
		}
		//If there is not winner, then reset back to default for the next
		//check
		else
		{
			consecX = 0;
			consecO = 0;
		}
	}

	//Check from the top right to bottom left diagonally if no winner has
	//been found yet
	if(foundWinner == false)
	{
		for(col = (MAX_COLUMNS - 1); col >= 0; col--)
		{
			if(col == MAX_COLUMNS - 1){row = 0;}

			if     (board[row][col] == 'X'){consecX++;}
			else if(board[row][col] == 'O'){consecO++;}

			row++;
		}

		//Check if there is a winner
		if(consecX == MAX_ROWS)
		{
			winner = 'X';
			foundWinner = true;
		}
		else if(consecO == MAX_ROWS)
		{
			winner = 'O';
			foundWinner = true;
		}
		//If there is not winner, then reset back to default for the next
		//check
		else
		{
			consecX = 0;
			consecO = 0;
		}
	}
}

/************************************************************************
* Method DisplayWinner: Class TicTacToe
*----------------------------------------------------------------------
* 	 This method display who won the game
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void TicTacToe::DisplayWinner() const
{

	//OUTPUT - Display the finished gameboard
	DisplayBoard();

	switch(winner)
	{
	case 'O':	cout << "\n******************************\n"
					 << "The winner is  O!\n"
					 << "******************************\n";
				break;
	case 'T':   cout << "\n*********************************************\n"
			 	 	 << "Congratulations on ending in a tie!\n"
					 << "*********************************************\n";
				break;
	case 'X':   cout << "\n******************************\n"
		     	 	 << "The winner is  X!\n"
					 << "******************************\n";
	}

	system("pause");
}

/************************************************************************
* Method DisplayBoard: Class TicTacToe
*----------------------------------------------------------------------
* 	 This method display the game board
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void TicTacToe::DisplayBoard() const
{
	using std::setw;

	int col;  //PROC - the column in the 2D array
	int row;  //PROC - the row in the 2D array

	//Clear the screen before displaying the board
	system("cls");

	//Place the number headers above the columns
	cout << setw(10) << "1" << setw(8) << "2" << setw(9) << "3\n";

	//Place the numbers and lines for the board
	for(row = 0; row < MAX_ROWS; row++)
	{
		cout << setw(7)<< "["<< row + 1 << "][1] | "<< "["<< row + 1;
		cout <<"][2] | " <<"["<< row + 1 << "][3]" << endl;
		cout << setw(14)<< "|"<< setw(9) << "|"  << endl;

		for(col = 0; col < MAX_COLUMNS; col++)
		{
			switch(col)
			{
				case 0:   cout  << row + 1 << setw(9) << board[row][col];
						  cout  << setw(4) << "|";
						  break;

				case 1:   cout << setw(4) << board[row][col];
				          cout << setw(5) << "|";
				          break;

				case 2:   cout << setw(4) << board[row][col] << endl;
				          break;

			    default:  cout << "ERROR!\n\n";
			}
		}

		cout << setw(14)<< "|"<< setw(10) << "|\n";

		//If the row is not 2, then ouput a row of -
		if(row != 2)
		{
			cout << setw(32) << "--------------------------\n";
		}
	}
	cout << endl << endl;
}
