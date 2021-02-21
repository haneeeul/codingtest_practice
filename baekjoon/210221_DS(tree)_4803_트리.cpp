#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<bool> visited;
vector<vector<int> > graph;
vector<vector<bool> > edges;
bool cycle = false;

// 그래프에 사이클이 존재하지 않는다면
// 해당 그래프의 간선 개수는 n-1개 이다. (역도 성립)
// 문제 조건: 간선 m의 개수 <= n(n-1)/2
void DFS(int curr_node) {
    
    visited[curr_node] = true;

    for (int i = 0; i < graph[curr_node].size(); ++i) {
        int next_node = graph[curr_node][i];

        if (visited[next_node] == false) {
            edges[curr_node][next_node] = true;
            edges[next_node][curr_node] = true;
            DFS(next_node);
        }
        else if (edges[curr_node][next_node] == false) {
            cycle = true;
        }
        // 이미 방문한 노드인데, 이 엣지가 아니라 다른 엣지로 방문한 경우 -> 사이클 존재
    }
    return;
}

int main(void) {

    // cin 속도 개선
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m = -1;
    int node1, node2;

    for (int test_case = 1; ; ++test_case) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        visited.assign(n + 1, false);
        graph.assign(n + 1, vector<int>());
        edges.assign(n + 1, vector<bool>(n + 1, false));

        for (int i = 0; i < m; ++i) {
            cin >> node1 >> node2;
            // 부모 - 자식 관계를 알 수 없으므로 양방향으로 노드를 집어넣는다.
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }

        int answer = 0;
        for (int i = 1; i <= n; ++i) {
            // 모든 방문하지 않은 노드를 돌면서
            if (visited[i] == false) {
                cycle = false;
                DFS(i);
                if (cycle == false) answer += 1;
                // 사이클이 존재하지 않는다면 트리이다.
            }
        }

        cout << "Case " << test_case << ": ";
        // 문제를 잘 읽자,,,
        if (answer > 1) cout << "A forest of " << answer << " trees.\n";
        else if (answer == 1) cout << "There is one tree.\n";
        else cout << "No trees.\n";
        
        visited.clear();
        graph.clear();
        edges.clear();
    } 
    
    return 0;
}
