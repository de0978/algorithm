#ifndef __TREE_H__
#define __TREE_H_

#include<iostream>
#include<iomanip>
using namespace std;

template < class T >
class Tree {

private:

	int index;       // ���� ����Ű�� �ִ� �ε���
	int capacity;	 // �迭 �뷮
	int nodeCount;   // ��� ��
	T* nodeArr;      // T Ÿ�� ������


	/*
	* �Լ� �̸� : printTree
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : int, int
	* �Լ� ��� : Ʈ�� ������� ���
	*/
	void printTree(const int nextIndex, char ch, const int length) const;
	
	/*
	* �Լ� �̸� : printTreeByPreorder
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : int
	* �Լ� ��� : Ʈ�� ���� ��ȸ
	*/
	void printTreeByPreorder(const int nextIndex) const;

	/*
	* �Լ� �̸� : printTreeByInorder
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : int
	* �Լ� ��� : Ʈ�� ���� ��ȸ
	*/
	void printTreeByInorder(const int nextIndex) const;

	/*
	* �Լ� �̸� : printTreeByPostorder
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : int
	* �Լ� ��� : Ʈ�� ���� ��ȸ
	*/
	void printTreeByPostorder(const int nextIndex) const;

public:

	/*
	* �Լ� �̸� : Tree
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : ������.
	*/
	Tree(int capacity = 10);

	/*
	* �Լ� �̸� : ~Tree
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : �Ҹ���
	*/
	~Tree();

	/*
	* �Լ� �̸� : isFull
	* ��ȯ Ÿ�� : bool
	* �Ű� ���� : X
	* �Լ� ��� : �迭�� �� á���� Ȯ��
	*/
	bool isFull() const;

	/*
	* �Լ� �̸� : isEmpty
	* ��ȯ Ÿ�� : bool
	* �Ű� ���� : X
	* �Լ� ��� : �迭�� ������� Ȯ��
	*/
	bool isEmpty() const;

	/*
	* �Լ� �̸� : push
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : T
	* �Լ� ��� : ������ ����
	*/
	void push(const T& data);

	/*
	* �Լ� �̸� : printTree
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : Ʈ�� ���
	*/
	void printTree() const;

	/*
	* �Լ� �̸� : printTreeByPreorder
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : Ʈ�� ���� ��ȸ
	*/
	void printTreeByPreorder() const;

	/*
	* �Լ� �̸� : printTreeByInorder
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : Ʈ�� ���� ��ȸ
	*/
	void printTreeByInorder() const;

	/*
	* �Լ� �̸� : printTreeByPostorder
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : Ʈ�� ���� ��ȸ
	*/
	void printTreeByPostorder() const;

	/*
	* �Լ� �̸� : printTreeByLevelorder
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : Ʈ�� ���� ��ȸ
	*/
	void printTreeByLevelorder() const;

	/*
	* �Լ� �̸� : extendArray
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : �迭 ũ�� ����
	*/
	void extendArray();
	
};



template < class T >
Tree<T>::Tree(int capacity) {

	if (capacity <= 0) {
		cout << " ������ �߸��� " << endl;
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
		cout << " �� Ʈ�� " << endl;

	else  {
		cout << " [ �� ��� �� ] : " << nodeCount << endl;
		printTree(1,'��' , 0);
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