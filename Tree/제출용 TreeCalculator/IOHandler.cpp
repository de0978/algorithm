#include "IOHandler.h"

string IOHandler::insertExp() {

	string data;

	cout << endl << " [ ����� �Է� ] : ";

	getline(cin, data, '\n');

	return data;
}

char IOHandler::insertChar() {

	char ch;

	cin >> ch;

	return ch;
}


void IOHandler::insertString(const string str) {

	cout << str << endl;
}
