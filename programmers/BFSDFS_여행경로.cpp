#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int max_cnt = 0;

void DFS(string start, vector<vector<string> > &tickets, vector<bool> &visited, vector<string> &answer, vector<string> &temp, int cnt) {
    // 시작 공항을 temp에 넣는다.
    temp.push_back(start);
    
    if (max_cnt < cnt) {
        max_cnt = cnt;
        answer = temp;
    }
    
    for (int i = 0; i < tickets.size(); ++i) {
        // 시작 공항과 연결된 공항을 찾고
        // 연결된 공항을 방문하지 않았다면
        if (start == tickets[i][0] && !visited[i]) {
            visited[i] = true;
            DFS(tickets[i][1], tickets, visited, answer, temp, cnt + 1);
            visited[i] = false;
        }
    }
    temp.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    int cnt = 0;
    vector<string> answer, temp;
    vector<bool> visited(tickets.size(), false);
    
    // 공항 이름의 알파벳 순으로 공항을 정렬
    // 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로로 가야하기 때문에
    sort(tickets.begin(), tickets.end());
    
    DFS("ICN", tickets, visited, answer, temp, cnt);
    
    return answer;
}