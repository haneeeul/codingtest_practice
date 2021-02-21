#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int> p;

const int MAXNUM = 1000 + 1;

vector<vector<int> > tomatos(MAXNUM, vector<int>(MAXNUM, 0));
vector<vector<bool> > visited(MAXNUM, vector<bool>(MAXNUM, 0));
queue<pair<int, int> > q;

int seg, cnt, days = 0;
bool traverse;

int dx[4] = { 0, 0, -1, 1 }; // 상하좌우
int dy[4] = { 1, -1, 0, 0 };

void BFS(int n, int m) {
	// 익은 토마토 주위 탐색
	while (!q.empty()) {
		cnt = 0;
		traverse = false;
		for (int i = 0; i < seg; i++) {
			int x = q.front().first;
			int y = q.front().second;
			visited[x][y] = 1;
			q.pop();

			for (int j = 0; j < 4; j++) { // 상하좌우 확인

				int crt_x = x + dx[j];
				int crt_y = y + dy[j];

				if (0 <= crt_x && crt_x < n && 0 <= crt_y && crt_y < m) { // bound check
					if (tomatos[crt_x][crt_y] == 0 && !visited[crt_x][crt_y]) { // 주변 토마토가 안익었다면			
						traverse = true;
						tomatos[crt_x][crt_y] = 1; // 익히고
						q.push(make_pair(crt_x, crt_y)); // 추가
						cnt++; // 내일부터 익힐 토마토의 개수
					}
				}
			}
		}
		seg = cnt; // 하루 지남
		if (traverse) days++;
	}
	return;
}

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int m, n; cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomatos[i][j];
			if (tomatos[i][j] == 1) {
				q.push(make_pair(i, j));
				// 익은 토마토가 들어오면 큐에 넣어둔다
				seg++; // 첫날에 익은 토마토의 개수
			}
		}
	}

	BFS(n, m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && tomatos[i][j] == 0) days = -1;
		}
	}

	cout << days << endl;

	return 0;
}