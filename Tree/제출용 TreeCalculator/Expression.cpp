#include "Expression.h"

Expression::Expression(int capacity) {

	if (capacity <= 0)
		exit(1);

	length = 0;
	this->capacity = capacity;
	
	exp = new Token[capacity];
}

Expression::~Expression() {


}

Expression& Expression::operator=(Expression& e) {

	if (exp)
		delete exp;

	this->length = e.length;
	this->capacity = e.capacity;
	this->exp = new Token(capacity);

	for (int i = 0; i < length; ++i)
		exp[i] = e[i];

	return *this;
}

Token& Expression::operator[](int index) {

	try {

		if (length <= index)
			throw ExceptionOutOfIndex();

		return exp[index];
	}

	catch (ExceptionOutOfIndex e) {
		e.printErrorMsg();
	}
}

bool Expression::isFull() {

	return (length == capacity - 1);
}

bool Expression::isEmpty() {

	return length == 0;
}

void Expression::addToken(Token& token) {

	if (isFull())
		extendArray();

	this->exp[length++] = token;
}

int Expression::getLength() {

	return length;
}

Token Expression::getToken(const int index) {

	try {

		if (index < 0 && length <= index)
			throw ExceptionOutOfIndex();

		return exp[index];
	}

	catch (ExceptionOutOfIndex e) {
		e.printErrorMsg();
	}
}

void Expression::extendArray() {

	Token *temp = new Token[capacity + 10];

	for (int i = 0; i < capacity; ++i)
		temp[i] = exp[i];

	delete[] exp;

	exp = temp;

	capacity = capacity + 10;
}