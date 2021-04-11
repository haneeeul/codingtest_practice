#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    bool find = false;
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    // 시간복잡도: O(nlogn)
    
    for (int i = 0; i < completion.size(); ++i) {
        if (participant[i] != completion[i]) {
            answer = participant[i];
            find = true;
            break;
        }
    }
    
    if (!find) answer = participant[participant.size() - 1];
    
    return answer;
}