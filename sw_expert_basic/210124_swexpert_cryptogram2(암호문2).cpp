#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(void) {
	int test_case, T = 10;

	for (test_case = 1; test_case <= T; ++test_case) {
		int input, len, cnt;
		deque<int> original;

		cin >> len;
		for (int i = 0; i < len; ++i) {
			cin >> input;
			original.push_back(input);
		}
		
		cin >> cnt;
		for (int i = 0; i < cnt; ++i) {
			string inst = "";
			cin >> inst;
			if (inst == "I") {
				int coor, num, temp;
				deque<int>::iterator it = original.begin();
				cin >> coor; cin >> num;

				it += coor;
				for (int j = 0; j < num; ++j) {
					cin >> temp;
					it = original.insert(it, temp) + 1;
				}

			}
			else if (inst == "D") {
				int coor, num;
				deque<int>::iterator it = original.begin();
				cin >> coor; cin >> num;

				it += coor;
				original.erase(it, it + num);
			}
		}
		//vector<int> result = cryptogram(original, instructions, cnt);
		cout << '#' << test_case << ' ';
		for (int i = 0; i < 10; ++i) {
			cout << original[i] << ' ';
		}
		cout << '\n';
	}
}