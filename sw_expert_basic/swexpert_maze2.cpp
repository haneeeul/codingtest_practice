#include <iostream>
#include <cstring> // memset()
#include <string>
#include <queue>

using namespace std;

#define SIZE 100

struct coor {
    coor(int x, int y) : x(x), y(y) {}
    int x;
    int y;
};

// 상하좌우
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int maze[SIZE + 1][SIZE + 1];
int visited[SIZE + 1][SIZE + 1];

int BFS(coor s) {
    int curr_x, curr_y, rst = 0;

    queue<coor> q;
    q.push(s);
    visited[s.y][s.x] == 1;
    
    while (!q.empty()) {
        curr_x = q.front().x;
        curr_y = q.front().y;
        q.pop();
        /*cout << "curr_y, curr_x : " << curr_y << ", " << curr_x << "\n";
        cout << "maze[curr_y][curr_x] : " << maze[curr_y][curr_x] << "\n";
        cout << "queue size is : " << q.size() << "\n";*/

		// 0은 길, 1은 벽, 2는 출발점, 3은 도착점
        if (maze[curr_y][curr_x] > 2) {
            rst = 1;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int xx = curr_x + dx[i];
            int yy = curr_y + dy[i];
            if (yy >= 0 && yy < SIZE && xx >= 0 && xx < SIZE) {
                if (maze[yy][xx] != 1 && visited[yy][xx] == 0) {
                    q.push(coor(xx, yy));
                    visited[yy][xx] = 1;
                }
            }
        }
    }

    return rst;
}

int main(void) {
    int n, test_case, T = 10;

	coor start_idx(0, 0);
    string val;
    for (test_case = 1; test_case <= 10; ++test_case) {
        memset(visited, 0, sizeof(visited)); // visited 초기화
        cin >> n; // dummy value

        for (int y = 0; y < SIZE; ++y) {
            cin >> val;
            for (int x = 0; x < SIZE; ++x) {
				// char to integer
                maze[y][x] = val[x] - '0'; // ASCII '0' value is 48.
                if (maze[y][x] == 2) { // 출발점 확인
                    start_idx.x = x;
                    start_idx.y = y;
                }
            }
        }
        
        //cout << "start point: " << start_idx.x << ", " << start_idx.y << "\n";
        cout << "#" << test_case << " " << BFS(start_idx) << "\n";
    }
    return 0;
}