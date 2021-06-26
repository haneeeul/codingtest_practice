#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    
    if (N == number) {
        answer = 1;
        return answer;
    }
    
    vector<vector<long long> > memo(8);

    for (int i = 0; i < 8; ++i) {
        string num;
        for (int m = 0; m <= i; ++m) {
            num += to_string(N);
        }
        memo[i].push_back(stoll(num));
    }

    for (int i = 1; i < 8; ++i) {
        
        for (int j = 0; j < i; ++j) {
            // 이 부분을 j, k로 표현을 못하겠음...
            for (auto op1 : memo[j]) {
                for (auto op2 : memo[i - j - 1]) {
                    memo[i].push_back(op1 + op2);
                    memo[i].push_back(op1 - op2);
                    memo[i].push_back(op1 * op2);
                    if (op2 != 0) memo[i].push_back(op1 / op2);
                }
            }
        }
        
        if (find(memo[i].begin(), memo[i].end(), (long long)number) != memo[i].end()) {
            answer = i + 1;
            break;
        }
    }
    
    return answer;
}