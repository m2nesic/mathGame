/*Question class object*/
#ifndef keyPair_
#define keyPair_

#include <string>


class keyPair {					// Class containing our starting int, goal, assigned function and name respectively
	int smallNum;
	int largeNum;
	int (*mysteryFn)(int);		// Pointer to a function
	std::string fnName;
public:
	keyPair();
	keyPair(int newInt, int (*mysteryFn_)(int), std::string newName);
	int getSmallNum();			// Set of query functions.
	int getLargeNum();
	std::string getName();
	int operator()(int input) { return mysteryFn(input); };		// Making the class a functor.
};
#endif

