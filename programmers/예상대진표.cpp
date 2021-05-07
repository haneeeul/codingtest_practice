// a, b를 2로 나누어 가면서
// 두 숫자가 같은 숫자가 되는 경우
// 두 숫자는 같은 라운드에서 만난 것이 된다.

// 홀수 / 2 에 대하여
// (홀수 + 1) / 2 로 라운드를 맞춰주는 것이 관건

#include <iostream>

using namespace std;

int solution(int n, int a, int b) {
    int answer = 0;
    
    while (a != b) {
        a = (a + 1) >> 1;
        b = (b + 1) >> 1;
        answer += 1;
    }

    return answer;
}