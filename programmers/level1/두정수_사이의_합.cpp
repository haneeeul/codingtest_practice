#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    if (a == b) return a;
    
    // 등차수열의 합공식 
    long long count = abs(b - a) + 1;
    
    answer = (long long)(a + b) * count / 2;
    // 오류. 오버플로우가 생기는 것 같다.
    // answer = ((long long)(a + b) / 2) * count;
    
    return answer;
}