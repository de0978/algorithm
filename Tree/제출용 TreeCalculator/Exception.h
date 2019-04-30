#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <iostream>
#include <string>
using namespace std;

class Exception {

private:

	string errMsg;

public:

	/*
	* 함수 이름 : Exception
	* 반환 타입 : X
	* 매개 변수 : string errMsg
	* 함수 기능 : 생성자
	*/
	Exception(string errMsg = " Exception") { this->errMsg = errMsg; }

	/*
	* 함수 이름 : ~Exception
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 소멸자
	*/
	~Exception() { }

	/*
	* 함수 이름 : printErrorMsg
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 에러 메세지 출력
	*/
	void printErrorMsg() { cout << errMsg << endl; }
};



#endif