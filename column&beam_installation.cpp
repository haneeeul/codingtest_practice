#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
int map[102][102][2]; // x, y and column is 0, beam is 1

bool isbuiltBeam(int n, int x, int y) {
    // 기둥이 새로운 보의 오른쪽에 있는 경우
    if (y - 1 >= 0 && x + 1 <= n && map[x + 1][y - 1][0]) {
        return true;
    }
    // 기둥이 새로운 보의 왼쪽에 있는 경우
    if (y - 1 >= 0 && map[x][y - 1][0]) {
        return true;
    }
    // 보의 양쪽 끝에 다른 보들이 동시에 연결되어 그 사이에 짓는 경우
    if (x - 1 >= 0 && x + 1 <= n && map[x - 1][y][1] && map[x + 1][y][1]) {
        return true;
    }
    return false;
}

bool isbuiltCol(int n, int x, int y) {
    // 기둥을 바닥 위에 짓는 경우
    if (y == 0) {
        return true;
    }
    // 기둥을 다른 기둥 위에 짓는 경우
    if (y - 1 >= 0 && map[x][y - 1][0]) {
        return true;
    }
    // 기둥을 왼쪽 보의 끝에 짓는 경우
    if (map[x][y][1]) {
        return true;
    }
    // 기둥을 오른쪽 보의 끝에 짓는 경우
    if (x - 1 >= 0 && map[x - 1][y][1]) {
        return true;
    }
    return false;
}

bool isdeletedBeam(int n, int x, int y) {
    // 먼저 보를 지워본다
    map[x][y][1] = 0;
    // 지운 보의 오른쪽 끝 위에 있는 기둥을 지을 수 있는가?
    if (x + 1 <= n && map[x + 1][y][0]) {
        if (!isbuiltCol(n, x + 1, y)) {
            return false;
        }
    }
    // 지운 보의 왼쪽 끝 위에 있는 기둥을 지을 수 있는가?
    if (map[x][y][0]) {
        if (!isbuiltCol(n, x, y)) {
            return false;
        }
    }
    // 지운 보의 오른쪽에 있는 보를 지을 수 있는가?
    if (x + 1 <= n && map[x + 1][y][1]) {
        if (!isbuiltBeam(n, x + 1, y)) {
            return false;
        }
    }
    // 지운 보의 왼쪽에 있는 보를 지을 수 있는가?
    if (x - 1 >= 0 && map[x - 1][y][1]) {
        if (!isbuiltBeam(n, x - 1, y)) {
            return false;
        }
    }
    return true;
}

bool isdeletedCol(int n, int x, int y) {
    // 먼저 기둥을 지워본다
    map[x][y][0] = 0;
    // 지운 기둥의 위에 있는 기둥을 지을 수 있는가?
    if (y + 1 <= n && map[x][y + 1][0]) {
        if (!isbuiltCol(n, x, y + 1)) {
            return false;
        }
    }
    // 지운 기둥의 오른쪽에 걸친 보를 지을 수 있는가?
    if (y + 1 >= n && map[x][y + 1][1]) {
        if (!isbuiltBeam(n, x, y + 1)) {
            return false;
        }
    }
    // 지운 기둥의 왼쪽에 걸친 보를 지을 수 있는가?
    if (x - 1 >= 0 && y + 1 <= n && map[x - 1][y + 1][1]) {
        if (!isbuiltBeam(n, x - 1, y + 1)) {
            return false;
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    memset(map, 0, sizeof(map));

    int x, y, object, construct;

    for (int i = 0; i < build_frame.size(); i++) {
        x = build_frame[i][0];
        y = build_frame[i][1];
        object = build_frame[i][2];
        construct = build_frame[i][3];

        if (construct) { // 짓는 경우
            if (object) { // 보를 짓는 경우
                if (isbuiltBeam(n, x, y)) {
                    map[x][y][1] = 1;
                }
            }
            else { // 기둥을 짓는 경우
                if (isbuiltCol(n, x, y)) {
                    map[x][y][0] = 1;
                }
            }
        }
        else { // 삭제하는 경우
            if (object) { // 보를 삭제하는 경우
                if (!isdeletedBeam(n, x, y)) {
                    map[x][y][1] = 1;
                }
            }
            else {
                if (!isdeletedCol(n, x, y)) {
                    map[x][y][0] = 1;
                }
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < 2; k++) {
                if (map[i][j][k] != 0) {
                    answer.push_back({ i,j,k });
                }
            }
        }
    }
    return answer;
}

int main(void) {
    int n;
    cout << "Input n value: ";
    cin >> n;

    vector<vector<int>> frame (8, vector<int> (4));
    vector<vector<int>> rst;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> frame[i][j];
        }
    }

    rst = solution(n, frame);


    for (int i = 0; i < rst.size(); i++) {
        for (int j = 0; j < 3; j++) {
            cout << rst[i][j];
        }
        cout << endl;
    }
    return 0;
}