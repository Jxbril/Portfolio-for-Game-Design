#include <iostream>
#include "ttt_functions.hpp"

int main() {
	char user1 = 'x';
	char user2 = 'o';
	int pos;

	std::cout << "Please select your player\n" << "Player 1 = x\n" << "Player 2 = o\n";

	resetGrid();

	for (int i = 0; i < 4; i++) {
		std::cout << "Please select position\n";
		gridPosition();
		std::cin >> pos;
		userInput(spaceChk(pos), user1);

		if (winChk() == true) {
			break;
		}


		std::cout << "Please select position\n";
		gridPosition();
		std::cin >> pos;
		userInput(spaceChk(pos), user2);

		if (winChk() == true) {
			break;
		}

		if (i == 3) {
			std::cout << "Please select position\n";
			gridPosition();
			std::cin >> pos;
			userInput(spaceChk(pos), user1);

			if (winChk() == true) {
				break;
			}
			else {
				std::cout << "Match tie\n";
			}
		}
	}

}