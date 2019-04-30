#ifndef __TASKMANAGER_H__
#define __TASKMANAGER_H__

#include "BST.h"
#include "IOHandler.h"

typedef enum { INSERT = '1', PRINT_TREE, EXIT } MENU;

template < class T >
class TaskManager {

private:

	/*
	* 함수 이름 : insertData
	* 반환 타입 : X
	* 매개 변수 : Tree<T>&
	* 함수 기능 : insertData
	*/
	void insertData(BST<T>& tree);

public:

	TaskManager() { }

	~TaskManager() { }

};

template < class T >
void TaskManager<T>::insertData(BST<T>& tree) {

	tree.addData(ioh.insertData());
}



#endif