
#include "header.h"

int main() {
	TOE TICKTACK;
	bool win = true;
	bool din = true;
	char kin;
	string stringstring;


	TICKTACK.createArray();


	while (win) {

		while (din) {

			TICKTACK.displayMenu();

			TICKTACK.displayArray();

			cout << endl;

			TICKTACK.modifyArrayX();

			if (TICKTACK.checkifWin(TICKTACK.returnXO())) {
				system("CLS");

				TICKTACK.displayMenu();
				TICKTACK.displayArray();

				cout << endl << TICKTACK.returnXO() << " wins!" << endl;

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

				system("CLS");

				break;
			}

			system("CLS");

			TICKTACK.displayMenu();

			TICKTACK.displayArray();

			cout << endl;

			TICKTACK.modifyArrayO();

			if (TICKTACK.checkifWin(TICKTACK.returnXO())) {
				system("CLS");

				TICKTACK.displayMenu();
				TICKTACK.displayArray();

				cout << endl << " You win " << TICKTACK.returnXO() << endl;

				cin.ignore();
				cin.ignore();

				din = false;
			}

			if (TICKTACK.isdraw()) {
				din = false;

				cin.ignore();
				cin.ignore();
			}

			system("CLS");
		}

		cout << " Would you like to play again? (Types Y for yes and N for no): " << endl;
		cin >> kin;

		if (kin == 'Y') {
			win = true;
			TICKTACK.resetArray();
			din = true;
		}
		else
			win = false;

		TICKTACK.ResetTrack();

		system("CLS");

	}

}

