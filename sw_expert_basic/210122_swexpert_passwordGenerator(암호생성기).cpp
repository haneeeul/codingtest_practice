#include <iostream>
#include <vector>

using namespace std;

vector<int> & findPassword(vector<int> &numArr) {
	vector<int>::iterator itNum = numArr.begin();
	int num = 0;
	while (1) {
		for (int i = 1; i <= 5; ++i) {
			if (itNum == numArr.end()) itNum = numArr.begin();

			num = *itNum;
			//cout << num << endl;
			itNum = numArr.erase(itNum);
			if (num - i <= 0) {
				numArr.push_back(0);
				return numArr;
			} else {
				numArr.push_back(num - i);
			}
		}
	}
	return numArr;
}

int main(void) {
	int test_case, T = 10;

	for (test_case = 1; test_case <= T; ++test_case) {
		int n;
		vector<int> num;
		cin >> n; // dummy value
		for (int i = 0; i < 8; ++i) {
			cin >> n;
			num.push_back(n);
		}

		vector<int> result = findPassword(num);
		cout << '#' << test_case << ' ';
		for (vector<int>::iterator it = result.begin(); it != result.end(); ++it) {
			cout << *it << ' ';
		}
		cout << "\n";
	}
}