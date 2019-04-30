#ifndef __TASKMANAGER_H__
#define __TASKMANAGER_H__

#include "IOHandler.h"
#include "ExpressionConvertor.h"
#include "TreeCalculator.h"

class TaskManager {

private:

	IOHandler ioh; // 있는게 더 효율적이지 않을까 ..?


public:

	TaskManager() { }

	~TaskManager() { }

	/*
	* 함수 이름 : guideMainMenu
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 프로그램 가이드..?
	*/
	void guideMainMenu();

};


#endif