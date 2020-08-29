#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isVPS(string s) {
    //stack<char> st; // oops ���� ������
    bool flag = true;
    int count = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') count++;
        else count--;

        if (count < 0) {
            flag = false;
            break;
        }
        /*if (s[i] == '(') st.push('(');
        else if (s[i] == ')') {
            if (!st.empty() && st.top() == '(') st.pop();
            else { // ')'�� �־�� �ϴµ� ������ ��� �ִ� ���
                flag = false;
                break;
            }
        }*/
    }
    return flag;
}

string solution(string p) {
    string answer = "";
    string u, v;
    int len = p.size();
    int right_pare = 0;
    int left_pare = 0;

    for (int i = 0; i < len; i++) {
        if (p[i] == '(') right_pare++;
        else left_pare++;

        if (right_pare == left_pare) break;
    }

    u = p.substr(0, right_pare + left_pare);
    v = p.substr(right_pare + left_pare);
    //cout << "u is " << u << endl;
    //cout << "v is " << v << endl;

    if (isVPS(u)) {
        answer += u;
        if (v.length()) answer += solution(v); // v�� ũ�Ⱑ 0�� ��쿡 solution() ���� �ÿ� ��Ͱ� ������ ����!!
    }
    else {
        answer += '(';
        answer += solution(v);
        answer += ')';
        for (int i = 1; i < u.length() - 1; i++) {
            if (u[i] == '(') answer += ')';
            else answer += '(';
        }
    }

    return answer;
}

int main() {
    string input;
    cin >> input;
    string output = solution(input);
    cout << "Output value is " << output << endl;
    return 0;
}

