#ifndef __TREECALCULATOR_H__
#define __TREECALCULATOR_H__

#include <iomanip>
#include "ExpressionConvertor.h"
#include "TokenNode.h"

class TreeCalculator {

public:


	/*
	* �Լ� �̸� : TreeCalculator
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : ������
	*/
	TreeCalculator();

	/*
	* �Լ� �̸� : ~TreeCalculator
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : �Ҹ���
	*/
	~TreeCalculator();

	/*
	* �Լ� �̸� : compute
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : Expression&
	* �Լ� ��� : ���� ����� ���
	*/
	void compute(Expression& exp);
	
	/*
	* �Լ� �̸� : printComputeProcess
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : TokenNode*, int
	* �Լ� ��� : ��� ���� Ʈ�� ���
	*/
	void printComputeProcess(TokenNode *rootNode, int len = 15);

};





#endif