#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int a, b, c;
int answer[20 + 1][20 + 1][20 + 1];

int recur(int a, int b, int c) {

	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return recur(20, 20, 20);

	int &rst = answer[a][b][c];
	if (rst != 0) {
		return rst;
	}

	if (a < b && b < c) {
		rst = recur(a, b, c - 1) + recur(a, b - 1, c - 1) - recur(a, b - 1, c);
	} else {
		rst = recur(a - 1, b, c) + recur(a - 1, b - 1, c) + recur(a - 1, b, c - 1) - recur(a - 1, b - 1, c - 1);
	}
	return rst;
}

int main(void) {
	
	while (cin >> a >> b >> c) {
		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		//memset(answer, 0, sizeof(answer));
		cout << "w(" << a << ", " << b << ", " << c << ") = " << recur(a, b, c) << '\n';	
	}

	return 0;
}