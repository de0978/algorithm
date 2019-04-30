#ifndef __IOHANDLER_H__
#define __IOHANDLER_H__

#include <iostream>
#include <string>
using namespace std;

class IOHandler {

public:

	/*
	* �Լ� �̸� : putString
	* ��ȯ Ÿ�� : string
	* �Ű� ���� : X
	* �Լ� ��� : ������ ����
	*/
	string insertExp();

	/*
	* �Լ� �̸� : insertData();
	* ��ȯ Ÿ�� : char
	* �Ű� ���� : X
	* �Լ� ��� : ĳ������ ���� �Է�
	*/
	char insertChar();

	/*
	* �Լ� �̸� : insertString
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : string
	* �Լ� ��� : ��Ʈ�� ���� ���
	*/
	void insertString(const string str);

};

#endif