#define pii pair<int, int>
#define MAXNUM 100
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int> > graph;
vector<bool> visited;

bool comp (pii p1, pii p2) {
	return p1.first < p2.first;
}

int BFS(int node, int stage) {
	vector<pii> v;
	queue<pii> q;

	q.push(make_pair(node, stage));
	visited[node] = true;

	while (!q.empty()) {
		pii curr = q.front();
		// visited[curr.first] = true; // 틀림
		// 스테이지가 변경 되었는지 확인
		if (v.size() == 0) {}
		else if (curr.second != v[v.size() - 1].second) {
			v.clear();
		}
		v.push_back(curr);
		q.pop();

		for (int i = 0; i < graph[curr.first].size(); ++i) {
			if (!visited[graph[curr.first][i]]) {
				visited[graph[curr.first][i]] = true; // 맞음
				q.push(make_pair(graph[curr.first][i], curr.second + 1));
			}
		}
	}

	pii max_pair = *max_element(v.begin(), v.end(), comp);
	return max_pair.first;
}

int main(void) {

	int test_case;
	int T = 10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{	
		int from, to, len, start;
		cin >> len;
		cin >> start;

		graph.assign(MAXNUM + 1, vector<int>());
		visited.assign(MAXNUM + 1, false);

		for (int i = 0; i < len / 2; ++i) {
			cin >> from;
			cin >> to;
			graph[from].push_back(to);
		}

		cout << '#' << test_case << ' ' << BFS(start, 0) << '\n';

		graph.clear();
		visited.clear();
	}

	return 0;
}
