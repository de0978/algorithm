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
	* 함수 이름 : printTreeByInorder
	* 반환 타입 : void
	* 매개 변수 : const TreeNode<T> *
	* 함수 기능 : 트리를 중위 순회 방식으로 탐색
	*/
	void printTreeByInorder(const TreeNode<T>* nextNode) const;
	
	/*
	* 함수 이름 : printTreeByPreorder
	* 반환 타입 : void
	* 매개 변수 : const TreeNode<T> *
	* 함수 기능 : 트리를 전위 순회 방식으로 탐색
	*/
	void printTreeByPreorder(const TreeNode<T>* nextNode) const;
	
	/*
	* 함수 이름 : printTreeByPostorder
	* 반환 타입 : void
	* 매개 변수 : const TreeNode<T> *
	* 함수 기능 : 트리를 후위 순회 방식으로 탐색
	*/
	void printTreeByPostorder(const TreeNode<T>* nextNode) const;

	/*
	* 함수 이름 : printTree
	* 반환 타입 : X
	* 매개 변수 : int, const TreeNode<T> *
	* 함수 기능 : 트리 모양으로 트리 출력
	*/
	void printTree(int length, char ch,const TreeNode<T> *nextNode) const;

public:

	/* Constructor */

	/*
	* 함수 이름 : Tree
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : rootNode를 NULL로 초기화
	*/
	Tree();

	/*
	* 함수 이름 : Tree
	* 반환 타입 : X
	* 매개 변수 : const T&
	* 함수 기능 : rootNode 에 메모리를 바로 할당
	*/
	Tree(const T& data);

	/* Destroyer */

	/*
	* 함수 이름 : ~Tree
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : rootNode 동적 메모리 해제
	*/
	~Tree();

	/* Member Function */
	
	/*
	* 함수 이름 : addNode
	* 반환 타입 : X
	* 매개 변수 : const T&
	* 함수 기능 : 자식 노드를 추가한다.
	*/
	void addNode(const T& data);

	/*
	* 함수 이름 : printTreeByInorder
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 트리 중위 순회
	*/
	void printTreeByInorder() const;

	/*
	* 함수 이름 : printTreeByPreorder
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 트리 전위 순회
	*/
	void printTreeByPreorder() const;

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
	* 함수 이름 : printTree
	* 반환 타입 : X
	* 매개 변수 : X
	* 함수 기능 : 트리 모양으로 트리 출력
	*/
	void printTree() const;

	/*
	* 함수 이름 : getMaxLevel
	* 반환 타입 : int
	* 매개 변수 : X
	* 함수 기능 : 최대 레벨 탐색
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

	// level order를 통해 빈 자리 찾기

	CircleQueue<T> levelOrder;

	TreeNode<T> *blankFinder = rootNode;

	while (1) {

		if (!blankFinder->getLeftChild()) { // 왼쪽 자식 없음
			blankFinder->makeLeftChild(data);
			break;
		}

		else if (!blankFinder->getRightChild()) { // 오른쪽 자식 없음
			blankFinder->makeRightChild(data);
			break;
		}

		// 둘 다 꽉 찬 경우 ( null pointer 가 들어가지 않는 구조 )
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
void Tree<T>::printTreeByInorder(const TreeNode<T>* nextNode) const { // 중위 순회

	if (!nextNode)
		return;

	printTreeByInorder(nextNode->getLeftChild()); // 왼쪽으로 쭉 ~
	cout << nextNode->getData() << " "; // 데이터 출력
	printTreeByInorder(nextNode->getRightChild()); // 오른쪽으로 쮹 ~

}

template < class T >
void Tree<T>::printTreeByPostorder() const {

	printTreeByPostorder(rootNode);
}

template < class T >
void Tree<T>::printTreeByPostorder(const TreeNode<T>* nextNode) const { // 후위 순회

	if (!nextNode)
		return;

	printTreeByPostorder(nextNode->getLeftChild());  // 왼
	printTreeByPostorder(nextNode->getRightChild()); // 오
	cout << nextNode->getData() << " ";			 // 데이터 출력
}

template < class T >
void Tree<T>::printTreeByPreorder() const {

	printTreeByPreorder(rootNode);
}

template < class T >
void Tree<T>::printTreeByPreorder(const TreeNode<T>* nextNode) const { // 전위 순회

	if (!nextNode)
		return;

	cout << nextNode->getData() << " ";
	printTreeByPreorder(nextNode->getLeftChild());
	printTreeByPreorder(nextNode->getRightChild());
}

template < class T >
void Tree<T>::printTreeByLevelorder() const { // 단계 순회

	CircleQueue<T> levelOrder;

	TreeNode<T> *orderPtr = rootNode;

	while (orderPtr) {

		cout << orderPtr->getData() << " ";

		if (orderPtr->getLeftChild()) // 왼쪽 자식이 있으면 넣기
			levelOrder.push(orderPtr->getLeftChild());

		if (orderPtr->getRightChild()) // 오른쪽 자식이 있으면 넣기
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