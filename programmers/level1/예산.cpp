#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int sum = 0, answer = 0;
    
    sort(d.begin(), d.end());
    
    for (auto temp : d) {
        sum += temp;
        if (sum > budget) {
            break;
        }
        answer += 1;
    }
    
    return answer;
}