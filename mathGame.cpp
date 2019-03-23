#include "keyPair.h"
#include "Functions.h"
#include <iostream>
#include <vector>
#include <string>

const int noOfValues = 9;
/*
Potentially add Dynamic memory, add unit tests.|
*/
void generateTable(std::vector<keyPair>& varTable) {		// Generate array of pointers to Functions containing our usable functions.
	int(*fnTable[noOfValues])(int) = {function1,function2,function3,function4,function5,function6,function7,function8,function9}; 
	std::string fnNames[noOfValues] = { "2x + 2", "3x - 6", "x + 15","x ^ 2","x - 9", "x^3", "x ^ 2 - 3x", "x ^ 2 + 2x + 2" , "x ^ 3 - 2(x ^ 2)"};


	for (int i = 0; i < noOfValues; i++) {
		keyPair tempkeyPair(rand() % 11, fnTable[i], fnNames[i]);
		varTable.push_back(tempkeyPair);
	}
}

int main() {
	int noRounds = 3;
	int score = 0;
	int userSelect;
	std::vector<keyPair> myTable;
	generateTable(myTable);	
	
	while (noRounds != 0) {
		int randInt[3] = { rand() % myTable.size(), rand() % myTable.size(), rand() % myTable.size() }; // Select 3 random, unique functions to be used
		while (randInt[1] == randInt[0]) {
			randInt[1] = rand() % myTable.size();
		}
		while (randInt[2] == randInt[0] || randInt[2] == randInt[1]) {
			randInt[2] = rand() % myTable.size();
		}

		std::cout << "Our target Value >>>>>> " << myTable[randInt[0]].getLargeNum() << std::endl;
		std::cout << "What can we do to our starting value >>> " << myTable[randInt[0]].getSmallNum() << " <<< to reach our target.\n" << std::endl;

		for (int j = 0; j < 3; j++) {
			std::cout.width(15);
			std::cout << (j + 1) << ") " << myTable[randInt[j]].getName() << "\n" << std::endl;
		}
		std::cout << "Select an option: ";
		
		std::cin >> userSelect;
		while (userSelect != 1 && userSelect != 2 && userSelect != 3 ) {
			std::cout << "Not a valid option, try again." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> userSelect;
		}
		
		switch (userSelect) {
		case 1: {
			if (myTable[randInt[0]](myTable[randInt[0]].getSmallNum()) == myTable[randInt[0]].getLargeNum()) {
				std::cout << "Good job, ";
				score++;
			}
			else {
				std::cout << "Not quite, ";
			}}break;
		case 2: {
			if (myTable[randInt[1]](myTable[randInt[1]].getSmallNum()) == myTable[randInt[0]].getLargeNum()) {
				std::cout << "Good job, ";
				score++;
			}
			else {
				std::cout << "Not quite, ";
			}}break;
		case 3: {
			if (myTable[randInt[2]](myTable[randInt[2]].getSmallNum()) == myTable[randInt[0]].getLargeNum()) {
				std::cout << "Good job, ";
				score++;
			}
			else {
				std::cout << "Not quite, ";
			}}break;
		}
		std::cin.get();
		std::cout << "press enter to continue" << std::endl;
		std::cin.get();
		system("CLS");
		noRounds--;

		myTable.erase(myTable.begin() + randInt[0]);			// Ensuring each set of questions will be different.
		if (randInt[0] < randInt[1]) {
			randInt[1]--;
		}
		if (randInt[0] < randInt[2]) {
			randInt[2]--;
		}
		myTable.erase(myTable.begin() + randInt[1]);
		if (randInt[1] < randInt[2]) {
			randInt[2]--;
		}
	}
	std::cout << "You got " << score << " question(s) right" << std::endl;
	std::cin.get();
	return 0;
}