#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> num;
int ic[1001]; // 증가하는 부분수열 구하기
int dc[1001]; // 감소하는 부분수열 구하기

int bitonic(int n) {
	int maxx = 1;
	int minn = 1;
	for (int i = 2; i <= n; i++) {
		// 가장 긴 증가부분수열
		for (int j = 1; j < i; j++) {
			if (num[j] < num[i]) {
				ic[i] = max(ic[i], ic[j] + 1);
			}
		}
		maxx = max(maxx, ic[i]);
	}
	for (int i = n-1; i >= 1; i--) {
		// 가장 긴 감소부분수열
		for (int j = n; j > i; j--) {
			if (num[i] > num[j]) {
				dc[i] = max(dc[i], dc[j] + 1);
			}
		}
		minn = max(minn, dc[i]);
	}

    // 가장 긴 증가부분수열의 길이 + 가장 긴 감소부분수열의 길이
	int rst = 0;
	for (int i = 1; i <= n; i++) {
		rst = max(rst, ic[i] + dc[i] - 1); // 겹치는 부분 제외 (-1)
	}

	return rst;
}

int main(void) {
	int n;
    cin >> n;

	num.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		ic[i] = 1;
        dc[i] = 1;
	}

	int rst = bitonic(n);

	cout << rst;
	return 0;
}