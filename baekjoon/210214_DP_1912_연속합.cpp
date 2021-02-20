#include<iostream>
#include<algorithm>

using namespace std;

int dp[100000];
int num[100000];

int maxsum(int n) {
	dp[0] = num[0];
    // 현재 수와 이전 수와 현재 수의 합 비교(DP)
	for (int i = 1; i < n; i++) {
		dp[i] = max(num[i], dp[i - 1] + num[i]);
	}

	int rst = dp[0];
	for (int i = 1; i < n; i++) {
		rst = max(rst, dp[i]);
	}

	return rst;
}

int main(void) {
	int n; cin >> n;

	for (int i = 0; i < n; i++) cin >> num[i];

	int ans = maxsum(n);

	cout << ans;
	return 0;
}