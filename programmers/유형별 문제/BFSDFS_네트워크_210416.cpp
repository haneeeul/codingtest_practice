#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int visited[200];
void BFS(int start, int n, vector<vector<int>>& board);
void DFS(int start, int n, vector<vector<int>>& board);

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        if (visited[i] == 0) {
	    //BFS(i, n, computers);
	    DFS(i, n, computers);
            answer += 1;
        }
    }
    return answer;
}

void BFS(int start, int n, vector<vector<int>>& board) {
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        visited[curr] = 1;
        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0 && board[curr][i] == 1) {
                q.push(i);
            }
        }
    }

    return;
}

void DFS(int start, int n, vector<vector<int>> &board) {
    visited[start] = 1;
    for (int i = 0; i < n; i++) {
        if (board[start][i] == 1 && visited[i] == 0) {
            visited[i] = 1;
            DFS(i, n, board);
        }
    }
    return;
}
