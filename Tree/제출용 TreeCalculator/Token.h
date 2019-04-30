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
	* 함수 이름 : Token
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 생성자
	*/
	Token();

	/*
	* 함수 이름 : Token
	* 반환 타입 : X
	* 매개 변수 : int
	* 함수 기능 : 생성자
	*/
	Token(int operand);

	/*
	* 함수 이름 : Token
	* 반환 타입 : X
	* 매개 변수 : char
	* 함수 기능 : 생성자
	*/
	Token(char op);

	/*
	* 함수 이름 : Token
	* 반환 타입 : X
	* 매개 변수 : int, char
	* 함수 기능 : 생성자
	*/
	Token(int operand, char op);
	
	/*
	* 함수 이름 : Token
	* 반환 타입 : X
	* 매개 변수 : char
	* 함수 기능 : 생성자
	*/
	Token(const Token& token);

	Token& operator=(const Token& token);

	/*
	* 함수 이름 : ~Token
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 생성자
	*/
	~Token();

	/*
	* 함수 이름 : getOperand
	* 반환 타입 : int
	* 매개 변수 : X
	* 함수 기능 : 피연산자 반환
	*/
	int getOperand();

	/*
	* 함수 이름 : getOperator
	* 반환 타입 : char
	* 매개 변수 : X
	* 함수 기능 : 연산자 반환
	*/
	char getOperator();

	/*
	* 함수 이름 : getIsOperator
	* 반환 타입 : bool
	* 매개 변수 : X
	* 함수 기능 : isOperator 반환
	*/
	bool getIsOperator();

	/*
	* 함수 이름 : setOperator
	* 반환 타입 : X
	* 매개 변수 : char
	* 함수 기능 : this->char = char
	*/
	void setOperator(char op);
};



#endif