#include "header.h"

 void TOE::createArray() {

	for (int i = 0; i < 3; ++i) {
		for (int k = 0; k < 3; ++k) {
			array[i][k] = 'I';
		}
	}

	inc = 0;
}

 void TOE::ADDWIN() {
	 string xo = returnXO();

	 if (xo == "X") {
		 winsX++;
	 }
	 if (xo == "O") {
		 winsO++;
	 }
 }
 

 void TOE::displayWINS() {

	 cout << endl << endl << "    X WINS:    " << "O WINS:  " << endl;
	 cout << "    -------   " << " -------" << endl;
	 cout << "    " << winsX << "          " << winsO << endl;

 }

void TOE::displayMenu() {
	cout << "Menu: Type in these letters (KEEP LETTERS CAPITALIZED)" << endl
		<< " TL TC TR" << endl
		<< " CL CC CR" << endl
		<< " BL BC BR" << endl 
		<< "Or Type ( UNDO ) if you want to undo a move" << endl << endl;
}

void TOE::displayArray() {

	for (int i = 0; i < 3; ++i) {
		cout << "  ";
		for (int k = 0; k < 3; ++k) 
		{
			cout << array[i][k] << " ";
		}
		cout << endl;
	}
}

void TOE::modifyArray() {

	cout << "Type which sector you want to place:" << endl;
	cin >> place;

	for (int i = 0, n = place.length(); i < n; i++)
	{
		place[i] = toupper(place[i]);
	}
	
	if (place == "UNDO") 
	{
		if (XO == "X" && undo != 1)
		{
			system("CLS");
			
			displayMenu();
			displayArray();
			displayWINS();
			cout << "\n" << "Can't undo twice a turn!" << "\n";
			modifyArray();
			
			return;
		}
		if (XO == "O" && undo != 2)
		{
			system("CLS");

			displayMenu();
			displayArray();
			displayWINS();
			cout << "\n" << "Can't undo twice a turn!" << "\n";
			modifyArray();

			return;
		}

		UNDO();
		return;
	}

	if (inc == 2)
	{
		inc = 0;
	}

	if (inc == 0)
	{
		XO = "X";
	}

	if (inc == 1)
	{
		XO = "O";
	}

	track++;
	keeps[track] = place;

	changePosition();
		
}

void TOE::UNDO() {

	vector<vector<int>> ArrayCombos = { {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2} };

	string ChangeArray[9] = { "TL","TC","TR", "CL", "CC", "CR", "BL", "BC", "BR" };

	for (int i = 0; i < 9; ++i) {
		vector<int>	collect = ArrayCombos[i];

		if (keeps[track] == ChangeArray[i]) {
			array[collect[0]][collect[1]] = "I";
		}
	}

	if (XO == "X")
	{
		inc = 0;
		undo = 2;
	}
	if (XO == "O")
	{
		inc = 1;
		undo = 1;
	}

	system("CLS");
	displayMenu();
	displayArray();
	displayWINS();
	cout << endl;
	track--;
	modifyArray();
}

bool TOE::changePosition() {

	int increment = 0;

	vector<vector<int>> ArrayCombos = { {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2} };

	string ChangeArray[9] = { "TL","TC","TR", "CL", "CC", "CR", "BL", "BC", "BR" };

	for (int i = 0; i < 9; ++i) {

		if (place == ChangeArray[i]) {
			++increment;
		}

		if (place == ChangeArray[i]) {
			vector<int>	collect = ArrayCombos[i];

				//Checks if the position in the array already has a value
				if (array[collect[0]][collect[1]] != "I") {
					system("CLS");

					displayMenu();
					displayArray();

					cout << endl;
					cout << "That postion is already filled! " << endl << endl;

					modifyArray();
					break;
				}
	
			if (XO == "X") {
				array[collect[0]][collect[1]] = "X";
				undo = 1;
				++inc;
			}

			if (XO == "O") {
				array[collect[0]][collect[1]] = "O";
				undo = 2;
				++inc;
			}
		}
	}

	if (increment != 1) {
		system("CLS");

		displayMenu();
		displayArray();

		cout << endl;
		cout << "Not a known value! " << endl << endl;
		modifyArray();
	}

	return true;
}

// Main function: Checks if player "O" has won
bool TOE::checkifWin() {
	vector<vector<int>> winConditions = {
		{0, 0, 0, 1, 0, 2}, // Top row
		{1, 0, 1, 1, 1, 2}, // Middle row
		{2, 0, 2, 1, 2, 2}, // Bottom row
		{0, 0, 1, 1, 2, 2}, // Top left to bottom right
		{2, 0, 1, 1, 0, 2}, // Bottom left to top right
		{0, 0, 1, 0, 2, 0}, // Left column
		{0, 2, 1, 2, 2, 2}, // Right column
		{0, 1, 1, 1, 2, 1}  // Center column
	};

	if (XO == "X") {
		return winCheck(winConditions, "X");
	}
	if (XO == "O")
		return winCheck(winConditions, "O");
}

// Helper function: Checks if a specified player has won
bool TOE::winCheck(vector<vector<int>> winConditions, string playerSymbol) {

	for (auto& condition : winConditions) {

		if (array[condition[0]][condition[1]] == playerSymbol
			&& array[condition[2]][condition[3]] == playerSymbol
			&& array[condition[4]][condition[5]] == playerSymbol) {
			cout << "\n" << playerSymbol << " WINS\n\n";
			return true;
		}
	}
	return false;
}

bool TOE::isdraw() {
	int Plus = 0;

	for (int i = 0; i < 3; ++i) {
		for (int k = 0; k < 3; ++k) {
			if ((array[i][k] == "I"))
			{
				++Plus;
			}
		}

	}

	if (Plus == 0) {
		cout << endl << "THE GAME IS A DRAW!" << endl;
		return true;
		++draws;
	}
	else
		return false;
}

void TOE::resetArray() {
	for (int i = 0; i < 3; ++i) {
		for (int k = 0; k < 3; ++k) {
			array[i][k] = 'I';
		}
	}
	track = -1;
	inc = 0;
}

string TOE::returnXO() {
	return XO;
}