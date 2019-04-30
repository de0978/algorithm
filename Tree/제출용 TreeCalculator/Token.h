#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <iostream>
#include <string>
using namespace std;

class Token {

private:

	int operand;
	char op;
	bool isOperator;

public:

	/*
	* �Լ� �̸� : Token
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : ������
	*/
	Token();

	/*
	* �Լ� �̸� : Token
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : int
	* �Լ� ��� : ������
	*/
	Token(int operand);

	/*
	* �Լ� �̸� : Token
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : char
	* �Լ� ��� : ������
	*/
	Token(char op);

	/*
	* �Լ� �̸� : Token
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : int, char
	* �Լ� ��� : ������
	*/
	Token(int operand, char op);
	
	/*
	* �Լ� �̸� : Token
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : char
	* �Լ� ��� : ������
	*/
	Token(const Token& token);

	Token& operator=(const Token& token);

	/*
	* �Լ� �̸� : ~Token
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : ������
	*/
	~Token();

	/*
	* �Լ� �̸� : getOperand
	* ��ȯ Ÿ�� : int
	* �Ű� ���� : X
	* �Լ� ��� : �ǿ����� ��ȯ
	*/
	int getOperand();

	/*
	* �Լ� �̸� : getOperator
	* ��ȯ Ÿ�� : char
	* �Ű� ���� : X
	* �Լ� ��� : ������ ��ȯ
	*/
	char getOperator();

	/*
	* �Լ� �̸� : getIsOperator
	* ��ȯ Ÿ�� : bool
	* �Ű� ���� : X
	* �Լ� ��� : isOperator ��ȯ
	*/
	bool getIsOperator();

	/*
	* �Լ� �̸� : setOperator
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : char
	* �Լ� ��� : this->char = char
	*/
	void setOperator(char op);
};



#endif