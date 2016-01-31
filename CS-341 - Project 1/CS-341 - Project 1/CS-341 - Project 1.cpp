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

string analyzeStr(string s) {
	cout << s.length() << endl;
	return 0;
};

int main()
{
	bool done = false;
	string str;
	char go;

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

