#include "TaskManager.h"
using namespace std;

int main() {


	while (1) {

		BST<string> bst;

		string phrase;

		cout << " [ ���ڿ� �Է� ] : ";

		getline(cin, phrase, '\n'); // �Է�

		if (phrase == "0") break;

		int prePos = 0;
		int postPos = 0;

		while (postPos != string::npos) {

			postPos = phrase.find(' ', prePos); // ���ڿ� ����

			//��ð� ���ؿ� �躴�� �輱�� ������ ����ȯ 0
			//�躴�� �輱�� ��ð� ����ȯ ���ؿ� ������ 0

			string temp = phrase.substr(prePos, postPos - prePos);

			if (temp[0] == '0') break;

			bst.addData(temp);

			prePos = postPos + 1;
		}

		bst.printBST();

	}
	return 0;
}