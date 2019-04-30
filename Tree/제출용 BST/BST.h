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
	* 함수 이름 : printTree
	* 반환 타입 : void
	* 매개 변수 : X
	* 함수 기능 : BST를 출력
	*/
	void printBST(const int length, const TreeNode<T> *nextNode) const ;

public:


	/*
	* 함수 이름 : BST
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 생성자
	*/
	BST() { rootNode = NULL;  }

	/*
	* 함수 이름 : BST
	* 반환 타입 : X
	* 매개 변수 : T
	* 함수 기능 : 생성자
	*/
	BST(T& data) { rootNode = new TreeNode<T>(data); }

	/*
	* 함수 이름 : ~BST
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 소멸자
	*/
	~BST() { if (rootNode) delete rootNode; }

	/*
	* 함수 이름 : addData
	* 반환 타입 : void
	* 매개 변수 : T
	* 함수 기능 : 데이터 추가
	*/
	void addData(T& insertedData);

	/*
	* 함수 이름 : printTree
	* 반환 타입 : void
	* 매개 변수 : X
	* 함수 기능 : BST를 출력
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

				// 입력 데이터가 더 작은 경우
				if (insertedData < nextNode->getData()) {

					if (nextNode->getLeftChild())
						nextNode = nextNode->getLeftChild();

					else
						break;
				}

				// 입력 데이터가 더 큰 경우
				else if (nextNode->getData() < insertedData) {

					if (nextNode->getRightChild())
						nextNode = nextNode->getRightChild();

					else
						break;
				}

				// 이미 존재하는 데이터가 들어올 경우
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
	cout << setw(length) << "ㅁ---" << nextNode->getData() << endl;
	printBST(length + 20, nextNode->getLeftChild());
}


#endif