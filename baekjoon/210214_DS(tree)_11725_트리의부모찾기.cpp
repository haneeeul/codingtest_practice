#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int> > nodes;
vector<int> visited;


void DFS(int idx) {
    int curr_node = idx;
    
    if (nodes[curr_node].size() == 0) return;

    for (int i = 0; i < nodes[curr_node].size(); ++i) {
        //cout << "child nodes : " << nodes[curr_node].size() << endl;
        if (visited[nodes[curr_node][i]] == 0) {
            //cout << "curr child node idx : " << nodes[curr_node][i] << endl;
            visited[nodes[curr_node][i]] = curr_node; // parent node number
            DFS(nodes[curr_node][i]);
        }
    }
}

int main(void) {
    int a, b, N;
    cin >> N;

    nodes.resize(N + 1);
    visited.resize(N + 1);

    for (int i = 0; i < N; ++i) {
        cin >> a >> b;
        // 누가 부모인지 알 수 없기 때문에
        // 두 군데 모두 서로 자식이라고 추가해야한다.
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }

    visited[1] = -1;
    DFS(1);
    
    for (int i = 2; i <= N; ++i) {
        cout << visited[i] << "\n";
    }
    return 0;
}