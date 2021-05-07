#include <iostream>
#include <string>
#include <vector>

using namespace std;

int iscorrect(int x, int y, int N, vector<vector<int> > board, vector<vector<int> > key) {
    int M = key.size();

    for (int i = y, a = 0; i < y + M; i++, a++) {
        for (int j = x, b = 0; j < x + M; j++, b++) {
            board[i][j] = board[i][j] ^ key[a][b];
            if (!board[i][j] && key[a][b]) return -1;
        }
    }

    int cnt = 0;
    for (int i = M - 1; i < M + N - 1; i++) {
        for (int j = M - 1; j < N + M - 1; j++) {
            if (!board[i][j]) cnt++;
        }
    }
    return cnt;
}

vector<vector<int> > rotation(vector<vector<int> > key) {
    int s = key.size();
    vector<vector<int> > rst(s, vector<int>(s, 0));

    for (int i = 0, j = 0; i < s; i++, j++) {
        for (int a = s - 1, b = 0; a >= 0; a--, b++) {
            rst[j][b] = key[a][i];
        }
    }
    return rst;
}

bool solution(vector<vector<int> > key, vector<vector<int> > lock) {
    bool answer = true;
    int N = lock.size();
    int M = key.size();
    vector<vector<int> > board(2 * M + N - 2, vector<int>(2 * M + N - 2, 0));

    for (int i = M - 1, a = 0; i < M - 1 + N; i++, a++) {
        for (int j = M - 1, b = 0; j < M - 1 + N; j++, b++) {
            board[i][j] = lock[a][b];
        }
    }

    for (int i = 0; i < M + N - 1; i++) {
        for (int j = 0; j < M + N - 1; j++) {
            vector<vector<int> > nextkey = key;

            for (int k = 0; k < 4; k++) {
                if (iscorrect(j, i, N, board, nextkey) == 0) {
                    answer = true;
                    return answer;
                }
                nextkey = rotation(nextkey);
            }

        }
    }
    answer = false;
    return answer;
}

int main(void) {
    vector<vector<int> > lock;
    vector<vector<int> > key;

    bool answer = solution(key, lock);

    cout << answer << endl;
    return 0;
}