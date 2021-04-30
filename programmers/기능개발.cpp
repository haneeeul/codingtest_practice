// stack/queue 문제

#include <string>
#include <vector>
#include <stack>
#include <deque>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<pair<int, int> > prog;
    stack<pair<int, int> > temp;
    
    for (int i = progresses.size() - 1; i >= 0; --i) {
        prog.push({progresses[i], i});
    }
    
    while (!prog.empty()) {
        if (prog.top().first >= 100) {
            int cnt = 1;
            prog.pop();

            while (!prog.empty() && prog.top().first >= 100) {
                prog.pop();
                cnt += 1;
            }
            answer.push_back(cnt);
        }
        
        // 하루가 지난다.
        while (!prog.empty()) {
            temp.push({prog.top().first + speeds[prog.top().second], prog.top().second});
            prog.pop();
        }

        while (!temp.empty()) {
            prog.push({temp.top().first, temp.top().second});
            temp.pop();
        }
    }
    
    
    return answer;
}