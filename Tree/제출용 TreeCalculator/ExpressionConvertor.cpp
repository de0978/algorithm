#include "ExpressionConvertor.h"

int ExpressionConvertor::ICP(const char ch) {

	switch (ch) {

	case '(':
		return 0;

	case '~':
		return 1;

	case '^':
		return 2;

	case '*':
	case '/':
	case '%':
		return 3;

	case '+':
	case '-':
		return 4;

	default:
		return -1;
	}
}


int ExpressionConvertor::ISP(const char ch) {

	switch (ch) {

	case '~':
		return 1;

	case '^':
		return 2;

	case '*':
	case '/':
	case '%':
		return 3;

	case '+':
	case '-':
		return 4;

	case '(':
	case '#':
		return 5;

	case ')': // 임시방편..
		return 6;

	default:
		return -1;
	}
}

void ExpressionConvertor::checkSingleMinus(Expression& exp) {

	int len = exp.getLength()-1;

	if (exp[0].getOperator() == '-')
		exp[0].setOperator('~');

	for (int i = 0; i < len; ++i) {
		
		int temp = ICP(exp[i].getOperator());

		if (exp[i].getOperator() == '-' || ( 0 <= temp && temp <= 1)) {
		
			if (exp[i+1].getOperator() == '-')
				exp[i+1].setOperator('~');
		}
	}
}

void ExpressionConvertor::strToExpression(Expression& tokenExp,string exp) {

	int len = exp.length();

	string num;

	for (int i = 0; i < len; ++i) {

		if ('0' <= exp[i] && exp[i] <= '9')
			num = num + exp[i];

		else {

			if (num != "") {
				tokenExp.addToken(Token(atoi(num.c_str())));
				num = "";
			}

			if(0 <= ISP(exp[i]))
				tokenExp.addToken(Token(exp[i]));
		}
	}

	if (num != "")
		tokenExp.addToken(Token(atoi(num.c_str())));
}


bool ExpressionConvertor::filterExpression(Expression& exp) {

	int len = exp.getLength();

	int total = 0, i;

	// 1. 이상한 문자 입력
	for (i = 0; i < len; ++i) {

		if (exp[i].getIsOperator()) {
			// 이상한 문자인 경우
			if(ISP(exp[i].getOperator()) == -1)
				return false;

			if (exp[i].getOperator() == '(')
				++total;

			else if (exp[i].getOperator() == ')')
				--total;
		}
	}

	// 2. 괄호 수가 안맞을때
	if (total != 0)
		return false;

	len = len - 1;

	for (i = 0; i < len; ++i) {

		// 3. 숫자 연속 입력 3 80 + 32 와 같은 경우
		if (!(exp[i].getIsOperator() || exp[i+1].getIsOperator()))
			return false;

		// 4. 연산자 두개가 다  2 <= ICP 인 경우
		if (exp[i].getIsOperator() && exp[i + 1].getIsOperator()) {

			// +*,+/ 와 같은 경우
			if (2 <= ICP(exp[i].getOperator()) && 2 <= ICP(exp[i + 1].getOperator()))
				return false;

			// (+, (* 와 같은 경우
			else if (exp[i].getOperator() == '(' && 2 <= ICP(exp[i + 1].getOperator()))
				return false;
			// +), *), /)와 같은 경우
			else if (2 <= ICP(exp[i].getOperator()) && exp[i+1].getOperator() == ')')
				return false;
		}
		// 5. 3(12) 이런 경우
		if ((!exp[i].getIsOperator()) && exp[i + 1].getOperator() == '(')
			return false;

	}

	return true;
}

Expression ExpressionConvertor::postfix(string exp) {

	Expression temp;
	
	strToExpression(temp,exp);

	Expression postfix;

	checkSingleMinus(temp);

	try {

		if (!filterExpression(temp)) // 이상한 식
			throw Exception();

		stack<Token> tokenStack;

		tokenStack.push(Token('#'));

		int len = temp.getLength();

		for (int i = 0; i < len; ++i) {

			// 피연산자일경우
			if (!temp[i].getIsOperator())
				postfix.addToken(temp[i]);

			else {

				// 닫는 괄호
				if (temp[i].getOperator() == ')') {
					
					for (; tokenStack.top().getOperator() != '('; tokenStack.pop()) 
						postfix.addToken(tokenStack.top());
					
					tokenStack.pop();
				}

				// 단항 마이너스
				else if (temp[i].getOperator() == '~')
					tokenStack.push(temp[i]);

				// 나머지
				else {

					if (ICP(temp[i].getOperator()) < ISP(tokenStack.top().getOperator()))
						tokenStack.push(temp[i]);

					else {

						for (; ISP(tokenStack.top().getOperator()) <= ICP(temp[i].getOperator()); tokenStack.pop())
							postfix.addToken(tokenStack.top());

						tokenStack.push(temp[i].getOperator());
					}
				}
			}
		}

		for (; tokenStack.top().getOperator() != '#'; tokenStack.pop())
			postfix.addToken(tokenStack.top());
	}

	catch (Exception e) {
		throw e;
	}

	return postfix;
}