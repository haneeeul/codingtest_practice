#include <string>
#include <vector>
#include <deque>
#include <stack>

using namespace std;

deque<int> dq;

void PushNum(int num) {
    stack<int> temp;

    if (dq.empty()) {
        dq.push_back(num);
        return;
    }
    else {
        if (dq.front() <= num) {
            dq.push_front(num);
        }
        else if (dq.back() >= num) {
            dq.push_back(num);
        }
        else {
            while (dq.front() > num) {
                temp.push(dq.front());
                dq.pop_front();
            }

            dq.push_front(num);

            while (!temp.empty()) {
                dq.push_front(temp.top());
                temp.pop();
            }
        }
        return;
    }
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    for (auto cmd : operations) {
        if (cmd[0] == 'I') {
            int num = stoi(string(cmd.begin() + 2, cmd.end()));
            PushNum(num);
        }
        else if (cmd[0] == 'D') {
            if (dq.empty()) {
                continue;
            }
            if (cmd.size() > 3) {
                // 최솟값 삭제
                dq.pop_back();
            }
            else {
                // 최댓값 삭제
                dq.pop_front();
            }
        }
    }
    
    if (dq.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(dq.front());
        answer.push_back(dq.back());
    }
    return answer;
}