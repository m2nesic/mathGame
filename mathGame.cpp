#include "keyPair.h"
#include "Functions.h"
#include <iostream>
#include <vector>
#include <string>

const int noOfValues = 8;



void generateTable() {		// Generate array of pointers to Functions containing our usable functions.
	int(*fnTable[noOfValues])(int) = {function1,function2,function3,function4,function5,function6,function7,function8}; 
	std::string fnNames[8] = { "2x + 2", "3x - 6", "x + 15","x ^ 2","x - 9", "x^3", " x ^ 2 - 3x", "x ^ 2 + 2x + 2" };
	std::vector<keyPair> myTable;

	for (int i = 0; i < 8; i++) {
		keyPair tempkeyPair(rand() % 10, fnTable[i], fnNames[i]);
		myTable.push_back(tempkeyPair);
	}
}

int main() {
	generateTable();
	std::cin.get();
	return 0;
}