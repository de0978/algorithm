#ifndef EXCEPTION
#define EXCEPTION

#include <iostream>
#include <string>
using namespace std;

class Exception {

private:

	string errMsg; // ���� �޼���

public:

	/*
	* �Լ� �̸� : ExceptionEmpty
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : ���� �޼��� �ʱ�ȭ
	*/
	Exception(string errMsg) { this->errMsg = errMsg; }


	/*
	* �Լ� �̸� : ~ExceptionEmpty
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : �Ҹ���
	*/
	~Exception() { }


	/*
	* �Լ� �̸� : printErrorMsg
	* ��ȯ Ÿ�� : void
	* �Ű� ���� : X
	* �Լ� ��� : error Msg ���
	*/
	void printErrorMsg() { cout << errMsg << endl; }

	void setErrorMsg(string errMsg) { this->errMsg = errMsg; }
};

#endif