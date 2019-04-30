#ifndef __EXPRESSIONCONVERTOR_H__
#define __EXPRESSIONCONVERTOR_H__

#include <stack>
#include "Expression.h"
using namespace std;


class ExpressionConvertor {

public:

	/*
	* 함수 이름 : ExpressionConvertor
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 생성자
	*/
	ExpressionConvertor() { }

	/*
	* 함수 이름 : ~ExpressionConvertor
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 소멸자
	*/
	~ExpressionConvertor() { }

	/*
	* 함수 이름 : filterExpression
	* 반환 타입 : bool
	* 매개 변수 : const Expression&
	* 함수 기능 : 연산식 필터링
	*/
	bool filterExpression(Expression& exp);

	/*
	* 함수 이름 : checkSingleMinus
	* 반환 타입 : X
	* 매개 변수 : Expression&
	* 함수 기능 : 단항 마이너스 확인 및 수정
	*/
	void checkSingleMinus(Expression& exp);

	/*
	* 함수 이름 : ICP ( In-coming priority )
	* 반환 타입 : int
	* 매개 변수 : const char
	* 함수 기능 : 연산자 우선순위 반환
	*/
	int ICP(const char ch);

	/*
	* 함수 이름 : ISP  ( In stack priority )
	* 반환 타입 : int
	* 매개 변수 : const char
	* 함수 기능 : 연산자 우선순위 반환
	*/
	int ISP(const char ch);

	/*
	* 함수 이름 : strToExpression
	* 반환 타입 : void
	* 매개 변수 : Expression&, string
	* 함수 기능 : 입력한 문자열을 Expression으로 캐스팅
	*/
	void strToExpression(Expression& tokenExp,const string exp);

	/*
	* 함수 이름 : postfix
	* 반환 타입 : Expression
	* 매개 변수 : string
	* 함수 기능 : 입력한 연산식을 후위 연산식으로 변환
	*/
	Expression postfix(string exp);
};



#endif