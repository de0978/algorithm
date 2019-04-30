#ifndef __IOHANDLER_H__
#define __IOHANDLER_H__

#include<iostream>
using namespace std;

template < class T >
class IOHandler {

public:

	/*
	* 함수 이름 : insertData
	* 반환 타입 : T
	* 매개 변수 : X
	* 함수 기능 : 데이터 입력
	*/
	T insertData();

	/*
	* 함수 이름 : printMenu
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 메뉴 출력
	*/
	void printMainMenu();

	/*
	* 함수 이름 : printPrintMenu
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 출력 메뉴 출력
	*/
	void printPrintMenu();

	/*
	* 함수 이름 : insertChar
	* 반환 타입 : char
	* 매개 변수 : X
	* 함수 기능 : 사용자 선택
	*/
	char insertChar();

};

template < class T >
T IOHandler<T>::insertData() {

	T data;

	cout << endl << " [ 데이터 입력 ] : ";

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
	cout << " [ 1. 데이터 입력    ] " << endl;
	cout << " [ 2. 트리 메뉴 보기 ] " << endl;
	cout << " [ 3.    종료        ] " << endl;
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