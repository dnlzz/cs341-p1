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
	INQ1,
	INQ2,
	INQ3,
	INQ4,
	INQ5,
	INQ6,
	INQ7,
	INQ8,
	INQ9,
	INQ10,
	INQ11,
	INTRAP
};

/**
	Prints the state of each character per the DFA.
	@param s the input string to test 
*/
void analyzeStr(string s) {

	State state = START;
	string lex;		//possibly do not need this
	lex.clear();	//or this

	for (int i = 0; i < s.length(); i++) {
		//cout << s[i] << endl;
		switch (state)
		{
		case START:
			cout << "q" << state << endl;
			if (s[i] == 'w') {
				state = INQ1;
			}
			break;
		case INQ1:
			cout << "q" << state << endl;
			if (s[i] == 'w') {
				state = INQ2;
			}
			break;
		case INQ2:
			cout << "q" << state << endl;
			if (s[i] == 'w') {
				state = INQ3;
			}
			break;
		case INQ3:
			cout << "q" << state << endl;
			if (s[i] == '.') {
				state = INQ4;
			}
			break;
		case INQ4:
			cout << "www." << endl;
			break;
		case INQ5:
			break;
		case INQ6:
			break;
		case INQ7:
			break;
		case INQ8:
			break;
		case INQ9:
			break;
		case INQ10:
			break;
		case INQ11:
			break;
		case INTRAP:
			break;
		default:
			break;
		}
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

