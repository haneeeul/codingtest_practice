#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

int N, M, K;
int used[6] = {0, 0, 0, 0, 0, 0};
vector<int> temp;
vector<vector<int> > perm;
vector<vector<int> > board;
vector<vector<int> > rboard;
int rotation[6][3];
int rst = INT_MAX;

void permutation(int n, int r) {
    if (temp.size() == r) {
        perm.push_back(temp);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (used[i] == 1) continue;
        used[i] = 1;
        temp.push_back(i);
        permutation(n, r);
        temp.pop_back();
        used[i] = 0;
    }
}

void Rotate(int r, int c, int s) {

    if (r - s == r + s && c - s == c + s) return;

    for (int x = c - s; x < c + s; x++) {
        rboard[r - s][x + 1] = board[r - s][x];
    }

    for (int y = r - s; y < r + s; y++) {
        rboard[y + 1][c + s] = board[y][c + s];
    }

    for (int x = c + s; x > c - s; x--) {
        rboard[r + s][x - 1] = board[r + s][x];
    }

    for (int y = r + s; y > r - s; y--) {
        rboard[y - 1][c - s] = board[y][c - s];
    }

    // for (auto a : rboard) {
    //     for (auto b : a) {
    //         cout << b << " ";
    //     }
    //     cout << endl;
    // }

    Rotate(r, c, s - 1);

}

void solution() {
    vector<vector<int> > origin = board;
    for (int p = 0; p < perm.size(); p++) {
        board = origin;
        rboard = origin;
        for (int k = 0; k < K; k++) {
            int r = rotation[perm[p][k]][0];
            int c = rotation[perm[p][k]][1];
            int s = rotation[perm[p][k]][2];

            Rotate(r, c, s);
            board = rboard;
        }

        // for (auto a : rboard) {
        //     for (auto b : a) {
        //         cout << b << " ";
        //     }
        //     cout << endl;
        // }

        // 최솟값 구하기
        int sum, minValue = 987654321;
        for (int i = 1; i <= N; i++) {
            sum = 0;
            for (int j = 1; j <= M; j++) {
                sum += rboard[i][j];
            }
            //cout << "sum : " << sum << endl;
            if (minValue > sum) minValue = sum;
        }
        if (rst > minValue) {
            rst = minValue;
        }
    }
}

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    board.assign(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        cin >> rotation[i][0] >> rotation[i][1] >> rotation[i][2];
    }

    permutation(K, K);

    solution();

    cout << rst << endl;

    return 0;
}