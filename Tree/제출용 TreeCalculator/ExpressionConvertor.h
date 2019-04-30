#ifndef __EXPRESSIONCONVERTOR_H__
#define __EXPRESSIONCONVERTOR_H__

#include <stack>
#include "Expression.h"
using namespace std;


class ExpressionConvertor {

public:

	/*
	* �Լ� �̸� : ExpressionConvertor
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : ������
	*/
	ExpressionConvertor() { }

	/*
	* �Լ� �̸� : ~ExpressionConvertor
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : �Ҹ���
	*/
	~ExpressionConvertor() { }

	/*
	* �Լ� �̸� : filterExpression
	* ��ȯ Ÿ�� : bool
	* �Ű� ���� : const Expression&
	* �Լ� ��� : ����� ���͸�
	*/
	bool filterExpression(Expression& exp);

	/*
	* �Լ� �̸� : checkSingleMinus
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : Expression&
	* �Լ� ��� : ���� ���̳ʽ� Ȯ�� �� ����
	*/
	void checkSingleMinus(Expression& exp);

	/*
	* �Լ� �̸� : ICP ( In-coming priority )
	* ��ȯ Ÿ�� : int
	* �Ű� ���� : const char
	* �Լ� ��� : ������ �켱���� ��ȯ
	*/
	int ICP(const char ch);

	/*
	* �Լ� �̸� : ISP  ( In stack priority )
	* ��ȯ Ÿ�� : int
	* �Ű� ���� : const char
	* �Լ� ��� : ������ �켱���� ��ȯ
	*/
	int ISP(const char ch);

	/*
	* �Լ� �̸� : strToExpression
	* ��ȯ Ÿ�� : void
	* �Ű� ���� : Expression&, string
	* �Լ� ��� : �Է��� ���ڿ��� Expression���� ĳ����
	*/
	void strToExpression(Expression& tokenExp,const string exp);

	/*
	* �Լ� �̸� : postfix
	* ��ȯ Ÿ�� : Expression
	* �Ű� ���� : string
	* �Լ� ��� : �Է��� ������� ���� ��������� ��ȯ
	*/
	Expression postfix(string exp);
};



#endif