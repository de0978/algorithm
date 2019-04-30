#ifndef __IOHANDLER_H__
#define __IOHANDLER_H__

#include <iostream>
#include <string>
using namespace std;

class IOHandler {

public:

	/*
	* 함수 이름 : putString
	* 반환 타입 : string
	* 매개 변수 : X
	* 함수 기능 : 데이터 삽입
	*/
	string insertExp();

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

};

#endif