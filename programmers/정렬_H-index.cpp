#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), greater<int>());

    if (citations[0] == 0) return 0;

    // 인용된 횟수는 주어진 citations의 값이 아니라 0 이상의 양의 정수이다.
    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] > i) ++answer;
        else break;
    }
    
    return answer;
}