#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

// up down left right
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int visited[4][3];
int pad[4][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {10, 0, 11}
};

int position[12][2] = {
    {1, 3}, // 0
    {0, 0}, // 1
    {1, 0}, // 2
    {2, 0}, // 3
    {0, 1}, // 4
    {1, 1}, // 5
    {2, 1}, // 6
    {0, 2}, // 7
    {1, 2}, // 8
    {2, 2}, // 9
    {0, 3}, // 10 == *
    {2, 3} // 11 == #
};

int min_dist = 12;

void dfs(int x, int y, int ans, int dist) {
    if (pad[y][x] == ans) {
        //cout << "        dist : " << dist << endl;
        if (min_dist > dist) {
            min_dist = dist;
        }
        return;
    }

    for (int k = 0; k < 4; k++) {
        if (x + dx[k] >= 0 && x + dx[k] < 3 && y + dy[k] >= 0 && y + dy[k] < 4 && visited[y + dy[k]][x + dx[k]] == 0) {
            // pad를 벗어나지 않은 상태에서
            visited[y + dy[k]][x + dx[k]] = 1;
            dfs(x + dx[k], y + dy[k], ans, dist + 1);
            visited[y + dy[k]][x + dx[k]] = 0;
        }
    }
}

int bfs(int x, int y, int ans) {
    queue<pair<int, int>> q;

    q.push({pad[y][x], 0});

    while (!q.empty()) {
        int num = q.front().first;
        int dist = q.front().second;
        q.pop();

        visited[position[num][1]][position[num][0]] = 1;

        if (num == ans) {
            return dist;
        }

        for (int k = 0; k < 4; k++) {
            if (position[num][0] + dx[k] >= 0 && position[num][0] + dx[k] < 3 && position[num][1] + dy[k] >= 0 && position[num][1] + dy[k] < 4 && visited[position[num][1] + dy[k]][position[num][0] + dx[k]] == 0) {
                visited[position[num][1] + dy[k]][position[num][0] + dx[k]] = 1;
                q.push({pad[position[num][1] + dy[k]][position[num][0] + dx[k]], dist + 1});
            }
        }
    }
    return -1;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    pair<pair<int, int>, int> leftpos, rightpos;

    leftpos.first.first = 0; // x
    leftpos.first.second = 3; // y
    leftpos.second = 10; // *

    rightpos.first.first = 2; // x
    rightpos.first.second = 3; // y
    rightpos.second = 11; // #

    for (int i = 0; i < numbers.size(); ++i) {
        int n = numbers[i];
        if (n == 1 || n == 4 || n == 7) {
            // left hand
            answer += "L";
            leftpos.first.first = position[n][0]; // x
            leftpos.first.second = position[n][1]; // y
            leftpos.second = n;
        }
        else if (n == 3 || n == 6 || n == 9) {
            // right hand
            answer += "R";
            rightpos.first.first = position[n][0]; // x
            rightpos.first.second = position[n][1]; // y
            rightpos.second = n;
        }
        else {
            // distance matters
            //cout << "거리 순으로 고른다. 목표 숫자는 " << n << endl;
            min_dist = 12;
            memset(visited, 0, sizeof(visited));
            //visited[leftpos.first.second][leftpos.first.first] = 1;
            //dfs(leftpos.first.first, leftpos.first.second, n, 0);
            //int dist_left = min_dist;
            int dist_left = bfs(leftpos.first.first, leftpos.first.second, n);

            //cout << "left distance : " << dist_left << endl;

            min_dist = 12;
            memset(visited, 0, sizeof(visited));
            //visited[rightpos.first.second][rightpos.first.first] = 1;
            //dfs(rightpos.first.first, rightpos.first.second, n, 0);
            //int dist_right = min_dist;
            int dist_right = bfs(rightpos.first.first, rightpos.first.second, n);

            //cout << "right distance : " << dist_right << endl;

            if (dist_left < dist_right) {
                answer += "L";
                leftpos.first.first = position[n][0]; // x
                leftpos.first.second = position[n][1]; // y
                leftpos.second = n;
            }
            else if (dist_left > dist_right) {
                answer += "R";
                rightpos.first.first = position[n][0]; // x
                rightpos.first.second = position[n][1]; // y
                rightpos.second = n;
            }
            else {
                if (hand == "right") {
                    // 오른손잡이
                    answer += "R";
                    rightpos.first.first = position[n][0]; // x
                    rightpos.first.second = position[n][1]; // y
                    rightpos.second = n;
                }
                else {
                    // 왼손잡이
                    answer += "L";
                    leftpos.first.first = position[n][0]; // x
                    leftpos.first.second = position[n][1]; // y
                    leftpos.second = n;
                }
            }
        }
    }

    return answer;
}