#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__

#include "Token.h"
#include "ExceptionOutOfIndex.h"
using namespace std;

class Expression {

private:

	Token *exp;
	int length;
	int capacity;

	/*
	* �Լ� �̸� : extendArray
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : �迭 ũ�� Ȯ��
	*/
	void extendArray();

public:

	/*
	* �Լ� �̸� : Expression
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : ������
	*/
	Expression(int capacity = 10);

	/*
	* �Լ� �̸� : ~Expression
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : �Ҹ���
	*/
	~Expression();

	/*
	* �Լ� �̸� : operator[]
	* ��ȯ Ÿ�� : Token&
	* �Ű� ���� : int
	* �Լ� ��� : return exp[index]
	*/
	Token& operator[](int index);

	/*
	* �Լ� �̸� : operator=
	* ��ȯ Ÿ�� : Expression&
	* �Ű� ���� : Expression& e
	* �Լ� ��� : return *this
	*/
	Expression& operator=(Expression& e);

	/*
	* �Լ� �̸� : addToken
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : const Token& token
	* �Լ� ��� : �迭�� ��ū �߰�
	*/
	void addToken(Token& token);

	/*
	* �Լ� �̸� : isFull
	* ��ȯ Ÿ�� : bool
	* �Ű� ���� : X
	* �Լ� ��� : �迭�� �� á���� Ȯ��
	*/
	bool isFull();

	/*
	* �Լ� �̸� : isEmpty
	* ��ȯ Ÿ�� : bool
	* �Ű� ���� : X
	* �Լ� ��� : �� �迭���� Ȯ��
	*/
	bool isEmpty();

	/*
	* �Լ� �̸� : getLength
	* ��ȯ Ÿ�� : int
	* �Ű� ���� : X
	* �Լ� ��� : �迭 �ε��� ��ȯ
	*/
	int getLength();
	
	/*
	* �Լ� �̸� : getToken
	* ��ȯ Ÿ�� : Token
	* �Ű� ���� : const int
	* �Լ� ��� : exp[index] ��ȯ
	*/
	Token getToken(const int index);


	void test() {

		for (int i = 0; i < length; ++i) {

			if (exp[i].getIsOperator())
				cout << exp[i].getOperator() << " ";

			else
				cout << exp[i].getOperand() << " ";
		}
	}
};


#endif