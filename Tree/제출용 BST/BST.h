#ifndef __BST__
#define __BST__

#include <iomanip>
#include "CircleQueue.h"
#include "TreeNode.h"
#include "ExceptionExistData.h"

using namespace std;
 

template < class T >
class BST {

private:

	TreeNode<T> *rootNode;

	/*
	* �Լ� �̸� : printTree
	* ��ȯ Ÿ�� : void
	* �Ű� ���� : X
	* �Լ� ��� : BST�� ���
	*/
	void printBST(const int length, const TreeNode<T> *nextNode) const ;

public:


	/*
	* �Լ� �̸� : BST
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : ������
	*/
	BST() { rootNode = NULL;  }

	/*
	* �Լ� �̸� : BST
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : T
	* �Լ� ��� : ������
	*/
	BST(T& data) { rootNode = new TreeNode<T>(data); }

	/*
	* �Լ� �̸� : ~BST
	* ��ȯ Ÿ�� : X
	* �Ű� ���� : X
	* �Լ� ��� : �Ҹ���
	*/
	~BST() { if (rootNode) delete rootNode; }

	/*
	* �Լ� �̸� : addData
	* ��ȯ Ÿ�� : void
	* �Ű� ���� : T
	* �Լ� ��� : ������ �߰�
	*/
	void addData(T& insertedData);

	/*
	* �Լ� �̸� : printTree
	* ��ȯ Ÿ�� : void
	* �Ű� ���� : X
	* �Լ� ��� : BST�� ���
	*/
	void printBST() const;
};

template < class T >
void BST<T>::addData(T& insertedData) {

	if (rootNode) {

		TreeNode<T> *nextNode = rootNode;

		try {

			// find parents node
			while (nextNode) {

				//nextNode = insertedData > nextNode ? nextNode->getRightChild() : nextNode->getLeftChild();

				// �Է� �����Ͱ� �� ���� ���
				if (insertedData < nextNode->getData()) {

					if (nextNode->getLeftChild())
						nextNode = nextNode->getLeftChild();

					else
						break;
				}

				// �Է� �����Ͱ� �� ū ���
				else if (nextNode->getData() < insertedData) {

					if (nextNode->getRightChild())
						nextNode = nextNode->getRightChild();

					else
						break;
				}

				// �̹� �����ϴ� �����Ͱ� ���� ���
				else
					throw ExceptionExistData();
			}

			if (nextNode->getData() < insertedData)
				nextNode->makeRightChild(insertedData);
			else
				nextNode->makeLeftChild(insertedData);
		}

		catch (Exception e) {
			e.printErrorMsg();
		}
	}
	else
		rootNode = new TreeNode<T>(insertedData);

	
}

template < class T >
void BST<T>::printBST() const {

	printBST(0, rootNode);
}

template < class T >
void BST<T>::printBST(const int length, const TreeNode<T> *nextNode) const {

	if (!nextNode)
		return;

	printBST(length + 20, nextNode->getRightChild());
	cout << setw(length) << "��---" << nextNode->getData() << endl;
	printBST(length + 20, nextNode->getLeftChild());
}


#endif