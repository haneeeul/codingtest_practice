#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> st;
    
    //answer.assign(prices.size(), 0);
    
    for (int i = 0; i < prices.size(); ++i) {
        while (!st.empty() && prices[st.top()] > prices[i]) {
            answer[st.top()] = i - st.top();
            st.pop();
            // 가격이 떨어진 경우
            // 이미 answer 값이 정해졌으므로
            // (한번 떨어진 가격은 후에 오르더라도 
            // 떨어지지 않은 기간에 포함하지 않음. 즉, 돌아보지 않음)
            // 이후에 answer 값을 수정하지 않도록
            // 스택에서 제거한다.
        }
        st.push(i);
    }
    
    while (!st.empty()) {
        answer[st.top()] = prices.size() - st.top() - 1;
        st.pop();
    }
    
    return answer;
}