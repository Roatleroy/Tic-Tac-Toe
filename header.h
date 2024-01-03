
#include <vector>
#include "iostream"
#include <stdlib.h> 
#include <cstring>

using namespace std;

class bob {
public:

int track = -1;
string keeps[9];

};


class TOE : bob{

public:

	void ResetTrack();

	//Creates the array for display
	void createArray();

	//Displays the menu in which player picks position
	void displayMenu();

	//Displays Array to the screen below display Menu
	void displayArray();

	//Collects users desired position for O
	void modifyArrayO();
	
	//Collects users desired position for X
	void modifyArrayX();

	//Modifys Positions in the 2d array and fills it with X or O char
	bool changePosition();
	
	//When player plays again it sets all array values back to I
	void resetArray();
	
	// Main function: Checks if player "O" has won
	bool checkifWin(string XO);

	// Helper function: Checks if a specified player has won
	bool winCheck(vector<vector<int>> winConditions, string playerSymbol);

	// if all positions are filled and there is no win it displays draw message
	bool isdraw();

	void ifStatements();

	void UNDO();


	
	// Returns the current value of XO
	string returnXO();

private:
	string array[3][3];
	string place;
	string XO;

};
