#include<iostream>
#include<algorithm>
using namespace std;

enum Color { red, green, blue };

int cost[1001][3];
int dp[1001][3];

int rgbstreet(int n) {
	dp[1][red] = cost[1][red];
    dp[1][green] = cost[1][green]; 
    dp[1][blue] = cost[1][blue];

    // 다음 선택지(red를 선택한 후에는 blue or green) 중 최솟값을 찾아서 더하는 것이 아니라
    // 이전 값 중에서 최솟값을 선택해서 더한다.
	for (int i = 2; i <= n; i++) {
		dp[i][red] = min(dp[i - 1][green], dp[i - 1][blue]) + cost[i][red];
		dp[i][green] = min(dp[i - 1][red], dp[i - 1][blue]) + cost[i][green];
		dp[i][blue] = min(dp[i - 1][red], dp[i - 1][green]) + cost[i][blue];
	}

	int minn = min(min(dp[n][red], dp[n][green]), dp[n][blue]);
	return minn;
}

int main(void) {
	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> cost[i][red] >> cost[i][green] >> cost[i][blue];
	}

	int rst = rgbstreet(n);

	cout << rst;
	return 0;
}