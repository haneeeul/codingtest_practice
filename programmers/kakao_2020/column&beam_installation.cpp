#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
int map[102][102][2]; // x, y and column is 0, beam is 1

bool isbuiltBeam(int n, int x, int y) {
    // ����� ���ο� ���� �����ʿ� �ִ� ���
    if (y - 1 >= 0 && x + 1 <= n && map[x + 1][y - 1][0]) {
        return true;
    }
    // ����� ���ο� ���� ���ʿ� �ִ� ���
    if (y - 1 >= 0 && map[x][y - 1][0]) {
        return true;
    }
    // ���� ���� ���� �ٸ� ������ ���ÿ� ����Ǿ� �� ���̿� ���� ���
    if (x - 1 >= 0 && x + 1 <= n && map[x - 1][y][1] && map[x + 1][y][1]) {
        return true;
    }
    return false;
}

bool isbuiltCol(int n, int x, int y) {
    // ����� �ٴ� ���� ���� ���
    if (y == 0) {
        return true;
    }
    // ����� �ٸ� ��� ���� ���� ���
    if (y - 1 >= 0 && map[x][y - 1][0]) {
        return true;
    }
    // ����� ���� ���� ���� ���� ���
    if (map[x][y][1]) {
        return true;
    }
    // ����� ������ ���� ���� ���� ���
    if (x - 1 >= 0 && map[x - 1][y][1]) {
        return true;
    }
    return false;
}

bool isdeletedBeam(int n, int x, int y) {
    // ���� ���� ��������
    map[x][y][1] = 0;
    // ���� ���� ������ �� ���� �ִ� ����� ���� �� �ִ°�?
    if (x + 1 <= n && map[x + 1][y][0]) {
        if (!isbuiltCol(n, x + 1, y)) {
            return false;
        }
    }
    // ���� ���� ���� �� ���� �ִ� ����� ���� �� �ִ°�?
    if (map[x][y][0]) {
        if (!isbuiltCol(n, x, y)) {
            return false;
        }
    }
    // ���� ���� �����ʿ� �ִ� ���� ���� �� �ִ°�?
    if (x + 1 <= n && map[x + 1][y][1]) {
        if (!isbuiltBeam(n, x + 1, y)) {
            return false;
        }
    }
    // ���� ���� ���ʿ� �ִ� ���� ���� �� �ִ°�?
    if (x - 1 >= 0 && map[x - 1][y][1]) {
        if (!isbuiltBeam(n, x - 1, y)) {
            return false;
        }
    }
    return true;
}

bool isdeletedCol(int n, int x, int y) {
    // ���� ����� ��������
    map[x][y][0] = 0;
    // ���� ����� ���� �ִ� ����� ���� �� �ִ°�?
    if (y + 1 <= n && map[x][y + 1][0]) {
        if (!isbuiltCol(n, x, y + 1)) {
            return false;
        }
    }
    // ���� ����� �����ʿ� ��ģ ���� ���� �� �ִ°�?
    if (y + 1 >= n && map[x][y + 1][1]) {
        if (!isbuiltBeam(n, x, y + 1)) {
            return false;
        }
    }
    // ���� ����� ���ʿ� ��ģ ���� ���� �� �ִ°�?
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

        if (construct) { // ���� ���
            if (object) { // ���� ���� ���
                if (isbuiltBeam(n, x, y)) {
                    map[x][y][1] = 1;
                }
            }
            else { // ����� ���� ���
                if (isbuiltCol(n, x, y)) {
                    map[x][y][0] = 1;
                }
            }
        }
        else { // �����ϴ� ���
            if (object) { // ���� �����ϴ� ���
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