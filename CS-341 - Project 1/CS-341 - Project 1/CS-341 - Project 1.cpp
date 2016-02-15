/*
Anthony Degliomini
ad473
CS-341-452
Project 1
Prof. Nakayama
*/

#include "stdlib.h"
#include <iostream>
#include <cctype>
#include <string>
#include <fstream>

using namespace std;

/**
	Each enum value represents a different state in the DFA.
*/
enum State {
	START,
	INQ1,	//W
	INQ2,	//WW
	INQ3,	//WWW
	INQ4,	//WWW.
	INQ5,	//.
	INQ6,	//.C
	INQ7,	//.CO
	INQ8,	//.COM
	INQ9,	//.CN
	INQ10,	//.CO.
	INQ11,	//.CO.C
	INQ12,	//.CO.CN
	INQ13,	//WWW.*.COM
	INQ14,	//*.com   ||   *.cn   ||   *co.cn
	INQ15,	//WWW.C
	INQ16,	//WWW.CO
	INQ17,	//WWW.COM
	INQ18,	//WWW.CN
	INTRAP	//TRAP STATE
};

/**
	Prints the state of each character per the DFA.
	@param s the input string to test
	@return verdict whether or not the DFA accepts or rejects the string 
*/
string analyzeStr(string s) {
	string verdict = "Reject.";
	State state = START;

	for (int i = 0; i <= s.length(); i++) {
		switch(state) {
			//Starting state of all strings
			case START:
			//We need to check if the string starts with
			//'www' or any other characters.
			cout << "q" << state << endl;
			if (s[i] == 'w') {
				state = INQ1;
			} else {
				state = INQ14;
			}
			break;

			case INQ1:
			//We may read a '.' before we reach the third 'w'
			//so we need to take that into account
			cout << "q" << state << endl;
			if (s[i] == 'w') {
				state = INQ2;
			} else if (s[i] == '.') {
				state = INQ5;
			} else {
				state = INQ14;
			}
			break;

			case INQ2:
			//We may read a '.' before we reach the third 'w'
			//so we need to take that into account
			cout << "q" << state << endl;
			if (s[i] == 'w') {
				state = INQ3;
			} else if (s[i] == '.') {
				state = INQ5;
			} else {
				state = INQ14;
			}			
			break;

			case INQ3:
			//We need to check if we have read in www. (S1)
			//or something else, starting with www (S2)
			cout << "q" << state << endl;
			if (s[i] == '.') {
				state = INQ4;
			} else {
				state = INQ13;
			}
			break;

			case INQ4:
			//We need to check if (S2) starts with 'co', 'cn' or 'com'
			cout << "q" << state << endl;
			if (s[i] == 'c') {
				state = INQ15;
			} else if (s[i] == '.') {
				state = INQ5;
			} 
			else {
				state = INQ13;
			}
			break;

			case INQ5:
			//We have reached the start of the (S3) portion of the string
			//We need to determine how it ends
			cout << "q" << state << endl;
			if (s[i] == 'c') {
				state = INQ6;
			} else {
				state = INTRAP;
			}
			break;

			case INQ6:
			//String can end in cn, co.cn or com
			//We need to check which we are dealing with
			//Strings ending in anything other than the above
			//are sent to the trap state because they will always be rejected
			cout << "q" << state << endl;
			if (s[i] == 'o') {
				state = INQ7;
			} else if (s[i] == 'n') {
				state = INQ9;
			} 
			else {
				state = INTRAP;
			}
			break;

			case INQ7:
			//String can end in cn, co.cn or com
			//We need to check which we are dealing with
			//Strings ending in anything other than the above
			//are sent to the trap state because they will always be rejected
			cout << "q" << state << endl;
			if (s[i] == 'm') {
				state = INQ8;
			} else if (s[i] == '.') {
				state = INQ10;
			} else {
				state = INTRAP;
			}
			break;

			case INQ8:
			//This is an accepting state as long as we are at the
			//end of a string. Any additional characters will
			//cause the string to be rejected.
			cout << "q" << state << endl;
			verdict = "Accept";
			if (s[i]) {
				verdict = "Reject";
				state = INTRAP;
			}
			break;

			case INQ9:
			//This is an accepting state as long as we are at the
			//end of a string. Any additional characters will
			//cause the string to be rejected.
			cout << "q" << state << endl;
			verdict = "Accept";
			if (s[i]) {
				verdict = "Reject";
				state = INTRAP;
			}
			break;

			case INQ10:
			//We need to make sure the string ends in co.cn
			cout << "q" << state << endl;
			if (s[i] == 'c') {
				state = INQ11;
			} else {
				state = INTRAP;
			}
			break;

			case INQ11:
			//We need to make sure the string ends in co.cn
			cout << "q" << state << endl;
			if (s[i] == 'n') {
				state = INQ12;
			} else {
				state = INTRAP;
			}
			break;

			case INQ12:
			//This is an accepting state as long as we are at the
			//end of a string. Any additional characters will
			//cause the string to be rejected.
			cout << "q" << state << endl;
			verdict = "Accept";
			if (s[i]) {
				verdict = "Reject";
				state = INTRAP;
			}
			break;

			case INQ13:
			//This state satisfies the (S2) portion of the language
			//such that it is a symbol followed by zero or more symbols
			cout << "q" << state << endl;
			verdict = "Reject";
			if (s[i] == '.') {
				state = INQ5;
			} else {
				state = INQ13;
			}
			break;

			case INQ14:
			//This state accounts for strings starting without 'www.'
			cout << "q" << state << endl;
			if (s[i] == '.') {
				state = INQ5;
			} else {
				state = INQ14;
			}
			break;

			case INQ15:
			//We can have strings that start with 'www.' and followed by
			//words starting with c that belong to (S2) and not (S3)
			cout << "q" << state << endl;
			if (s[i] == 'o') {
				state = INQ16;
			} else if (s[i] == 'n') {
				state = INQ18;
			} else if (s[i] == '.') {
				state = INQ5;
			} else {
				state = INTRAP;
			}
			break;

			case INQ16:
			//We can have strings that start with 'www.' and followed by
			//words starting with c that belong to (S2) and not (S3
			cout << "q" << state << endl;
			if (s[i] == 'm') {
				state = INQ17;
			} else if (s[i] == '.') {
				state = INQ5;
			} else {
				state = INQ13;
				verdict = "Reject";
			}
			break;

			case INQ17:
			//This is an accepting state as long as we are at the
			//end of a string. Any additional characters will
			//cause the string to be rejected.
			cout << "q" << state << endl;
			verdict = "Accept";
			if (s[i]) {
				verdict = "Reject";
				if (s[i] == '.') {
					state = INQ5;
				} else {
					state = INQ13;
				}
			}
			break;

			case INQ18:
			//This is an accepting state as long as we are at the
			//end of a string. Any additional characters will
			//cause the string to be rejected.
			cout << "q" << state << endl;
			verdict = "Accept";
			if (s[i] == '.') {
				state = INQ5;
				verdict = "Reject";
			} else {
				state = INQ13;
			}
			break;

			case INTRAP:
			//We find ourselves here when something has gone terribly, terribly wrong.
			//Or the machine will always reject a string...
			cout << "IN TRAP STATE" << endl;
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
/*
	ifstream infile("prog1test.txt");

	while (infile >> go >> str) {
		cout << "---------------------" << endl;
		cout << str << endl;
		cout << "Verdict:  " << analyzeStr(str) << endl;
		cout << "---------------------" << endl << endl;
	}
*/
	//Check to see if the user wants to enter a string to test.
	cout << "Do you want to enter a string? (y/n)  ";
	cin >> go;
	cout << endl;
	while (!done) {
		if (go == 'y') {
			cout << "Sting to test:  ";
			cin >> str;
			cout << "---------------------" << endl;
			cout << str << endl;
			cout << "Verdict:  " << analyzeStr(str) << endl;
			cout << "---------------------" << endl;
			cout << "Again? (y/n)  ";
			cin >> go;
			cout << endl;
		} else {
			done = true;
		}
	}
	//else {
	//	cout << "Terminated.";
	//}

	return 0;
}

