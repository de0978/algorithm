#include "IOHandler.h"

string IOHandler::insertExp() {

	string data;

	cout << endl << " [ 연산식 입력 ] : ";

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
