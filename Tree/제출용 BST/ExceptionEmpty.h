#ifndef EXCEPTIONEMPTY
#define EXCEPTIONEMPTY

#include "Exception.h"
using namespace std;

class ExceptionEmpty : public Exception {

public:

	/*
	* 함수 이름 : ExceptionEmpty
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 에러 메세지 초기화
	*/
	ExceptionEmpty() : Exception(" Empty Queue") { }


	/*
	* 함수 이름 : ~ExceptionEmpty
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 소멸자
	*/
	~ExceptionEmpty() { }

};

#endif