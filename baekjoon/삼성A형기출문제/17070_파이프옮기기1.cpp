#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

enum STATE {
    horizontal,
    vertical,
    diagonal
};

vector<vector<int> > board;
int N;
int rst = 0;

void dfs(int str_x, int str_y, int end_x, int end_y, int state) {

    if (str_x > 0 && str_x <= N && str_y > 0 && str_y <= N && end_x > 0 && end_x <= N && end_y > 0 && end_y <= N) {
        if (end_x == N && end_y == N) {
            rst += 1;
            return;
        }

        // 가로 상태
        switch (state) {
            case horizontal:
                if (end_x + 1 <= N) {
                    if (board[end_y][end_x + 1] == 0) {
                        dfs(str_x + 1, str_y, end_x + 1, end_y, horizontal);
                    }
                }
                if (end_x + 1 <= N && end_y + 1 <= N) {
                    if (board[end_y][end_x + 1] == 0 && board[end_y + 1][end_x + 1] == 0 && board[end_y + 1][end_x] == 0) {
                        dfs(str_x + 1, str_y, end_x + 1, end_y + 1, diagonal);
                    }
                }
                break;

            case vertical:
                if (end_y + 1 <= N) {
                    if (board[end_y + 1][end_x] == 0) {
                        dfs(str_x, str_y + 1, end_x, end_y + 1, vertical);
                    }
                }
                if (end_x + 1 <= N && end_y + 1 <= N) {
                    if (board[end_y + 1][end_x] == 0 && board[end_y + 1][end_x + 1] == 0 && board[end_y][end_x + 1] == 0) {
                        dfs(str_x, str_y + 1, end_x + 1, end_y + 1, diagonal);
                    }
                }
                break;

            case diagonal:
                if (end_x + 1 <= N) {
                    if (board[end_y][end_x + 1] == 0) {
                        dfs(str_x + 1, str_y + 1, end_x + 1, end_y, horizontal);
                    }
                }
                if (end_y + 1 <= N) {
                    if (board[end_y + 1][end_x] == 0) {
                        dfs(str_x + 1, str_y + 1, end_x, end_y + 1, vertical);
                    }
                }
                if (end_x + 1 <= N && end_y + 1 <= N) {
                    if (board[end_y + 1][end_x] == 0 && board[end_y + 1][end_x + 1] == 0 && board[end_y][end_x + 1] == 0) {
                        dfs(str_x + 1, str_y + 1, end_x + 1, end_y + 1, diagonal);
                    }
                }
                break;
        }
    }
    else {
        return;
    }

}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    board.assign(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    // 시작은 가로로
    dfs(1, 1, 2, 1, 0);

    cout << rst << endl;
}