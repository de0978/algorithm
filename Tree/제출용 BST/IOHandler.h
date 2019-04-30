#ifndef __IOHANDLER_H__
#define __IOHANDLER_H__

#include <iostream>
#include <string>
using namespace std;

template < class T >
class IOHandler {

public:

	/*
	* �Լ� �̸� : insertData
	* ��ȯ Ÿ�� : T
	* �Ű� ���� : X
	* �Լ� ��� : ������ ����
	*/
	T insertData();

	/*
	* �Լ� �̸� : insertData();
	* ��ȯ Ÿ�� : char
	* �Ű� ���� : X
	* �Լ� ��� : ĳ������ ���� �Է�
	*/
	char insertChar();

	/*
	* �Լ� �̸� : insertString
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : string
	* �Լ� ��� : ��Ʈ�� ���� ���
	*/
	void insertString(const string str);

	/*
	* �Լ� �̸� : showMainMenu
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : ���� ȭ�� ���
	*/
	void showMainMenu() const;

};

template < class T >
T IOHandler<T>::insertData() {

	T data;

	cout << endl << " [ ������ �Է� ] : ";

	cin >> data;

	return data;
}

template < class T >
char IOHandler<T>::insertChar() {

	char ch;

	cin >> ch;

	return ch;
}

template < class T >
void IOHandler<T>::insertString(const string str) {

	cout << str << endl;
}

template < class T >
void IOHandler<T>::showMainMenu() const {

	cout << endl << " [ ���� ȭ�� ] " << endl;
	cout << " [ 1 ] ������ �Է�" << endl;
	cout << " [ 2 ] Ʈ�� ���" << endl;
	cout << " [ 3 ] ����" << endl;
	cout << " [ �Է� ] : ";
}

#endif