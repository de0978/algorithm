#ifndef __TOKENNODE_H__
#define __TOKENNODE_H__

#include "Token.h"
using namespace std;

class TokenNode {

private:

	Token data;
	TokenNode *leftChild;
	TokenNode *rightChild;

public:

	/*
	* 함수 이름 : TokenNode
	* 반환 타입 : X
	* 매개 변수 : Token&, TokenNode* default NULL, TokenNode* defulat NULL
	* 함수 기능 : 생성자
	*/
	TokenNode(Token& token, TokenNode *left = NULL, TokenNode *right = NULL);

	/*
	* 함수 이름 : ~TokenNode
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 소멸자
	*/
	~TokenNode();

	/*
	* 함수 이름 : makeLeftChild
	* 반환 타입 : X
	* 매개 변수 : Token&
	* 함수 기능 : 왼쪽 자식 할당
	*/
	void makeLeftChild(Token& token);

	/*
	* 함수 이름 : makeRightChild
	* 반환 타입 : X
	* 매개 변수 : Token&
	* 함수 기능 : 오른쪽 자식 할당
	*/
	void makeRightChild(Token &token);

	/*
	* 함수 이름 : getLeftChild
	* 반환 타입 : TreeNode*
	* 매개 변수 : X
	* 함수 기능 : return leftChild
	*/
	TokenNode* getLeftChild();

	/*
	* 함수 이름 : getRightChild
	* 반환 타입 : TreeNode*
	* 매개 변수 : X
	* 함수 기능 : return rightChild
	*/
	TokenNode* getRightChild();

	/*
	* 함수 이름 : getToken
	* 반환 타입 : Token
	* 매개 변수 : X
	* 함수 기능 : return data
	*/
	Token getToken();

};


#endif