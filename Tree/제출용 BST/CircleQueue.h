#ifndef CIRCLEQUEUE
#define CIRCLEQUEUE

#include <iostream>
#include "TreeNode.h"
#include "ExceptionEmpty.h"

using namespace std;

template < class T >
class CircleQueue {

private:

	/* Member variable */

	TreeNode<T> **dataArr;   //  TreeNode * ������ ���� �Ҵ�
	int capacity;		  //  TreeNode ����
	int front;			  //  ������ ���� ������ �ε���
	int rear;			  //  ������ ����� ���� �ε���

public:

	/* Constructor */

	/*
	* �Լ� �̸� : CircleQueue
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : T, default value = 10;
	* �Լ� ��� : TreeNode�� ���̸� capacity ��ŭ �Ҵ�. ��� ������ �ʱ�ȭ
	*/
	CircleQueue(int capacity = 10);


	/* Destroyer */

	/*
	* �Լ� �̸� : ~CircleQueue
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : �Ҵ�� TreeNode ���� �޸� ȸ��
	*/
	~CircleQueue();

	/* Member Function */

	/*
	* �Լ� �̸� : isFull
	* ��ȯ Ÿ�� : bool
	* �Ű� ���� : X
	* �Լ� ��� : ���� ���� ť���� Ȯ��
	*/
	bool isFull();



	/*
	* �Լ� �̸� : isEmpty
	* ��ȯ Ÿ�� : bool
	* �Ű� ���� : X
	* �Լ� ��� : ����ִ� ���� ť���� Ȯ��
	*/
	bool isEmpty();



	/*
	* �Լ� �̸� : push
	* ��ȯ Ÿ�� : void
	* �Ű� ���� : TreeNode<T> *
	* �Լ� ��� :
	*/
	void push(TreeNode<T>* nextData);



	/*
	* �Լ� �̸� : getNode
	* ��ȯ Ÿ�� : TreeNode<T> *
	* �Ű� ���� : X
	* �Լ� ��� : ������� �����͸� ��ȯ
	*/
	TreeNode<T>* getNode();

	/*
	* �Լ� �̸� : extendArray
	* ��ȯ Ÿ�� : void
	* �Ű� ���� : X
	* �Լ� ��� : �迭 ���̸� + 5��ŭ Ȯ��
	*/
	void extendArray();
};

template < class T >
CircleQueue<T>::CircleQueue(int capacity) {

	if (capacity <= 0) {
		cout << " �迭 ������ �߸��� " << endl;
		exit(1);
	}

	this->capacity = capacity;
	front = rear = 1;
	dataArr = new TreeNode<T>*[capacity];

}

template < class T >
CircleQueue<T>::~CircleQueue() {

	delete[] dataArr; // �� �迭�� ���ؼ� �Ҵ������� �ʾұ� ������
}

template < class T >
bool CircleQueue<T>::isFull() {

	return (front - rear%capacity == 1);
}

template < class T >
bool CircleQueue<T>::isEmpty() {

	return (front - rear == 0);
}

template < class T >
void CircleQueue<T>::push(TreeNode<T> *nextData) {

	if (isFull())
		extendArray();

	dataArr[rear++%capacity] = nextData;
}

template < class T >
void CircleQueue<T>::extendArray() {

	TreeNode<T> **tempArr = new TreeNode<T>*[capacity + 5];

	for (int i = 1; front < rear; ++i, ++front)
		tempArr[i] = dataArr[front%capacity];

	delete dataArr;

	dataArr = tempArr;

	front = 1;
	rear = capacity;

	capacity = capacity + 5;
}

template < class T >
TreeNode<T>* CircleQueue<T>::getNode() {

	try {

		if (isEmpty())
			throw ExceptionEmpty();

		return dataArr[front++%capacity];
	}

	catch (ExceptionEmpty e) {
		e.printErrorMsg();
	}

	return NULL;
}
#endif