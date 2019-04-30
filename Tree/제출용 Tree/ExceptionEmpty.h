#ifndef EXCEPTIONEMPTY
#define EXCEPTIONEMPTY

#include <iostream>
#include <string>
using namespace std;

class ExceptionEmpty {

private:

	string errMsg; // 오류 메세지

public:

	/*
	* 함수 이름 : ExceptionEmpty
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 에러 메세지 초기화
	*/
	ExceptionEmpty() { errMsg = "Empty Queue"; }
	

	/*
	* 함수 이름 : ~ExceptionEmpty
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 소멸자
	*/
	~ExceptionEmpty() { }


	/*
	* 함수 이름 : printErrorMsg
	* 반환 타입 : void
	* 매개 변수 : X
	* 함수 기능 : error Msg 출력
	*/
	void printErrorMsg() { cout << errMsg << endl; }
};

#endif