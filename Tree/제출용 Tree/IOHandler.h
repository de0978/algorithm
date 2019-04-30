#ifndef __IOHANDLER_H__
#define __IOHANDLER_H__

#include<iostream>
using namespace std;

template < class T >
class IOHandler {

public:

	/*
	* �Լ� �̸� : insertData
	* ��ȯ Ÿ�� : T
	* �Ű� ���� : X
	* �Լ� ��� : ������ �Է�
	*/
	T insertData();

	/*
	* �Լ� �̸� : printMenu
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : �޴� ���
	*/
	void printMainMenu();

	/*
	* �Լ� �̸� : printPrintMenu
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : ��� �޴� ���
	*/
	void printPrintMenu();

	/*
	* �Լ� �̸� : insertChar
	* ��ȯ Ÿ�� : char
	* �Ű� ���� : X
	* �Լ� ��� : ����� ����
	*/
	char insertChar();

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
void IOHandler<T>::printMainMenu() {

	cout << " ---- Main Menu ----" << endl;
	cout << " [ 1. ������ �Է�    ] " << endl;
	cout << " [ 2. Ʈ�� �޴� ���� ] " << endl;
	cout << " [ 3.    ����        ] " << endl;
}

template < class T >
void IOHandler<T>::printPrintMenu() {

	cout << endl << " ---- Print Menu ---- " << endl;
	cout << " [ 1. PreOrder    ]" << endl;
	cout << " [ 2. InOrder     ]" << endl;
	cout << " [ 3. PostOrder   ]" << endl;
	cout << " [ 4. LevelOrder  ]" << endl;
	cout << " [ 5. Print Tree  ]" << endl;

}

#endif