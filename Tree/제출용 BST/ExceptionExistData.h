#ifndef EXCEPTIONEXISTDATA
#define EXCEPTIONEXISTDATA

#include "Exception.h"
using namespace std;

class ExceptionExistData : public Exception {

public:

	/*
	* �Լ� �̸� : ExceptionExistData
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : ���� �޼��� �ʱ�ȭ
	*/
	ExceptionExistData() : Exception(" Exist data") { }


	/*
	* �Լ� �̸� : ~ExceptionExistData
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : �Ҹ���
	*/
	~ExceptionExistData() { }

};

#endif