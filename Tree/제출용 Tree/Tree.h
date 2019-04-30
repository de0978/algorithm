#ifndef TREE
#define TREE


#include"TreeNode.h"
#include"CircleQueue.h"
#include <iomanip>
using namespace std;

template < class T >
class Tree {

private:

	/* Member var */

	TreeNode<T> *rootNode;   // rootNode

	/*
	* �Լ� �̸� : printTreeByInorder
	* ��ȯ Ÿ�� : void
	* �Ű� ���� : const TreeNode<T> *
	* �Լ� ��� : Ʈ���� ���� ��ȸ ������� Ž��
	*/
	void printTreeByInorder(const TreeNode<T>* nextNode) const;
	
	/*
	* �Լ� �̸� : printTreeByPreorder
	* ��ȯ Ÿ�� : void
	* �Ű� ���� : const TreeNode<T> *
	* �Լ� ��� : Ʈ���� ���� ��ȸ ������� Ž��
	*/
	void printTreeByPreorder(const TreeNode<T>* nextNode) const;
	
	/*
	* �Լ� �̸� : printTreeByPostorder
	* ��ȯ Ÿ�� : void
	* �Ű� ���� : const TreeNode<T> *
	* �Լ� ��� : Ʈ���� ���� ��ȸ ������� Ž��
	*/
	void printTreeByPostorder(const TreeNode<T>* nextNode) const;

	/*
	* �Լ� �̸� : printTree
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : int, const TreeNode<T> *
	* �Լ� ��� : Ʈ�� ������� Ʈ�� ���
	*/
	void printTree(int length, char ch,const TreeNode<T> *nextNode) const;

public:

	/* Constructor */

	/*
	* �Լ� �̸� : Tree
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : rootNode�� NULL�� �ʱ�ȭ
	*/
	Tree();

	/*
	* �Լ� �̸� : Tree
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : const T&
	* �Լ� ��� : rootNode �� �޸𸮸� �ٷ� �Ҵ�
	*/
	Tree(const T& data);

	/* Destroyer */

	/*
	* �Լ� �̸� : ~Tree
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : rootNode ���� �޸� ����
	*/
	~Tree();

	/* Member Function */
	
	/*
	* �Լ� �̸� : addNode
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : const T&
	* �Լ� ��� : �ڽ� ��带 �߰��Ѵ�.
	*/
	void addNode(const T& data);

	/*
	* �Լ� �̸� : printTreeByInorder
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : Ʈ�� ���� ��ȸ
	*/
	void printTreeByInorder() const;

	/*
	* �Լ� �̸� : printTreeByPreorder
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : Ʈ�� ���� ��ȸ
	*/
	void printTreeByPreorder() const;

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
	* �Լ� �̸� : printTree
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : Ʈ�� ������� Ʈ�� ���
	*/
	void printTree() const;

	/*
	* �Լ� �̸� : getMaxLevel
	* ��ȯ Ÿ�� : int
	* �Ű� ���� : X
	* �Լ� ��� : �ִ� ���� Ž��
	*/
	int getMaxLevel() const;
	
};

template < class T >
Tree<T>::Tree() {}

template < class T >
Tree<T>::Tree(const T& data) {

	rootNode = new TreeNode<T>(data);
}

template < class T >
Tree<T>::~Tree() {

	delete rootNode;
}

template < class T >
void Tree<T>::addNode(const T& data){

	if (!rootNode) {
		rootNode = new TreeNode<T>(data);
		return;
	}

	// level order�� ���� �� �ڸ� ã��

	CircleQueue<T> levelOrder;

	TreeNode<T> *blankFinder = rootNode;

	while (1) {

		if (!blankFinder->getLeftChild()) { // ���� �ڽ� ����
			blankFinder->makeLeftChild(data);
			break;
		}

		else if (!blankFinder->getRightChild()) { // ������ �ڽ� ����
			blankFinder->makeRightChild(data);
			break;
		}

		// �� �� �� �� ��� ( null pointer �� ���� �ʴ� ���� )
		levelOrder.push(blankFinder->getLeftChild());
		levelOrder.push(blankFinder->getRightChild());

		blankFinder = levelOrder.getNode();
	}
}

template < class T >
void Tree<T>::printTreeByInorder() const {

	printTreeByInorder(rootNode);
}

template < class T >
void Tree<T>::printTreeByInorder(const TreeNode<T>* nextNode) const { // ���� ��ȸ

	if (!nextNode)
		return;

	printTreeByInorder(nextNode->getLeftChild()); // �������� �� ~
	cout << nextNode->getData() << " "; // ������ ���
	printTreeByInorder(nextNode->getRightChild()); // ���������� �� ~

}

template < class T >
void Tree<T>::printTreeByPostorder() const {

	printTreeByPostorder(rootNode);
}

template < class T >
void Tree<T>::printTreeByPostorder(const TreeNode<T>* nextNode) const { // ���� ��ȸ

	if (!nextNode)
		return;

	printTreeByPostorder(nextNode->getLeftChild());  // ��
	printTreeByPostorder(nextNode->getRightChild()); // ��
	cout << nextNode->getData() << " ";			 // ������ ���
}

template < class T >
void Tree<T>::printTreeByPreorder() const {

	printTreeByPreorder(rootNode);
}

template < class T >
void Tree<T>::printTreeByPreorder(const TreeNode<T>* nextNode) const { // ���� ��ȸ

	if (!nextNode)
		return;

	cout << nextNode->getData() << " ";
	printTreeByPreorder(nextNode->getLeftChild());
	printTreeByPreorder(nextNode->getRightChild());
}

template < class T >
void Tree<T>::printTreeByLevelorder() const { // �ܰ� ��ȸ

	CircleQueue<T> levelOrder;

	TreeNode<T> *orderPtr = rootNode;

	while (orderPtr) {

		cout << orderPtr->getData() << " ";

		if (orderPtr->getLeftChild()) // ���� �ڽ��� ������ �ֱ�
			levelOrder.push(orderPtr->getLeftChild());

		if (orderPtr->getRightChild()) // ������ �ڽ��� ������ �ֱ�
			levelOrder.push(orderPtr->getRightChild());

		orderPtr = levelOrder.getNode();
	}
}

template < class T >
void Tree<T>::printTree() const {

	printTree(0, '-',rootNode);
}

template < class T >
void Tree<T>::printTree(int length, char ch, const TreeNode<T> *nextNode) const {

	if (!nextNode)
		return;
	
	printTree(length + 15, 1,nextNode->getRightChild());
	cout << setw(length) << ch << "---" <<nextNode->getData() << endl;
	printTree(length + 15, 3,nextNode->getLeftChild());

}

template < class T >
int Tree<T>::getMaxLevel() const {

	int level = 0;

	TreeNode<T> *maxFinder = rootNode;

	while (maxFinder) {

		if (maxFinder->getLeftChild()) 
			++level;
			
		maxFinder = maxFinder->getLeftChild();
	}

	return level;
}

#endif