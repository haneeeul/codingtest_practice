#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int i = 0; i < commands.size(); ++i) {
        vector<int> subarray(5);
        subarray.clear();
        // 11, 12 line 없으면 error
        subarray.assign(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);
        sort(subarray.begin(), subarray.end());
        answer.push_back(subarray[commands[i][2] - 1]);
    }
    
    return answer;
}

