
#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include <iostream>
#include <iomanip>

using std::string;
using std::cout;
using std::cin;
using std::endl;

/************************************************************************
* Player Class
* 	This class represents a player in the game
* 	It manages 2 attribute: name and token
*************************************************************************/
class Player	//Base Class
{
	public:

		/******************************
		 ** CONSTRUCTOR & DESTRUCTOR **
		 ******************************/

		/****************************************************************
		 * Player ();
		 *
		 *   Constructor; this method initializes a player
		 *--------------------------------------------------------------
		 *   Parameters: none
		 *--------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		Player(); //default constructor

		/****************************************************************
		 * Player(const string& NAME);
		 *
		 *   Constructor; this method initializes a player with a name
		 *--------------------------------------------------------------
		 *   Parameters: NAME (string) - the name of the user
		 *--------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		Player(const string& NAME);

		/****************************************************************
		 * Player(const char& TOKEN);
		 *
		 *   Constructor; this method initializes a player with a token
		 *--------------------------------------------------------------
		 *   Parameters: TOKEN (char) - the token for the user
		 *--------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		Player(const char& TOKEN);

		/****************************************************************
		 * Player(const string& NAME, const char& TOKEN);
		 *
		 *   Constructor; this method initializes a player with a name and token
		 *--------------------------------------------------------------
		 *   Parameters: NAME (string) - the name of the user
		 *   			 TOKEN(char)   - the token for the user
		 *--------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		Player(const string& NAME, const char& TOKEN);

		/****************************************************************
		 * ~Player ();
		 *
		 *   Deconstructor; does nothing special
		 *--------------------------------------------------------------
		 *   Parameters: none
		 *--------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		virtual ~Player();

		/******************
		 **** MUTATORS ****
		 ******************/

		/****************************************************************
		 * 	void GetAndSetPlayerStats();
		 *
		 *   Mutator; this method will get the stats for a player and set them
		 *--------------------------------------------------------------
		 *   Parameters: none
		 *--------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		void GetAndSetPlayerStats();

		/****************************************************************
		 * 	void SetPlayer(const string& NAME, const char& TOKEN);
		 *
		 *   Mutator; this method will set the stats for a player
		 *--------------------------------------------------------------
		 *   Parameters: NAME (string) - the name of the user
		 *   			 TOKEN(char)   - the token for the user
		 *--------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		void SetPlayer(const string& NAME, const char& TOKEN);

		/****************************************************************
		 * 	void SetName(const string& NAME);
		 *
		 *   Mutator; this method will set the name for a player
		 *--------------------------------------------------------------
		 *   Parameters: NAME (string) - the name of the user
		 *--------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		void SetName(const string& NAME) {this->name = NAME;}

		/****************************************************************
		 * 	void SetToken(const char& TOKEN);
		 *
		 *   Mutator; this method will set the token for a player
		 *--------------------------------------------------------------
		 *   Parameters: TOKEN (char) - the token of the user
		 *--------------------------------------------------------------
		 *   Return: none
		 ***************************************************************/
		void SetToken(const char& TOKEN) {this->name = TOKEN;}

		/*******************
		 **** ACCESSORS ****
		 *******************/

		/****************************************************************
		 * string GetName() const;
		 *
		 *   Accessor; This method returns the name of the player
		 *-----------------------------------------------------------------
		 *   Parameters:
		 *-----------------------------------------------------------------
		 *   Return: the name of the player
		 ***************************************************************/
		string GetName() const{return name;}

		/****************************************************************
		 * char GetToken() const;
		 *
		 *   Accessor; This method returns the token of the player
		 *-----------------------------------------------------------------
		 *   Parameters: none
		 *-----------------------------------------------------------------
		 *   Return: the token of the player
		 ***************************************************************/
		char GetToken() const{return token;}

	private:
		string 	name;		//The name of the player
		char 	token;		//The token of the player
};

#endif /* PLAYER_H_ */
