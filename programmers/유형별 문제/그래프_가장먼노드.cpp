#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> bfs(vector<vector<int> > &conn, int start, int n) {
    vector<int> dist(n + 1, 0);
    vector<int> visited(n + 1, 0);
    queue<int> q;

    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i = 2; i <= n; i++) {
            if (conn[curr][i] == 1 && visited[i] == 0) {
                dist[i] = dist[curr] + 1;
                visited[i] = 1;
                q.push(i);
            }
        }
    }
    
    return dist;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    vector<vector<int> > conn(n + 1, vector<int>(n + 1, 0));
    
    for (auto e : edge) {
        conn[e[0]][e[1]] = conn[e[1]][e[0]] = 1;
    }

    vector<int> dist = bfs(conn, 1, n);

    int max_value = *max_element(dist.begin(), dist.end());

    for (auto d : dist) {
        if (d == max_value) answer++;
    }

    return answer;
}