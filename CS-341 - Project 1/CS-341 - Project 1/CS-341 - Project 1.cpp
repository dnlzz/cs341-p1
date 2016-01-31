// CS-341 - Project 1.cpp : Defines the entry point for the console application.
//

#include "stdlib.h"
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

/**
	Each enum value represents a different state in the DFA.
*/
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
	INQ12,
	INQ13,
	INQ14,
	INTRAP
};

/**
	Prints the state of each character per the DFA.
	@param s the input string to test 
*/
string analyzeStr(string s) {
	string verdict = "Reject.";
	State state = START;
	string lex;		//possibly do not need this
	lex.clear();	//or this

	for (int i = 0; i < s.length(); i++) {
		//cout << s[i] << endl;
		switch (state)
		{
		case START:
			cout << "q" << state << endl;
			//Check to see if we are starting in S1 or S2
			if (s[i] == 'w') {
				state = INQ1;
			} else if (s[i] == '.') {
				state = INQ7;
			} else {
				//We are not in S1, we are hopefully in S2
				//TO DO handling single letter (ie test case #3)
				state = START;
			}
			break;
		case INQ1:
			cout << "q" << state << endl;
			if (s[i] == 'w') {
				state = INQ2;
			} else {
				state = INQ5;
			}
			break;
		case INQ2:
			cout << "q" << state << endl;
			if (s[i] == 'w') {
				state = INQ3;
			} else {
				state = INQ5;
			}
			break;
		case INQ3:
			cout << "q" << state << endl;
			if (s[i] == '.') {
				state = INQ4;
			} else {
				state = INQ5;
			}
			break;
		//Successfully found 'www.'
		case INQ4:
			state = START;
			break;
		case INQ5:
			cout << "Trap State." << endl;
			break;
		case INQ6:
			cout << "q" << state << endl;
			if (s[i] == '.') {
				state = INQ7;
			} else {
				state = INQ6;
			}
			break;
		case INQ7:
			cout << "q" << state << endl;
			if (s[i] == 'c') {
				state = INQ8;
			}
			break;
		case INQ8:
			cout << "q" << state << endl;
			if (s[i] == 'o') {
				state = INQ9;
			} else if (s[i] == 'n') {
				cout << "Accept." << endl;
				cout << ".cn" << endl;
				verdict = "Accept";
				state = INQ14;
			}
			break;
		case INQ9:
			cout << "q" << state << endl;
			if (s[i] == 'm') {
				cout << "Accept." << endl;
				cout << ".com" << endl;
				verdict = "Accept";
				state = INQ10;
			} else if (s[i] == '.') {
				state = INQ11;
			}
			break;
		//this case may not be necessary for the given test cases...
		case INQ10:
			cout << "q" << state << endl;
			cout << "INQ10" << endl;
			if (isalpha(s[i])) {
				state = INQ5; //letters after .com
			} else {
			cout << "Accept." << endl;
			cout << ".com" << endl;
			verdict = "Accept";
			}
			break;
		case INQ11:
			cout << "q" << state << endl;
			if (s[i] == 'c') {
				state = INQ12;
			}
			break;
		case INQ12:
			cout << "q" << state << endl;
			if (s[i] == 'n') {
				cout << "Accept." << endl;
				cout << ".co.cn" << endl;
				verdict = "Accept";
				state = INQ13;
			}
			break;
		case INQ13:
			cout << "Accept." << endl;
			cout << ".co.cn" << endl;
			break;			

		case INQ14:
			cout << "Accept." << endl;
			cout << ".cn" << endl;
			break;
		default:
			break;
		}
	}

return verdict;

};

int main()
{
	bool done = false;
	string str;
	char go;

	//Check to see if the user wants to enter a string to test.
	cin >> go;
	while (go == 'y') {
		cin >> str;
		cout << str << endl;
		cout << "Verdict:  " << analyzeStr(str) << endl;

		cin >> go;
	}

	return 0;
}

