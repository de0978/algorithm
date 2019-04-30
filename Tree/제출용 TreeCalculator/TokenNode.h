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
	* �Լ� �̸� : TokenNode
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : Token&, TokenNode* default NULL, TokenNode* defulat NULL
	* �Լ� ��� : ������
	*/
	TokenNode(Token& token, TokenNode *left = NULL, TokenNode *right = NULL);

	/*
	* �Լ� �̸� : ~TokenNode
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : �Ҹ���
	*/
	~TokenNode();

	/*
	* �Լ� �̸� : makeLeftChild
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : Token&
	* �Լ� ��� : ���� �ڽ� �Ҵ�
	*/
	void makeLeftChild(Token& token);

	/*
	* �Լ� �̸� : makeRightChild
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : Token&
	* �Լ� ��� : ������ �ڽ� �Ҵ�
	*/
	void makeRightChild(Token &token);

	/*
	* �Լ� �̸� : getLeftChild
	* ��ȯ Ÿ�� : TreeNode*
	* �Ű� ���� : X
	* �Լ� ��� : return leftChild
	*/
	TokenNode* getLeftChild();

	/*
	* �Լ� �̸� : getRightChild
	* ��ȯ Ÿ�� : TreeNode*
	* �Ű� ���� : X
	* �Լ� ��� : return rightChild
	*/
	TokenNode* getRightChild();

	/*
	* �Լ� �̸� : getToken
	* ��ȯ Ÿ�� : Token
	* �Ű� ���� : X
	* �Լ� ��� : return data
	*/
	Token getToken();

};


#endif