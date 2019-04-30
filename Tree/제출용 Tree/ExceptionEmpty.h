#ifndef EXCEPTIONEMPTY
#define EXCEPTIONEMPTY

#include <iostream>
#include <string>
using namespace std;

class ExceptionEmpty {

private:

	string errMsg; // ���� �޼���

public:

	/*
	* �Լ� �̸� : ExceptionEmpty
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : ���� �޼��� �ʱ�ȭ
	*/
	ExceptionEmpty() { errMsg = "Empty Queue"; }
	

	/*
	* �Լ� �̸� : ~ExceptionEmpty
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : �Ҹ���
	*/
	~ExceptionEmpty() { }


	/*
	* �Լ� �̸� : printErrorMsg
	* ��ȯ Ÿ�� : void
	* �Ű� ���� : X
	* �Լ� ��� : error Msg ���
	*/
	void printErrorMsg() { cout << errMsg << endl; }
};

#endif