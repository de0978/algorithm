#ifndef TREENODE
#define TREENODE

#include <iostream>
using namespace std;

template < class T >
class TreeNode {

private:

	/* Member variable */

	T data;				// 가지고 있는 데이터
	TreeNode *leftChild;	// 왼쪽 자식 포인터
	TreeNode *rightChild;	// 오른쪽 자식 포인터

public:

	/*
	* 함수 이름 : TreeNode
	* 반환 타입 : X
	* 매개 변수 : T, TreeNode<T> * defualt NULL, TreeNode<T> * defualt NULL
	* 함수 기능 : 생성자
	*/
	TreeNode(T& data, TreeNode<T> *left = NULL, TreeNode<T> *right = NULL);

	/*
	* 함수 이름 : ~TreeNode
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 소멸자
	*/
	~TreeNode();

	/*
	* 함수 이름 : getData
	* 반환 타입 : T
	* 매개 변수 : X
	* 함수 기능 : data 반환
	*/
	T getData() const;

	/*
	* 함수 이름 : getLeftChild
	* 반환 타입 : TreeNode<T> *
	* 매개 변수 : X
	* 함수 기능 : 왼쪽 자식 포인터 반환
	*/
	TreeNode<T> *getLeftChild() const;

	/*
	* 함수 이름 : getRightChild
	* 반환 타입 : TreeNode<T> *
	* 매개 변수 : X
	* 함수 기능 : 오른쪽 자식 포인터 반환
	*/
	TreeNode<T> *getRightChild() const;

	/*
	* 함수 이름 : makeLeftChild
	* 반환 타입 : void
	* 매개 변수 : T
	* 함수 기능 : 왼쪽 자식 동적 메모리 할당
	*/
	void makeLeftChild(T& data) { leftChild = new TreeNode<T>(data); }

	/*
	* 함수 이름 : makeRightChild
	* 반환 타입 : void
	* 매개 변수 : T
	* 함수 기능 : 오른쪽 자식 동적 메모리 할당
	*/
	void makeRightChild(T& data) { rightChild = new TreeNode<T>(data); }


	bool operator<(const T& data) { return this->data < data; }
	bool operator>(const T& data) { return this->data > data; }
	bool operator==(const T& data) { return this->data == data; }
};

template < class T >
TreeNode<T>::TreeNode(T& data, TreeNode<T> *left, TreeNode<T> *right) {

	this->data = data;
	this->leftChild = left;
	this->rightChild = right;

}

template < class T >
TreeNode<T>::~TreeNode() {

	data.~T();
	if (leftChild) delete leftChild;
	if (rightChild) delete rightChild;

}

template < class T >
T TreeNode<T>::getData() const {

	return data;
}

template < class T >
TreeNode<T>* TreeNode<T>::getLeftChild() const {

	return leftChild;
}

template < class T >
TreeNode<T>* TreeNode<T>::getRightChild() const {

	return rightChild;
}

#endif