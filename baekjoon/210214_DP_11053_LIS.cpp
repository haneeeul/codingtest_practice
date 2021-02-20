#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> num;
int dp[1001];

int LIS(int n) {
	int maxx = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (num[j] < num[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		maxx = max(maxx, dp[i]);
	}

	/*if (num[i] > max_num) {
        dp[i] = max_len + 1;
        max_len++;
        max_num = num[i];
    }
    else {
        dp[i] = max_len;
    }*/

	return maxx;
}

int main(void) {
	int n;
    cin >> n;

	num.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		dp[i] = 1;
	}

	int rst = LIS(n);

	cout << rst;
	return 0;
}