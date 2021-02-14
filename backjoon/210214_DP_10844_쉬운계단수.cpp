#include<iostream>

using namespace std;

typedef long long ll;
#define mod 1000000000

ll num[101][10];

int stairnum(int n) {

	for (int i = 1; i < 10; i++) {
		num[1][i] = 1;
	}

    // 모듈러 연산 조심
	for (int i = 2; i <= n; i++) {
		num[i][0] = num[i - 1][1] % mod;
		num[i][9] = num[i - 1][8] % mod;
		for (int j = 1; j < 9; j++) {
			num[i][j] = (num[i - 1][j - 1] + num[i - 1][j + 1]) % mod;
		}
	}

	ll sum = 0;
	for (int i = 0; i < 10; i++) {
		sum = (sum + num[n][i]) % mod;
	}
	return sum;
}


int main(void) {
	int n;
	cin >> n;

	int rst = stairnum(n);

	cout << rst;
	return 0;
}