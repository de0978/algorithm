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
	* �Լ� �̸� : Exception
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : string errMsg
	* �Լ� ��� : ������
	*/
	Exception(string errMsg = " Exception") { this->errMsg = errMsg; }

	/*
	* �Լ� �̸� : ~Exception
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : �Ҹ���
	*/
	~Exception() { }

	/*
	* �Լ� �̸� : printErrorMsg
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : ���� �޼��� ���
	*/
	void printErrorMsg() { cout << errMsg << endl; }
};



#endif