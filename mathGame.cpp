#include "keyPair.h"
#include "Functions.h"
#include <iostream>
#include <vector>
#include <string>

const int noOfValues = 9;

/*Initialize a container containing each function seeded with an initial value*/
void generateTable(std::vector<keyPair>& varTable) {		// Generate array of pointers to Functions containing our usable functions.
	int(*fnTable[noOfValues])(int) = {function1,function2,function3,function4,function5,function6,function7,function8,function9}; 
	std::string fnNames[noOfValues] = { "2x + 2", "3x - 6", "x + 15","x ^ 2","x - 9", "x^3", "x ^ 2 - 3x", "x ^ 2 + 2x + 2" , "x ^ 3 - 2(x ^ 2)"};

	for (int i = 0; i < noOfValues; i++) {
		keyPair tempkeyPair(rand() % 11, fnTable[i], fnNames[i]);
		varTable.push_back(tempkeyPair);
	}
}
/*Check to see each function returns a value successfully*/
void checkFunctions() {							
	try {
		function1(rand() & 11);
	}
	catch(std::exception& e){
		std::cout << "Standard Exception" << std::endl;
	}
	try {
		function2(rand() & 11);
	}
	catch (std::exception& e) {
		std::cout << "Standard Exception" << std::endl;
	}
	try {
		function3(rand() & 11);
	}
	catch (std::exception& e) {
		std::cout << "Standard Exception" << std::endl;
	}
	try {
		function4(rand() & 11);
	}
	catch (std::exception& e) {
		std::cout << "Standard Exception" << std::endl;
	}
	try {
		function5(rand() & 11);
	}
	catch (std::exception& e) {
		std::cout << "Standard Exception" << std::endl;
	}
	try {
		function6(rand() & 11);
	}
	catch (std::exception& e) {
		std::cout << "Standard Exception" << std::endl;
	}
	try {
		function7(rand() & 11);
	}
	catch (std::exception& e) {
		std::cout << "Standard Exception" << std::endl;
	}
	try {
		function8(rand() & 11);
	}
	catch (std::exception& e) {
		std::cout << "Standard Exception" << std::endl;
	}
	try {
		function9(rand() & 11);
	}
	catch (std::exception& e) {
		std::cout << "Standard Exception" << std::endl;
	}
}

int main() {
	int noRounds = 3;
	int score = 0;
	int userSelect;
	checkFunctions();					// Call unit test function
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

		for (int j = 0; j < 3; j++) {					// Display our three options
			std::cout.width(15);
			std::cout << (j + 1) << ") " << myTable[randInt[j]].getName() << "\n" << std::endl;
		}
		std::cout << "Select an option: ";
		
		std::cin >> userSelect;
		while (userSelect != 1 && userSelect != 2 && userSelect != 3 ) {
			std::cout << "Not a valid option, try again." << std::endl;
			std::cin.clear();															//clear the input buffer
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');			//In-case a non-integer was entered.
			std::cin >> userSelect;
		}
		/*Check if the correct value has been selected. Multiple anwsers can exist for a function*/
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