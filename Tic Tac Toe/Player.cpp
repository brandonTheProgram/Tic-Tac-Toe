
#include "Player.h"

/************************************************************************
* Method Player: Class Player
*----------------------------------------------------------------------
* 	 This method creates the player object
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
Player::Player()
{
	this->name.clear();
	this->token = ' ';
}

/************************************************************************
* Method Player: Class Player
*----------------------------------------------------------------------
* 	 This method creates the player object with a name
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
* 		NAME (string) - the name of the player
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
Player::Player(const string& NAME)
{
	this->name  = NAME;
	this->token = ' ';
}

/************************************************************************
* Method Player: Class Player
*----------------------------------------------------------------------
* 	 This method creates the player object with a token
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
* 		TOKEN (char) - the token of the player
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
Player::Player(const char& TOKEN)
{
	this->name.clear();
	this->token = TOKEN;
}

/************************************************************************
* Method Player: Class Player
*----------------------------------------------------------------------
* 	 This method creates the player object with a name and token
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
* 		NAME (string) - the name of the player
* 		TOKEN (char)  - the token of the player
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
Player::Player(const string& NAME, const char& TOKEN)
{
	this->name  = NAME;
	this->token = TOKEN;
}

/************************************************************************
* Method ~Player: Class Player
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
Player::~Player()
{this->name.clear();}

/************************************************************************
* Method GetAndSetPlayerStats: Class Player
*----------------------------------------------------------------------
* 	 This method gets as input the name and token from the user and assigns them
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Player::GetAndSetPlayerStats()
{
	string playerName;		//IN & PROC - the name of the player

	char   playerToken;		//IN & PROC - the token of the player

	bool   invalidToken;	//PROC		- the condition for invalid token input
	bool   inputFail;		//PROC		- the condition for input failure

	do
	{
		cout << "What is your name? ";

		getline(cin, playerName);

		cout << "\nWould you like to the 'X' or 'O' Token? ";

		cin.get(playerToken);

		cin.ignore(1000, '\n');

		playerToken = std::toupper(playerToken);

		//Set the invalid conditions
		invalidToken = (playerToken != 'X' && playerToken != 'O');
		inputFail    = cin.fail();

		if(invalidToken || inputFail)
		{
			if(invalidToken)
				{cout << endl << playerToken << " is an incorrect answer\n\n";}
			else
			{
				cin.clear();
				cin.ignore(1000, '\n');
			}
		}

	}while(invalidToken || inputFail);

	this->name  = playerName;
	this->token = playerToken;
}

/************************************************************************
* Method SetPlayer: Class Player
*----------------------------------------------------------------------
* 	 This method sets the stats of the player
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
* 	 	NAME (string) - the name of the player
* 		TOKEN (char)  - the token of the player
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Player::SetPlayer(const string& NAME, const char& TOKEN)
{
	this->name  = NAME;
	this->token = TOKEN;
}
