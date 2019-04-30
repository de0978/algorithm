#include "Token.h"

Token::Token() {

}

Token::Token(int operand) {

	this->operand = operand;
	this->op = NULL;
	this->isOperator = false;
}

Token::Token(char op) {

	this->op = op;
	this->isOperator = true;
}

Token::Token(int operand, char op) {

	this->operand = operand;
	this->op = op;
	this->isOperator = false;
}

Token::Token(const Token& token) {

	this->operand = token.operand;
	this->op = token.op;
	this->isOperator = token.isOperator;
}

Token& Token::operator=(const Token& token) {

	this->operand = token.operand;
	this->op = token.op;
	this->isOperator = token.isOperator;

	return *this;
}

Token::~Token() {

}

int Token::getOperand() {

	return operand;
}

char Token::getOperator() {

	return op;
}

bool Token::getIsOperator() {

	return isOperator;
}

void Token::setOperator(char op) {
	this->op = op;
}
