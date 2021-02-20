#include<iostream>
#include<algorithm>

using namespace std;

pair<int, int> line[501];
int dp[501];

int LIS(int n) {
	int idx = 0; 
    int ans = 0;
	dp[idx] = line[0].second;

	for (int i = 1; i < n; i++) {
        // 전기줄은 A 인덱스 기준으로 정렬되어 있다.
        // 다음 전깃줄의 B 인덱스가 현재 인덱스보다 큰 경우
		if (dp[idx] < line[i].second) {
			idx++;
			dp[idx] = line[i].second;
		}
		else  // 다음 전깃줄의 B 인덱스가 현대 인덱스보다 작은 경우(전깃줄이 교차한다)
        {
			int idx2 = lower_bound(dp, dp + idx, line[i].second) - dp;
			/* lower_bound(it.begin, it.end, key), container가 정렬 되어 있어야 한다!
			key가 몇번째에 있는지를 반환하거나 
            key가 없는 경우 key값보다 큰 가장 작은 정수의 위치를 반환한다.
            여기서는 0번째부터 값이 주어지므로 위치(index)를 구하기 위해 -dp 만 한다.
			*/
			dp[idx2] = line[i].second;
			ans++;
		}
	}
	return ans;
}

int main(void) {
	int n;
    cin >> n;

	for (int i = 0; i < n; i++) {
        cin >> line[i].first >> line[i].second;
    }

	sort(line, line + n); // 기본은 first value 오름차순 정렬

	int rst = LIS(n);
	cout << rst;

	return 0;
}