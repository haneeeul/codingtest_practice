#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    // 이젠 좀 외우자 아스키코드
    // a == 97
    // A == 65
    
    // toupper(), tolower() 둘다 파라미터도 반환형도 int이다
    // 둘다 아스키코드 기반
    
    int idx = 0;
    
    for (auto temp : s) {
        if (temp == ' ') {
            answer += temp;
            idx = 0;
        }
        else {
            if (idx % 2) {
                // if (temp >= 97 && temp <= 122) {
                //     // 소문자인 경우
                //     answer += temp;
                // }
                // else {
                //     // 대문자인 경우
                //     answer += temp + 32;
                // }
                answer += tolower(temp);
            }
            else {
                // if (temp >= 97 && temp <= 122) {
                //     // 소문자인 경우
                //     answer += temp - 32;
                // }
                // else {
                //     // 대문자인 경우
                //     answer += temp;
                // }
                answer += toupper(temp);
            }
            idx++;
        }
    }
    
    return answer;
}