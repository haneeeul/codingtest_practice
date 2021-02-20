#include <iostream>
#include <vector>
#include <string>
#include <cstring> // memset()

using namespace std;

vector<vector<pair<int, int> > > nodes;
int visited[10000 + 1];
int max_length_node_idx = 0;
int diameter = 0;

void DFS(int idx, int curr_diam) {
    if (visited[idx] == 1) return;
    visited[idx] = 1;

    if (diameter < curr_diam) {
        diameter = curr_diam;
        max_length_node_idx = idx;
    }

    // cout << "current diameter : " << diameter << endl;
    // cout << "current max node index : " << max_length_node_idx << endl;

    // cout << "current root node index : " << idx << endl;
    // cout << "current node size(the number of children) : " << nodes[idx].size() << endl;
    for (int i = 0; i < nodes[idx].size(); ++i) {
        if (visited[nodes[idx][i].first] == 0) {
            // cout << "nodes[idx][i].first : " << nodes[idx][i].first << endl;
            DFS(nodes[idx][i].first, curr_diam + nodes[idx][i].second);
        }
    }
}

int main(void) {
    int a, b, w, N;
    cin >> N;

    nodes.resize(N + 1);

    for (int i = 0; i < N - 1; ++i) {
        cin >> a >> b >> w;
        // 트리는 사이클이 없는 무방향 그래프이다. 부모 -> 자식 이것은 방향이 아니다!!
        nodes[a].push_back(make_pair(b, w));
        nodes[b].push_back(make_pair(a, w));
    }

    // root에서 가장 먼 노드 찾기
    memset(visited, 0, sizeof(visited));
    DFS(1, 0);

    // root에서 가장 먼 노드에서 가장 먼 노드 찾기
    memset(visited, 0, sizeof(visited));
    DFS(max_length_node_idx, 0);

    cout << diameter;

    return 0;
}