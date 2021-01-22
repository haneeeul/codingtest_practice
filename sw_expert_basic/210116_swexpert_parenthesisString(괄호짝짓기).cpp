#include <iostream>
#include <stack>
#include <string>

using namespace std;

#define ll long long

int correctBracketPair(string str, ll len);

int main(int argc, char** argv)
{
    int test_case;
	int T = 10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        ll len = 0;
        string str;
        cin >> len;
        cin >> str;
        int answer = correctBracketPair(str, len);
        cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}

int correctBracketPair(string str, ll len) {
    stack<char> st, temp_st;
    int check = 1;

    for (int i = 0; i < len; ++i) {
        if (str[i] == '(') {
            st.push('(');
        }
        else if (str[i] == '<') {
            st.push('<');
        }
        else if (str[i] == '[') {
            st.push('[');
        }
        else if (str[i] == '{') {
            st.push('{');
        }
        else {
            if (str[i] == ')') {
                while (!st.empty() && st.top() != '(') {
                    temp_st.push(st.top());
                    st.pop();
                }
            }
            else if (str[i] == '>') {
                while (!st.empty() && st.top() != '<') {
                    temp_st.push(st.top());
                    st.pop();
                }
            }
            else if (str[i] == ']') {
                while (!st.empty() && st.top() != '[') {
                    temp_st.push(st.top());
                    st.pop();
                }
            }
            else if (str[i] == '}') {
                while (!st.empty() && st.top() != '{') {
                    temp_st.push(st.top());
                    st.pop();
                }
            }
            
            if (st.empty()) {
                check = 0;
                break;
            }
            else {
                st.pop(); // pop '(', '<', '[' or '{'
                while (!temp_st.empty()) {
                    st.push(temp_st.top());
                    temp_st.pop();
                }
            }
        }
    }

    if (check && st.empty()) check = 1;
    else check = 0;
    return check;
}