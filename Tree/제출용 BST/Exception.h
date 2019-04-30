#ifndef EXCEPTION
#define EXCEPTION

#include <iostream>
#include <string>
using namespace std;

class Exception {

private:

	string errMsg; // 오류 메세지

public:

	/*
	* 함수 이름 : ExceptionEmpty
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 에러 메세지 초기화
	*/
	Exception(string errMsg) { this->errMsg = errMsg; }


	/*
	* 함수 이름 : ~ExceptionEmpty
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 소멸자
	*/
	~Exception() { }


	/*
	* 함수 이름 : printErrorMsg
	* 반환 타입 : void
	* 매개 변수 : X
	* 함수 기능 : error Msg 출력
	*/
	void printErrorMsg() { cout << errMsg << endl; }

	void setErrorMsg(string errMsg) { this->errMsg = errMsg; }
};

#endif