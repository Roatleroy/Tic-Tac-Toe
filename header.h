
#include <vector>
#include "iostream"
#include <stdlib.h> 
#include <cstring>
#include <ctype.h>
using namespace std;

class bob {
public:

int track = -1;
string keeps[9];
int inc = 0;
int undo = 2;
};


class TOE : bob{

public:

	//Creates the array for display
	void createArray();

	//Displays the menu in which player picks position
	void displayMenu();

	//Displays Array to the screen below display Menu
	void displayArray();

	//Collects users desired position for O
	void modifyArray();

	//Modifys Positions in the 2d array and fills it with X or O char
	bool changePosition();
	
	//When player plays again it sets all array values back to I
	void resetArray();
	
	// Main function: Checks if player "O" has won
	bool checkifWin();

	// Helper function: Checks if a specified player has won
	bool winCheck(vector<vector<int>> winConditions, string playerSymbol);

	// if all positions are filled and there is no win it displays draw message
	bool isdraw();

	//Undoes the last move so player can place somewhere else
	void UNDO();

	//returns the current value of XO
	string returnXO();


	void ADDWIN();

	void displayWINS();



private:
	string array[3][3];
	string place;
	string XO;
	int winsO = 0;
	int winsX = 0;
	int draws;
};
