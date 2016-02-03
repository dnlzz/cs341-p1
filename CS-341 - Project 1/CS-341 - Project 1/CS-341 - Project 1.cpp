// CS-341 - Project 1.cpp : Defines the entry point for the console application.
//

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
	INQ14,	//*.com / *.cn / *co.cn
	INQ15,	//WWW.C
	INQ16,	//WWW.CO
	INQ17,	//WWW.COM
	INQ18,	//WWW.CN
	INQ19,	//W.	     WW.
	INQ20,	//W.C        WW.C
	INQ21,	//W.CN       WW.CN
	INQ22,	//W.CO       WW.CO
	INQ23,	//W.CO.      WW.CO.
	INQ24,	//W.CO.C     WW.CO.C
	INQ25,	//W.CO.CN    WW.CO.CN
	INQ26,	//W.COM      WW.COM
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
			} else if (s[i] == '.') {
				state = INQ19;
			} else {
				state = INQ14;
			}
			break;

			case INQ2:
			cout << "q" << state << endl;
			if (s[i] == 'w') {
				state = INQ3;
			} else if (s[i] == '.') {
				state = INQ19;
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
			if (s[i]) {
				verdict = "Reject";
				state = INTRAP;
			}
			//Accept state as long as there is no more input.
			//if s[i] is alpha - reject, else accept...?
			break;

			case INQ9:
			cout << "q" << state << endl;
			verdict = "Accept";
			if (s[i]) {
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
			if (s[i]) {
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

			case INQ19:
			cout << "q" << state << endl;
			if (s[i] == 'c') {
				state = INQ20;
			} else {
				state = INTRAP;
			}
			break;

			case INQ20:
			cout << "q" << state << endl;
			if (s[i] == 'o') {
				state = INQ21;
			} else if (s[i] == 'n') {
				state = INQ23;
			} 
			else {
				state = INTRAP;
			}
			break;

			case INQ21:
			cout << "q" << state << endl;
			if (s[i] == 'm') {
				state = INQ22;
			} else if (s[i] == '.') {
				state = INQ24;
			} /*else {
				state = INQ13;
			}*/
			break;

			case INQ22:
			cout << "q" << state << endl;
			verdict = "Accept";
			if (s[i]) {
				verdict = "Reject";
				state = INTRAP;
			}
			//Accept state as long as there is no more input.
			//if s[i] is alpha - reject, else accept...?
			break;

			case INQ23:
			cout << "q" << state << endl;
			verdict = "Accept";
			if (s[i]) {
				verdict = "Reject";
				state = INTRAP;
			}
			//Accept state as long as there is no more input.
			//if s[i] is alpha - reject, else accept...?
			break;

			case INQ24:
			cout << "q" << state << endl;
			if (s[i] == 'c') {
				state = INQ25;
			} else {
				state = INTRAP;
			}
			break;

			case INQ25:
			cout << "q" << state << endl;
			if (s[i] == 'n') {
				state = INQ26;
			} else {
				state = INTRAP;
			}
			break;

			case INQ26:
			cout << "q" << state << endl;
			verdict = "Accept";
			if (s[i]) {
				verdict = "Reject";
				state = INTRAP;
			}
			//Accept state as long as there is no more input.
			//if s[i] is alpha - reject, else accept...?
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
	ifstream infile("C:\\Users\\Pedeco-\\Desktop\\prog1test.txt");

	//Check to see if the user wants to enter a string to test.

	while (infile >> go >> str) {
		cout << str << endl;
		cout << "Verdict:  " << analyzeStr(str) << endl;
	}

	return 0;
}

