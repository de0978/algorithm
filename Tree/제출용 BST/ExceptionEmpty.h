#ifndef EXCEPTIONEMPTY
#define EXCEPTIONEMPTY

#include "Exception.h"
using namespace std;

class ExceptionEmpty : public Exception {

public:

	/*
	* �Լ� �̸� : ExceptionEmpty
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : ���� �޼��� �ʱ�ȭ
	*/
	ExceptionEmpty() : Exception(" Empty Queue") { }


	/*
	* �Լ� �̸� : ~ExceptionEmpty
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : �Ҹ���
	*/
	~ExceptionEmpty() { }

};

#endif