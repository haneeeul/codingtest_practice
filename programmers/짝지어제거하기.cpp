#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 1;
    
    stack<char> st;
    
    for (int i = 0; i < s.size(); ++i) {
        if (st.empty()) {
            st.push(s[i]);
        }
        else {
            if (s[i] == st.top()) {
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        }
    }

    answer = st.size() > 0 ? 0 : 1;

    return answer;
}