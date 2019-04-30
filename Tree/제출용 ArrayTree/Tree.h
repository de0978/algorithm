#ifndef __TREE_H__
#define __TREE_H_

#include<iostream>
#include<iomanip>
using namespace std;

template < class T >
class Tree {

private:

	int index;       // 현재 가르키고 있는 인덱스
	int capacity;	 // 배열 용량
	int nodeCount;   // 노드 수
	T* nodeArr;      // T 타입 포인터


	/*
	* 함수 이름 : printTree
	* 반환 타입 : X
	* 매개 변수 : int, int
	* 함수 기능 : 트리 모양으로 출력
	*/
	void printTree(const int nextIndex, char ch, const int length) const;
	
	/*
	* 함수 이름 : printTreeByPreorder
	* 반환 타입 : X
	* 매개 변수 : int
	* 함수 기능 : 트리 전위 순회
	*/
	void printTreeByPreorder(const int nextIndex) const;

	/*
	* 함수 이름 : printTreeByInorder
	* 반환 타입 : X
	* 매개 변수 : int
	* 함수 기능 : 트리 중위 순회
	*/
	void printTreeByInorder(const int nextIndex) const;

	/*
	* 함수 이름 : printTreeByPostorder
	* 반환 타입 : X
	* 매개 변수 : int
	* 함수 기능 : 트리 중위 순회
	*/
	void printTreeByPostorder(const int nextIndex) const;

public:

	/*
	* 함수 이름 : Tree
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 생성자.
	*/
	Tree(int capacity = 10);

	/*
	* 함수 이름 : ~Tree
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 소멸자
	*/
	~Tree();

	/*
	* 함수 이름 : isFull
	* 반환 타입 : bool
	* 매개 변수 : X
	* 함수 기능 : 배열이 꽉 찼는지 확인
	*/
	bool isFull() const;

	/*
	* 함수 이름 : isEmpty
	* 반환 타입 : bool
	* 매개 변수 : X
	* 함수 기능 : 배열이 비었는지 확인
	*/
	bool isEmpty() const;

	/*
	* 함수 이름 : push
	* 반환 타입 : X
	* 매개 변수 : T
	* 함수 기능 : 데이터 삽입
	*/
	void push(const T& data);

	/*
	* 함수 이름 : printTree
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 트리 출력
	*/
	void printTree() const;

	/*
	* 함수 이름 : printTreeByPreorder
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 트리 전위 순회
	*/
	void printTreeByPreorder() const;

	/*
	* 함수 이름 : printTreeByInorder
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 트리 중위 순회
	*/
	void printTreeByInorder() const;

	/*
	* 함수 이름 : printTreeByPostorder
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 트리 후위 순회
	*/
	void printTreeByPostorder() const;

	/*
	* 함수 이름 : printTreeByLevelorder
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 트리 레벨 순회
	*/
	void printTreeByLevelorder() const;

	/*
	* 함수 이름 : extendArray
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 배열 크기 증가
	*/
	void extendArray();
	
};



template < class T >
Tree<T>::Tree(int capacity) {

	if (capacity <= 0) {
		cout << " 범위가 잘못됨 " << endl;
		exit(1);
	}

	nodeCount = 0;
	this->capacity = capacity;
	index = 1;

	nodeArr = new T[capacity];
}

template < class T >
Tree<T>::~Tree() {

	for (int i = 0; i < index; ++i)
		if (nodeArr[i])
			nodeArr[i].~T();

	delete[] nodeArr;
}

template < class T >
bool Tree<T>::isFull() const {

	return index == capacity - 1;
}

template < class T >
bool Tree<T>::isEmpty() const {

	return index == 1;
}

template < class T >
void Tree<T>::push(const T& data) {

	if (isFull())
		extendArray();

	nodeArr[index++] = data;
	nodeCount++;
}

template < class T >
void Tree<T>::extendArray() {

	T *tempArr = new T[capacity + 5];

	for (int i = 1; i < capacity; ++i)
		tempArr[i] = nodeArr[i];
	
	delete[] nodeArr;

	nodeArr = tempArr;

	capacity = capacity + 5;
}

template < class T >
void Tree<T>::printTree() const{

	if (isEmpty())
		cout << " 빈 트리 " << endl;

	else  {
		cout << " [ 총 노드 수 ] : " << nodeCount << endl;
		printTree(1,'ㅁ' , 0);
	}
}

template < class T >
void Tree<T>::printTree(const int nextIndex, char ch, const int length) const {

	if (index <= nextIndex)
		return;

	printTree(nextIndex * 2 + 1, 1,length + 15);
	cout << setw(length + 15) << ch << "----" << nodeArr[nextIndex] << endl;
	printTree(nextIndex * 2, 3,length + 15);
}


template < class T >
void Tree<T>::printTreeByPreorder() const{

	printTreeByPreorder(1);
}

template < class T >
void Tree<T>::printTreeByPreorder(const int nextIndex) const{

	if (index <= nextIndex)
		return;

	cout << nodeArr[nextIndex] << " ";
	printTreeByPreorder(nextIndex * 2);
	printTreeByPreorder(nextIndex * 2 + 1);
}

template < class T >
void Tree<T>::printTreeByInorder() const {
	
	printTreeByInorder(1);
}

template < class T >
void Tree<T>::printTreeByInorder(const int nextIndex) const {

	if (index <= nextIndex)
		return;

	printTreeByInorder(nextIndex * 2);
	cout << nodeArr[nextIndex] << " ";
	printTreeByInorder(nextIndex * 2 + 1);
}

template < class T >
void Tree<T>::printTreeByPostorder() const{
	
	printTreeByPostorder(1);
}

template < class T >
void Tree<T>::printTreeByPostorder(const int nextIndex) const{

	if (index <= nextIndex)
		return;

	printTreeByPostorder(nextIndex * 2);
	printTreeByPostorder(nextIndex * 2 + 1);
	cout << nodeArr[nextIndex] << " ";
}

template < class T >
void Tree<T>::printTreeByLevelorder() const{

	for (int i = 1; i < index; ++i)
		cout << nodeArr[i] << " ";

}

#endif