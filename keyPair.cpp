#include "keyPair.h"
#include<string>

keyPair::keyPair(){
	smallNum = 0;
	largeNum = 0;
	mysteryFn = nullptr;
	fnName = "";
}

keyPair::keyPair(int newInt, int(*mysteryFn_)(int&), std::string newName){
	smallNum = newInt;
	largeNum = mysteryFn_(newInt);
	mysteryFn = mysteryFn_;
	fnName = newName;
}

int keyPair::getSmallNum(){
	return smallNum;
}

int keyPair::getLargeNum(){
	return largeNum;
}

std::string keyPair::getName(){
	return fnName;
}
