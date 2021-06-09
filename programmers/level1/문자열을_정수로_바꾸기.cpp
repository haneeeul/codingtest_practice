#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int size = s.size() - 1;
    
    if (s.front() == '-') {
        size -= 1;
        for (int i = 1; i < s.size(); ++i) {
            answer -= pow(10, size) * (s[i] - '0');
            size--;
        }
    }
    else if (s.front() == '+') {
        size -= 1;
        for (int i = 1; i < s.size(); ++i) {
            answer += pow(10, size) * (s[i] - '0');
            size--;
        }
    }
    else {
        for (int i = 0; i < s.size(); ++i) {
            answer += pow(10, size) * (s[i] - '0');
            size--;
        }
    }
    
    // 한줄 정리
    // int answer = stoi(s);
    // 부호를 알아서 바꿔준다.

    return answer;
}