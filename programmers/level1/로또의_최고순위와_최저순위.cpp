#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int cnt_zero = 0;
    int matched = 0;
    for (auto num : lottos) {
        if (num == 0) cnt_zero += 1;
        else {
            for (auto w : win_nums) {
                if (w == num) {
                    matched += 1;
                    break;
                }
            }
        }
    }
    
    // 최고 순위
    int max_rst = 7 - (matched + cnt_zero);
    if (max_rst <= 5) {
        answer.push_back(max_rst);
    }
    else {
        answer.push_back(6);
    }
    
    // 최저 순위
    int min_rst = 7 - matched;
    if (min_rst <= 5) {
        answer.push_back(min_rst);
    }
    else {
        answer.push_back(6);
    }
    
    return answer;
}