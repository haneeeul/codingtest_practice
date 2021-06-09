#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> rst;
    
    while (n) {
        rst.push_back(n % 3);
        n /= 3;
    }
    
    for (int i = rst.size() - 1; i >= 0; --i) {
        answer += pow(3, i) * rst[rst.size() - 1 - i];
    }
    
    return answer;
}