
#include "header.h"

int main() {
	TOE TICKTACK;
	bool win = true;
	bool din = true;
	char kin;

	TICKTACK.createArray();

	while (win) {

		while (din) {
			system("CLS");

			TICKTACK.displayMenu();

			TICKTACK.displayArray();

			//TICKTACK.displayWINS();

			cout << endl;

			TICKTACK.modifyArray();

			if (TICKTACK.checkifWin()) {
				system("CLS");

				TICKTACK.displayMenu();
				TICKTACK.displayArray();

				cout << endl << TICKTACK.returnXO() << " wins!" << endl;

				TICKTACK.ADDWIN();

				cin.ignore();
				cin.ignore();

				din = false;

				system("CLS");

				break;
			}

			if (TICKTACK.isdraw()) {
				din = false;

				cin.ignore();
				cin.ignore();

				break;
			}
			
		}
			
			system("CLS");

			TICKTACK.displayMenu();

			TICKTACK.displayArray();

			//TICKTACK.displayWINS();

			cout << endl;

		cout << " Would you like to play again? (Types Y for yes and N for no): " << endl;
		cin >> kin;

		if (kin == 'Y') {
			win = true;
			TICKTACK.resetArray();
			din = true;
		}
		else
			win = false;

		system("CLS");

	}

}

