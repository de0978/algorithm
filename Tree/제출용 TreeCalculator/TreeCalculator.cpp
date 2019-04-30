#include "TreeCalculator.h"

TreeCalculator::TreeCalculator() {

}

TreeCalculator::~TreeCalculator() {

}

void TreeCalculator::compute(Expression& exp) {

	stack<TokenNode*> tokenStack;

	TokenNode *tempNode1 = NULL, *tempNode2 = NULL;

	int len = exp.getLength();

	int result = 0;
	
	for (int i = 0; i < len; ++i) {

		if (!exp[i].getIsOperator())
			tokenStack.push(new TokenNode(exp[i]));

		else {

			switch (exp[i].getOperator()) {

			case '~':

				tempNode1 = tokenStack.top(); // 7 토큰
				tokenStack.pop();
				tokenStack.push(new TokenNode(Token(-tempNode1->getToken().getOperand(), '~'), tempNode1));
				break;

			case '%':

				tempNode1 = tokenStack.top();
				tokenStack.pop();

				tempNode2 = tokenStack.top();
				tokenStack.pop();

				if (tempNode1->getToken().getOperand() == 0) {
					cout << " [ 분모  0 ] " << endl;
					return;
				}
				result = tempNode2->getToken().getOperand() % tempNode1->getToken().getOperand();

				tokenStack.push(new TokenNode(Token(result, '%'), tempNode1, tempNode2));

				break;

			case '/':

				tempNode1 = tokenStack.top();
				tokenStack.pop();

				tempNode2 = tokenStack.top();
				tokenStack.pop();

				if (tempNode1->getToken().getOperand() == 0) {
					cout << " [ 분모  0 ] " << endl;
					return;
				}
				result = tempNode2->getToken().getOperand() / tempNode1->getToken().getOperand();

				tokenStack.push(new TokenNode(Token(result, '/'), tempNode1, tempNode2));

				break;

			case '^':

				tempNode1 = tokenStack.top();
				tokenStack.pop();

				tempNode2 = tokenStack.top();
				tokenStack.pop();

				result = (int)pow(tempNode2->getToken().getOperand(), tempNode1->getToken().getOperand());

				tokenStack.push(new TokenNode(Token(result, '^'), tempNode1, tempNode2));

				break;

			case '-':

				tempNode1 = tokenStack.top();
				tokenStack.pop();

				tempNode2 = tokenStack.top();
				tokenStack.pop();

				result = tempNode2->getToken().getOperand() - tempNode1->getToken().getOperand();

				tokenStack.push(new TokenNode(Token(result, '-'), tempNode1, tempNode2));
				break;

			case '+':

				tempNode1 = tokenStack.top();
				tokenStack.pop();

				tempNode2 = tokenStack.top();
				tokenStack.pop();

				result = tempNode1->getToken().getOperand() + tempNode2->getToken().getOperand();

				tokenStack.push(new TokenNode(Token(result, '+'), tempNode1, tempNode2));
				break;

			case '*':

				tempNode1 = tokenStack.top();
				tokenStack.pop();

				tempNode2 = tokenStack.top();
				tokenStack.pop();

				result = tempNode1->getToken().getOperand() * tempNode2->getToken().getOperand();

				tokenStack.push(new TokenNode(Token(result, '*'), tempNode1, tempNode2));
				break;
			}
		}
	}

	cout << " [ 후위 연산식 ] : ";
	exp.test();
	cout << endl;

	printComputeProcess(tokenStack.top());
}

void TreeCalculator::printComputeProcess(TokenNode *rootNode, int len) {
	
	if (!rootNode)
		return;

	printComputeProcess(rootNode->getRightChild(), len + 15);
	cout << setw(len) << rootNode->getToken().getOperator() << '(' << rootNode->getToken().getOperand() << ") " << endl;
	printComputeProcess(rootNode->getLeftChild(), len + 15);
}
