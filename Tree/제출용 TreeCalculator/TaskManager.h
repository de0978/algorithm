#ifndef __TASKMANAGER_H__
#define __TASKMANAGER_H__

#include "IOHandler.h"
#include "ExpressionConvertor.h"
#include "TreeCalculator.h"

class TaskManager {

private:

	IOHandler ioh; // �ִ°� �� ȿ�������� ������ ..?


public:

	TaskManager() { }

	~TaskManager() { }

	/*
	* �Լ� �̸� : guideMainMenu
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : ���α׷� ���̵�..?
	*/
	void guideMainMenu();

};


#endif