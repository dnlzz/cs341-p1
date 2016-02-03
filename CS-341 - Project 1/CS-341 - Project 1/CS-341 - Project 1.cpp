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
	INQ14,	//*.com / *.cn / *co.cn
	INQ15,	//WWW.C
	INQ16,	//WWW.CO
	INQ17,	//WWW.COM
	INQ18,	//WWW.CN
	INTRAP	//TRAP STATE
};

/**
	Prints the state of each character per the DFA.
	@param s the input string to test 
*/
string analyzeStr(string s) {
	string verdict = "Reject.";
	State state = START;

	for (int i = 0; i <= s.length(); i++) {
		switch(state) {
			case START:
			cout << "q" << state << endl;
			if (s[i] == 'w') {
				state = INQ1;
			} else {
				state = INQ14;
			}
			break;

			case INQ1:
			cout << "q" << state << endl;
			if (s[i] == 'w') {
				state = INQ2;
			} else {
				state = INQ14;
			}
			break;

			case INQ2:
			cout << "q" << state << endl;
			if (s[i] == 'w') {
				state = INQ3;
			} else {
				state = INQ14;
			}			
			break;

			case INQ3:
			cout << "q" << state << endl;
			if (s[i] == '.') {
				state = INQ4;
			} else {
				state = INQ13;
			}
			break;

			case INQ4:
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
			cout << "q" << state << endl;
			if (s[i] == 'c') {
				state = INQ6;
			} else {
				state = INTRAP;
			}
			break;

			case INQ6:
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
			cout << "q" << state << endl;
			if (s[i] == 'm') {
				state = INQ8;
			} else if (s[i] == '.') {
				state = INQ10;
			} /*else {
				state = INQ13;
			}*/
			break;

			case INQ8:
			cout << "q" << state << endl;
			verdict = "Accept";
			if (isalpha(s[i])) {
				verdict = "Reject";
				state = INTRAP;
			}
			//Accept state as long as there is no more input.
			//if s[i] is alpha - reject, else accept...?
			break;

			case INQ9:
			cout << "q" << state << endl;
			verdict = "Accept";
			if (isalpha(s[i])) {
				verdict = "Reject";
				state = INTRAP;
			}
			//Accept state as long as there is no more input.
			//if s[i] is alpha - reject, else accept...?
			break;

			case INQ10:
			cout << "q" << state << endl;
			if (s[i] == 'c') {
				state = INQ11;
			} else {
				state = INTRAP;
			}
			break;

			case INQ11:
			cout << "q" << state << endl;
			if (s[i] == 'n') {
				state = INQ12;
			} else {
				state = INTRAP;
			}
			break;

			case INQ12:
			cout << "q" << state << endl;
			verdict = "Accept";
			if (isalpha(s[i])) {
				verdict = "Reject";
				state = INTRAP;
			}
			//Accept state as long as there is no more input.
			//if s[i] is alpha - reject, else accept...?
			break;

			case INQ13:
			cout << "q" << state << endl;
			verdict = "Reject";
			if (s[i] == '.') {
				state = INQ5;
			} else {
				state = INQ13;
			}
			break;

			case INQ14:
			cout << "q" << state << endl;
			if (s[i] == '.') {
				state = INQ5;
			} else {
				state = INQ14;
			}
			break;

			case INQ15:
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
			cout << "q" << state << endl;
			//Accept state as long as there is no more input.
			//if s[i] is alpha - state = INQ13, else accept...?
			//
			verdict = "Accept";
			if (s[i] == '.') {
				state = INQ5;
				verdict = "Reject";
			} else {
				state = INQ13;
			}
			break;

			case INTRAP:
			cout << "INTRAP" << state << endl;
			break;
		}
	}

	/*for (int i = 0; i < s.length(); i++) {
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
	}*/

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

