#ifndef __EXCEPTIONOUTOFINDEX_H__
#define __EXCEPTIONOUTOFINDEX_H__

#include "Exception.h"
using namespace std;

class ExceptionOutOfIndex : public Exception {

public:

	/*
	* 함수 이름 : ExceptionOutOfIndex
	* 반환 타입 : X
	* 매개 변수 : string
	* 함수 기능 : 생성자
	*/
	ExceptionOutOfIndex() : Exception("Out Of Index") { }

	/*
	* 함수 이름 : ~ExceptionOutOfIndex
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 소멸자
	*/
	~ExceptionOutOfIndex() { }


};


#endif