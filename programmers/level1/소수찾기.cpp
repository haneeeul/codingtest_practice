#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    /*
    * 에라토스테네스의 체
    */
    
    vector<int> prime(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        if (prime[i] == 0) {
            // 어떤 소수의 배수는 소수가 아니다.
            for (int j = i * 2; j <= n; j+=i) {
                prime[j] = 1;
            }
        }
    }

  	for (int i = 2; i <= n; i++) {
        if (prime[i] == 0) answer += 1;
    }
    
    return answer;
}