#ifndef __IOHANDLER_H__
#define __IOHANDLER_H__

#include <iostream>
#include <string>
using namespace std;

template < class T >
class IOHandler {

public:

	/*
	* 함수 이름 : insertData
	* 반환 타입 : T
	* 매개 변수 : X
	* 함수 기능 : 데이터 삽입
	*/
	T insertData();

	/*
	* 함수 이름 : insertData();
	* 반환 타입 : char
	* 매개 변수 : X
	* 함수 기능 : 캐릭터형 변수 입력
	*/
	char insertChar();

	/*
	* 함수 이름 : insertString
	* 반환 타입 : X
	* 매개 변수 : string
	* 함수 기능 : 스트링 변수 출력
	*/
	void insertString(const string str);

	/*
	* 함수 이름 : showMainMenu
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 메인 화면 출력
	*/
	void showMainMenu() const;

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
void IOHandler<T>::insertString(const string str) {

	cout << str << endl;
}

template < class T >
void IOHandler<T>::showMainMenu() const {

	cout << endl << " [ 메인 화면 ] " << endl;
	cout << " [ 1 ] 데이터 입력" << endl;
	cout << " [ 2 ] 트리 출력" << endl;
	cout << " [ 3 ] 종료" << endl;
	cout << " [ 입력 ] : ";
}

#endif