#ifndef TREENODE
#define TREENODE

#include <iostream>
using namespace std;

template < class T >
class TreeNode {

private:

	/* Member variable */

	T data;				// ������ �ִ� ������
	TreeNode *leftChild;	// ���� �ڽ� ������
	TreeNode *rightChild;	// ������ �ڽ� ������

public:

	/*
	* �Լ� �̸� : TreeNode
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : T, TreeNode<T> * defualt NULL, TreeNode<T> * defualt NULL
	* �Լ� ��� : ������
	*/
	TreeNode(T& data, TreeNode<T> *left = NULL, TreeNode<T> *right = NULL);

	/*
	* �Լ� �̸� : ~TreeNode
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : �Ҹ���
	*/
	~TreeNode();

	/*
	* �Լ� �̸� : getData
	* ��ȯ Ÿ�� : T
	* �Ű� ���� : X
	* �Լ� ��� : data ��ȯ
	*/
	T getData() const;

	/*
	* �Լ� �̸� : getLeftChild
	* ��ȯ Ÿ�� : TreeNode<T> *
	* �Ű� ���� : X
	* �Լ� ��� : ���� �ڽ� ������ ��ȯ
	*/
	TreeNode<T> *getLeftChild() const;

	/*
	* �Լ� �̸� : getRightChild
	* ��ȯ Ÿ�� : TreeNode<T> *
	* �Ű� ���� : X
	* �Լ� ��� : ������ �ڽ� ������ ��ȯ
	*/
	TreeNode<T> *getRightChild() const;

	/*
	* �Լ� �̸� : makeLeftChild
	* ��ȯ Ÿ�� : void
	* �Ű� ���� : T
	* �Լ� ��� : ���� �ڽ� ���� �޸� �Ҵ�
	*/
	void makeLeftChild(T& data) { leftChild = new TreeNode<T>(data); }

	/*
	* �Լ� �̸� : makeRightChild
	* ��ȯ Ÿ�� : void
	* �Ű� ���� : T
	* �Լ� ��� : ������ �ڽ� ���� �޸� �Ҵ�
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