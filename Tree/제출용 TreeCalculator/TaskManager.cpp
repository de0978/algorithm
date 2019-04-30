#include "TaskManager.h"

void TaskManager::guideMainMenu() {

	ExpressionConvertor expConvertor;;

	TreeCalculator calculator;

	string exp;

	try {

		while (1) {

			exp = ioh.insertExp(); // �� �Է�

			if (exp == "EXIT") break;

			Expression postfixedExp = expConvertor.postfix(exp); // ���� ����

			calculator.compute(postfixedExp); // ���

			ioh.insertString("\n");
		}
	}

	catch (Exception e) {
		e.printErrorMsg();
	}
	
}
