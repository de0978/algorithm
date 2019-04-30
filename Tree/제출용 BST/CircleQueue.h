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

	TreeNode<T> **dataArr;   //  TreeNode * 저장할 동적 할당
	int capacity;		  //  TreeNode 길이
	int front;			  //  다음에 나갈 데이터 인덱스
	int rear;			  //  다음에 저장될 공간 인덱스

public:

	/* Constructor */

	/*
	* 함수 이름 : CircleQueue
	* 반환 타입 : X
	* 매개 변수 : T, default value = 10;
	* 함수 기능 : TreeNode의 길이를 capacity 만큼 할당. 멤버 변수들 초기화
	*/
	CircleQueue(int capacity = 10);


	/* Destroyer */

	/*
	* 함수 이름 : ~CircleQueue
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 할당된 TreeNode 동적 메모리 회수
	*/
	~CircleQueue();

	/* Member Function */

	/*
	* 함수 이름 : isFull
	* 반환 타입 : bool
	* 매개 변수 : X
	* 함수 기능 : 꽉찬 원형 큐인지 확인
	*/
	bool isFull();



	/*
	* 함수 이름 : isEmpty
	* 반환 타입 : bool
	* 매개 변수 : X
	* 함수 기능 : 비어있는 원형 큐인지 확인
	*/
	bool isEmpty();



	/*
	* 함수 이름 : push
	* 반환 타입 : void
	* 매개 변수 : TreeNode<T> *
	* 함수 기능 :
	*/
	void push(TreeNode<T>* nextData);



	/*
	* 함수 이름 : getNode
	* 반환 타입 : TreeNode<T> *
	* 매개 변수 : X
	* 함수 기능 : 순서대로 데이터를 반환
	*/
	TreeNode<T>* getNode();

	/*
	* 함수 이름 : extendArray
	* 반환 타입 : void
	* 매개 변수 : X
	* 함수 기능 : 배열 길이를 + 5만큼 확장
	*/
	void extendArray();
};

template < class T >
CircleQueue<T>::CircleQueue(int capacity) {

	if (capacity <= 0) {
		cout << " 배열 범위가 잘못됨 " << endl;
		exit(1);
	}

	this->capacity = capacity;
	front = rear = 1;
	dataArr = new TreeNode<T>*[capacity];

}

template < class T >
CircleQueue<T>::~CircleQueue() {

	delete[] dataArr; // 각 배열에 대해서 할당해주지 않았기 때문에
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