#include "TokenNode.h"

TokenNode::TokenNode(Token& token, TokenNode *left, TokenNode *right) {

	this->data = token;
	this->leftChild = left;
	this->rightChild = right;
}

TokenNode::~TokenNode() {

	if (leftChild) delete leftChild;
	if (rightChild) delete rightChild;
}

void TokenNode::makeLeftChild(Token& token) {

	leftChild = new TokenNode(token);
}

void TokenNode::makeRightChild(Token& token) {

	rightChild = new TokenNode(token);
}

TokenNode* TokenNode::getLeftChild() {

	return leftChild;
}

TokenNode* TokenNode::getRightChild() {

	return rightChild;
}

Token TokenNode::getToken() {

	return data;
}