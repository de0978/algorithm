/*
*  **성 제작 수준이 낮긴함 ..  
*  제작 소요 시간 2시간 정도 .. 망할 소멸자
*  제작 일자 8/9
*/

#include"TaskManager.h"
#include <crtdbg.h>
using namespace std;

#ifndef _DEBUG
#define new new(_CLIENT_BLOCK,__FILE__,__LINE)
#endif

int main() {


	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	while (1) {

		Tree<int> tree;

		int num = 0;

		cout << " [ 숫자 입력 ] : ";

		cin >> num;

		for (int i = 0; i <= num; ++i)
			tree.addNode(i);

		cout << " [ preorder ] : ";
		tree.printTreeByPreorder();
		cout << endl;

		cout << " [ Inorder ] : ";
		tree.printTreeByInorder();
		cout << endl;

		cout << " [ postorder ] : ";
		tree.printTreeByPostorder();
		cout << endl;

		cout << " [ levelorder ] : ";
		tree.printTreeByLevelorder();
		cout << endl;

		cout << " [ Tree Print ] " << endl;
		tree.printTree();

	}
	return 0;
}

