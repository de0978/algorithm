
#include "Tree.h"

int main() {


	Tree<int> tree;

	int num;
	cout << " [ 숫자 입력 ] : ";

	cin >> num;

	for (int i = 0; i <= num; ++i)
		tree.push(i);

	cout << " [ Preorder ] : ";
	tree.printTreeByPreorder();
	cout << endl;

	cout << " [ Inorder ] : ";
	tree.printTreeByInorder();
	cout << endl;

	cout << " [ Postorder ] : ";
	tree.printTreeByPostorder();
	cout << endl;

	cout << " [ Levelorder ] : ";
	tree.printTreeByLevelorder();
	cout << endl;

	cout << " [ Print Tree ] " << endl;
	tree.printTree();
	cout << endl;
	


	return 0;
}