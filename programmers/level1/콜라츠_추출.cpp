#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long n = num;
    
    // 이미 1이라면 작업을 할 필요가 없다.
    if (n == 1) return 0;
    
    while (answer <= 500) {
        answer += 1;
        if (n % 2) {
            n = (n * 3) + 1;
        }
        else {
            n /= 2;
        }
        if (n == 1) break;
    }
    
    if (answer >= 500 && n != 1) {
        answer = -1;
    }
    
    return answer;
}