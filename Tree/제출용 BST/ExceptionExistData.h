#ifndef EXCEPTIONEXISTDATA
#define EXCEPTIONEXISTDATA

#include "Exception.h"
using namespace std;

class ExceptionExistData : public Exception {

public:

	/*
	* 함수 이름 : ExceptionExistData
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 에러 메세지 초기화
	*/
	ExceptionExistData() : Exception(" Exist data") { }


	/*
	* 함수 이름 : ~ExceptionExistData
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 소멸자
	*/
	~ExceptionExistData() { }

};

#endif