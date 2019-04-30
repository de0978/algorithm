#ifndef __TREECALCULATOR_H__
#define __TREECALCULATOR_H__

#include <iomanip>
#include "ExpressionConvertor.h"
#include "TokenNode.h"

class TreeCalculator {

public:


	/*
	* 함수 이름 : TreeCalculator
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 생성자
	*/
	TreeCalculator();

	/*
	* 함수 이름 : ~TreeCalculator
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 소멸자
	*/
	~TreeCalculator();

	/*
	* 함수 이름 : compute
	* 반환 타입 : X
	* 매개 변수 : Expression&
	* 함수 기능 : 후위 연산식 계산
	*/
	void compute(Expression& exp);
	
	/*
	* 함수 이름 : printComputeProcess
	* 반환 타입 : X
	* 매개 변수 : TokenNode*, int
	* 함수 기능 : 계산 과정 트리 출력
	*/
	void printComputeProcess(TokenNode *rootNode, int len = 15);

};





#endif