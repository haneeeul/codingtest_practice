// 크루스칼 알고리즘 문제
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parents;

int getParent(int node) {
    // 노드의 부모 노드 값을 반환하는 함수
    if (parents[node] == node) return node;
    return parents[node] = getParent(parents[node]);
}

bool cmp(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    // parents.push_back(i) 로 값을 밀어넣으면 실패
    parents.resize(n);
    for (int i = 0; i < n; ++i) {
        parents[i] = i;
    }
    
    sort(costs.begin(), costs.end(), cmp);

    for (int i = 0; i < costs.size(); ++i) {
        int start = getParent(costs[i][0]);
        int end = getParent(costs[i][1]);
        int cost = costs[i][2];
        
        if (start != end) {
            // 두 노드의 부모 노드가 서로 다르다면
            // 연결해도 된다.
            answer += cost;
            parents[end] = start;
        }
    }
    
    return answer;
}