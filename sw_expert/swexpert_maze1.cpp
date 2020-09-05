#include <iostream>
#include <cstring> // memset()
#include <string>
#include <queue>

using namespace std;

struct coor {
    coor(int x, int y) : x(x), y(y) {}
    int x;
    int y;
};

// 상하좌우
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int maze[16][16];
int visited[16][16];

int BFS(coor s) {
    int curr_x, curr_y, rst = 0;

    queue<coor> q;
    q.push(s);
    visited[s.y][s.x] == 1;

    while (!q.empty()) {
        curr_x = q.front().x;
        curr_y = q.front().y;
        q.pop();
        /*8cout << "curr_y, curr_x : " << curr_y << ", " << curr_x << "\n";
        cout << "maze[curr_y][curr_x] : " << maze[curr_y][curr_x] << "\n";
        cout << "queue size is : " << q.size() << "\n";*/
        if (maze[curr_y][curr_x] > 2) {
            rst = 1;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int xx = curr_x + dx[i];
            int yy = curr_y + dy[i];
            if (yy >= 0 && yy < 16 && xx >= 0 && xx < 16) {
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

    //freopen("input.txt", "r", stdin);
    coor start_idx(0, 0);
    int test_case;
    string val;
    for (int i = 1; i <= 10; ++i) {
        memset(visited, 0, sizeof(visited)); // visited 초기화
        cin >> test_case;

        for (int y = 0; y < 16; ++y) {
            cin >> val;
            for (int x = 0; x < 16; ++x) {
                maze[y][x] = val[x] - '0';
                if (maze[y][x] == 2) {
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