#ifndef __TASKMANAGER_H__
#define __TASKMANAGER_H__

#include "BST.h"
#include "IOHandler.h"

typedef enum { INSERT = '1', PRINT_TREE, EXIT } MENU;

template < class T >
class TaskManager {

private:

	/*
	* �Լ� �̸� : insertData
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : Tree<T>&
	* �Լ� ��� : insertData
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