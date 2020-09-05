#include <iostream>
#include <cstring> // memset()
#include <vector>
#include <algorithm>

using namespace std;

int box[100];

int flatten(int dump) {
	int rst;

	for (int i = 0; i < dump; i++) {
		sort(box, box + 100);
		if (box[99] - box[0] <= 1) {//break; // 왜 break인데 되지?
			return box[99] - box[0];
		}

		box[99]--;
		box[0]++;
	}

	rst = box[98] - box[1];

	return rst;
}

int main(int argc, char** argv) {

	//freopen("input.txt", "r", stdin);

	for (int t = 1; t <= 10; ++t) {

		int dump; cin >> dump;
		memset(box, 0, sizeof(box));
		for (int i = 0; i < 100; ++i) {
			cin >> box[i];
		}

		cout << "#" << t << " " << flatten(dump) << "\n";
	}

	return 0;
}