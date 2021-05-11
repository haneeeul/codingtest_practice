#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int> > pq;
    
    for (auto s : scoville) {
        pq.push(s);
    }
    
    while (pq.size() > 1 && pq.top() < K) {
        int first = pq.top();
        pq.pop();

        int second = pq.top();
        pq.pop();

        if (pq.size() == 0) {
            // 원소가 두개인 경우
            if (first + second * 2 < K) {
                return -1;
            }
        }

        pq.push(first + second * 2);
        answer += 1;      
    }
    
    return answer;
}