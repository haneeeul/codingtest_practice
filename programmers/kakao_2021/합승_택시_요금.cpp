#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
*
간선 E(fairs)는 문제에서 최대 n * (n-1) / 2 의 크기를 가진다.

n은 최대 200의 크기를 가지므로 최악의 경우
플로이드 워셜: O( n^3 ) = 8 * 10^6
최악의 다익스트라: O( n * Elog n ) = 3 * 10^7

*/

// 다익스트라 풀이: 실패
// 거리 배열 dist 와 우선순위 큐를 사용해서 첫 정점부터 각 노드까지의 거리를 배열에 업데이트한다.
// 우선순위 큐에 다음에 갈 수 있는 노드를 넣으면서 dist 배열을 갱신하는 방식

// INF 수를 충분히 크게 해야한다.
// 100001로 딱 맞게 하면 실패
const int INF = 1000000;

vector<vector<pair<int, int> > > conn;

int dijkstra(int n, int src, int dst) {
    vector<int> dist(n + 1, INF);

    // 시작 지점까지 가는 거리는 0
    dist[src] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int w = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // 저장된 거리값이 현재 거리값보다 작으면
        // 갱신할 이유가 없다.
        if (dist[node] < w) continue;

        for (auto ad : conn[node]) {
            int ad_node = ad.first;
            int ad_w = ad.second;

            // 인접한 노드까지의 값을 추가
            ad_w += w;

            // 인접한 노드를 포함해서 가는 값이 저장된 거리값보다 작으면 갱신
            // 우선순위큐에 이 인접한 노드를 추가
            if (ad_w < dist[ad_node]) {
                dist[ad_node] = ad_w;
                pq.push({ad_w, ad_node});
            }
        }
    }

    return dist[dst];
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {

    conn.resize(n + 1);
    for (auto f : fares) {
        conn[f[1]].push_back({f[0], f[2]});
        conn[f[0]].push_back({f[1], f[2]});
    }

    int cost = dijkstra(n, s, a) + dijkstra(n, s, b);
    for (int i = 1; i <= n; ++i) {
        if (s != i) {
            cost = min(cost, dijkstra(n, s, i) + dijkstra(n, i, a) + dijkstra(n, i, b));
        }
    }
    
    return cost;
}

// 플로이드 워셜 풀이: 성공
// 모든 정점에서 모든 정점으로의 최단경로 구하고
// 모든 중간 지점에 대한 최단경로와 비교
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    vector<vector<int> > graph(201, vector<int>(201, 1e8));
    
    for (int i = 0; i < 201; ++i) {
        graph[i][i] = 0;
    }
    
    for (int i = 0; i < fares.size(); ++i) {
        graph[fares[i][0]][fares[i][1]] = fares[i][2];
        graph[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
            }
        }
    }
    
    int cost = 1e9;
    
    for (int i = 1; i <= n; ++i) {
        cost = min(cost, graph[s][i] + graph[i][a] + graph[i][b]);
    }
    
    return cost;
}