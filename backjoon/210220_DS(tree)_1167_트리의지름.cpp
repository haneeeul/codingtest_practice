#include <iostream>
#include <vector>
#include <string>
#include <cstring> // memset()

using namespace std;

vector<vector<pair<int, int> > > nodes;
int visited[100000 + 1];
int max_length_node_idx = 0;
int diameter = 0;

void DFS(int idx, int curr_diam) {
    if (visited[idx] == 1) return;
    visited[idx] = 1;

    if (diameter < curr_diam) {
        diameter = curr_diam;
        max_length_node_idx = idx;
    }

    for (int i = 0; i < nodes[idx].size(); ++i) {
        if (visited[nodes[idx][i].first] == 0) {
            DFS(nodes[idx][i].first, curr_diam + nodes[idx][i].second);
        }
    }
}

int main(void) {
    int a, b, w, N;
    cin >> N;

    nodes.resize(N + 1);
    
    for (int i = 0; i < N; ++i) {
        cin >> a >> b;
        while (b >= 0) {
            cin >> w;
            nodes[a].push_back(make_pair(b, w));
            cin >> b;
        }
    }

    // 1번 노드에서 일단 가장 먼 노드 찾기 (굳이 1번 아니어도 된다)
    memset(visited, 0, sizeof(visited));
    DFS(1, 0);

    // root에서 가장 먼 노드에서 가장 먼 노드 찾기
    memset(visited, 0, sizeof(visited));
    DFS(max_length_node_idx, 0);

    cout << diameter;

    return 0;
}