#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int ndx[4] = { -1, 1, 1, -1 };
int ndy[4] = { 1, 1, -1, -1 };

struct robot {
	int x, y, dir, time;
	robot(int a, int b, int d, int t) {
		x = a;
		y = b;
		dir = d;
		time = t;
	}
};

int n;
bool visited[100][100][4];
vector<vector<int>> map;
queue<robot> q;

bool rangeChk(int x, int y, int xx, int yy) {
	if (x < 0 || x >= n || y < 0 || y >= n) return false;
	if (xx < 0 || xx >= n || yy < 0 || yy >= n) return false;

	return true;
}

pair<int, int> rotation(int x, int y, int nxx, int nyy, int dir, int time, int rotationdir) {
	for (int i = 1; i < 4; i+=2) {
		int ndir = (dir + i) % 4;
		nxx = x + dx[ndir];
		nyy = y + dy[ndir];

		int rx, ry;
		if (i == 1) {
			rx = x + ndx[ndir];
			ry = y + ndx[ndir];
		}
		else {
			rx = x + ndx[dir];
			ry = y + ndy[dir];
		}

		if (!rangeChk(rx, ry, nxx, nyy)) continue;
		if (rotationdir && visited[x][y][ndir]) continue;
		if (map[nxx][nyy]) continue;
		if (map[rx][ry]) continue;

		if (rotationdir) {
			visited[x][y][ndir] = true;
			q.push(robot(x, y, ndir, time + 1));
		}
		else {
			ndir = (ndir + 2) % 4;
			if (visited[nxx][nyy][ndir]) continue;
			visited[nxx][nyy][ndir] = true;
			q.push(robot(nxx, nyy, ndir, time + 1));
		}
	}
	return { nxx, nyy };
}

int solution(vector<vector<int>> board) {
	map = board;
	q.push(robot(0, 0, 0, 0));
	visited[0][0][0] = true;

	n = board.size();
	int dstX = n - 1;
	int dstY = n - 1;

	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;
		int time = q.front().time;
		q.pop();

		int xx = x + dx[dir];
		int yy = y + dy[dir];

		if ((x == dstX && y == dstY) || (xx == dstX && yy == dstY)) return time;

		int nx, ny, nxx, nyy;

		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			nxx = xx + dx[i];
			nyy = yy + dy[i];

			if (!rangeChk(nx, ny, nxx, nyy)) continue;
			if (visited[nx][ny][dir]) continue;
			if (board[nx][ny] == 1 || board[nxx][nyy] == 1) continue;

			visited[nx][ny][dir] = true;
			q.push(robot(nx, ny, dir, time + 1));
		}

		pair<int, int> rtn;
		rotation(x, y, nxx, nyy, dir, time, 1);
		rotation(xx, yy, nxx, nyy, (dir + 2) % 4, time, 0);
	}
}