// CS-341 - Project 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

enum State {
	START,
	INS1,
	INS2,
	INS3,
	INTRAP
};

/**
	Prints the state of each character per the DFA.
	@param s the input string to test 
*/
void analyzeStr(string s) {
	for (int i = 0; i < s.length(); i++) {
		cout << s[i] << endl;
	}

};

int main()
{
	bool done = false;
	string str;
	char go;

	//Check to see if the user wants to enter a string to test.
	cin >> go;
	if (go == 'y') {
		cin >> str;
		cout << str << endl;
		while (!done) {
			analyzeStr(str);
			done = true;
		}
	}
	else {
		cout << "Terminated.";
	}

	return 0;
}

