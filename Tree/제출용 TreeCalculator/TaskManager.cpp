#include "TaskManager.h"

void TaskManager::guideMainMenu() {

	ExpressionConvertor expConvertor;;

	TreeCalculator calculator;

	string exp;

	try {

		while (1) {

			exp = ioh.insertExp(); // 식 입력

			if (exp == "EXIT") break;

			Expression postfixedExp = expConvertor.postfix(exp); // 후위 연산

			calculator.compute(postfixedExp); // 계산

			ioh.insertString("\n");
		}
	}

	catch (Exception e) {
		e.printErrorMsg();
	}
	
}
