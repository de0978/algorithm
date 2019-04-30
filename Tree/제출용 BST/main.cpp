#include "TaskManager.h"
using namespace std;

int main() {


	while (1) {

		BST<string> bst;

		string phrase;

		cout << " [ 문자열 입력 ] : ";

		getline(cin, phrase, '\n'); // 입력

		if (phrase == "0") break;

		int prePos = 0;
		int postPos = 0;

		while (postPos != string::npos) {

			postPos = phrase.find(' ', prePos); // 문자열 구분

			//김시관 이해연 김병만 김선명 이현아 오득환 0
			//김병만 김선명 김시관 오득환 이해연 이현아 0

			string temp = phrase.substr(prePos, postPos - prePos);

			if (temp[0] == '0') break;

			bst.addData(temp);

			prePos = postPos + 1;
		}

		bst.printBST();

	}
	return 0;
}