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
	* 함수 이름 : extendArray
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 배열 크기 확장
	*/
	void extendArray();

public:

	/*
	* 함수 이름 : Expression
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 생성자
	*/
	Expression(int capacity = 10);

	/*
	* 함수 이름 : ~Expression
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 소멸자
	*/
	~Expression();

	/*
	* 함수 이름 : operator[]
	* 반환 타입 : Token&
	* 매개 변수 : int
	* 함수 기능 : return exp[index]
	*/
	Token& operator[](int index);

	/*
	* 함수 이름 : operator=
	* 반환 타입 : Expression&
	* 매개 변수 : Expression& e
	* 함수 기능 : return *this
	*/
	Expression& operator=(Expression& e);

	/*
	* 함수 이름 : addToken
	* 반환 타입 : X
	* 매개 변수 : const Token& token
	* 함수 기능 : 배열에 토큰 추가
	*/
	void addToken(Token& token);

	/*
	* 함수 이름 : isFull
	* 반환 타입 : bool
	* 매개 변수 : X
	* 함수 기능 : 배열이 꽉 찼는지 확인
	*/
	bool isFull();

	/*
	* 함수 이름 : isEmpty
	* 반환 타입 : bool
	* 매개 변수 : X
	* 함수 기능 : 빈 배열인지 확인
	*/
	bool isEmpty();

	/*
	* 함수 이름 : getLength
	* 반환 타입 : int
	* 매개 변수 : X
	* 함수 기능 : 배열 인덱스 반환
	*/
	int getLength();
	
	/*
	* 함수 이름 : getToken
	* 반환 타입 : Token
	* 매개 변수 : const int
	* 함수 기능 : exp[index] 반환
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