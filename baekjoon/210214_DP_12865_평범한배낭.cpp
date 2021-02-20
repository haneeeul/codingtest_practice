#include<iostream>
#include<algorithm>
using namespace std;

struct stuff {
	int weight;
	int value;
};

int dp[101][100001];

int knapsack(stuff* &s, int n, int maxweight) {
	for (int i = 1; i <= n; i++) { // 챙겨야 하는 물건 n개
		for (int j = 1; j <= maxweight; j++) { // 챙길 수 있는 무게를 하나씩 늘리며 확인
			if (s[i - 1].weight <= j) { // 현재 넣으려는 물건의 무게가 총 무게보다 작거나 같을 때
				dp[i][j] = max(s[i - 1].value + dp[i - 1][j - s[i - 1].weight], dp[i - 1][j]);
			}
			else dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[n][maxweight];
}

int main(void) {
	int n, k;
	cin >> n >> k;

	stuff* knap = new stuff[n];

	for (int i = 0; i < n; i++) {
		cin >> knap[i].weight >> knap[i].value;
	}

	int maxvalue = knapsack(knap, n, k);

	cout << maxvalue;
	return 0;
}