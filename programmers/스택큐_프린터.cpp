#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int> > q;
    priority_queue<int> pq;
    
    int answer = 0;
    int idx = 0;
    
    for (int i = 0; i < priorities.size(); ++i) {
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }
    
    while (!q.empty()) {
        // 현재 프린터에 대기 중인 문서의 우선순위가
        // 가장 우선순위가 높은 경우
        if (q.front().second == pq.top()) {
            // 프린트한다
            idx++;
            // 프린트 한 문서가 내가 원하는 문서일 때
            if (q.front().first == location) {
                // 반복문 종료
                answer = idx;
                break;
            }
            // 프린트 했으므로
            // 큐, 우선순위 큐 감소
            q.pop();
            pq.pop();
        }
        else {
            // 현재 문서의 우선순위가
            // 우선순위의 가장 위에 있는 순서와 맞지 않으므로
            // 이 문서는 큐의 가장 뒤로 옮긴다
            q.push(q.front());
            q.pop();
        }
    }
    
    return answer;
}