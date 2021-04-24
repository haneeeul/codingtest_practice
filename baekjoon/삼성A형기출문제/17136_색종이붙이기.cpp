#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int> > board;
vector<vector<int> > visited;
vector<int> papers;
int cnt = 0, rst = 987654321;

void func(int x, int y) {

    if (x == 10) {
        //cout << "next idx1 : " << 0 << ", " << y + 1 << endl;
        func(0, y + 1);
        return;
    }

    if (y == 10) {
        rst = min(rst, cnt);
        return;
    }

    if (board[y][x] == 0) {
        //cout << "next idx2 : " << x + 1 << ", " << y << endl;
        func(x + 1, y);
        return;
    }

    for (int len = 5; len > 0; len--) {
        bool isPossible = true;

        if (papers[len] == 0 || x + len > 10 || y + len > 10) {
            continue;
        }

        for (int i = y; i < y + len; i++) {
            for (int j = x; j < x + len; j++) {
                if (board[i][j] == 1) {}
                else {
                    isPossible = false;
                    break;
                }
            }
            if (!isPossible) break;
        }
    
        if (isPossible) {
            for (int i = y; i < y + len; i++) {
                for (int j = x; j < x + len; j++) {
                    board[i][j] = 0;
                }
            }

            cnt++;
            papers[len]--;

            func(x + len, y);

            for (int i = y; i < y + len; i++) {
                for (int j = x; j < x + len; j++) {
                    board[i][j] = 1;
                }
            }

            cnt--;
            papers[len]++;

        }
        else {
            continue;
        }
    }

    return;
}

void solution() {

    papers.clear();
    papers.assign(6, 5);
    papers[0] = 0;

    visited.clear();
    visited.assign(10, vector<int>(10, 0));

    func(0, 0);

    if (rst == 987654321) {
        rst = -1;
    }

    return;
}

int main(void) {

    board.assign(10, vector<int>(10, 0));

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> board[i][j];
        }
    }

    // for (auto a : board) {
    //     for (auto b : a) {
    //         cout << b << " "; 
    //     }
    //     cout << endl;
    // }

    solution();

    cout << rst << endl;

    return 0;
}