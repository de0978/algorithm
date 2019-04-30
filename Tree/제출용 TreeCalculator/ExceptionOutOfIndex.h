#ifndef __EXCEPTIONOUTOFINDEX_H__
#define __EXCEPTIONOUTOFINDEX_H__

#include "Exception.h"
using namespace std;

class ExceptionOutOfIndex : public Exception {

public:

	/*
	* �Լ� �̸� : ExceptionOutOfIndex
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : string
	* �Լ� ��� : ������
	*/
	ExceptionOutOfIndex() : Exception("Out Of Index") { }

	/*
	* �Լ� �̸� : ~ExceptionOutOfIndex
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : �Ҹ���
	*/
	~ExceptionOutOfIndex() { }


};


#endif