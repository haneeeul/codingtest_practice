#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int> > commands) {
    vector<int> answer;
    
    for (int i = 0; i < commands.size(); ++i) {
        vector<int> subarray;
        subarray.assign(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1] - 1);
        sort(subarray.begin(), subarray.end());
        answer.push_back(subarray[commands[i][2] - 1]);
    }
    
    return answer;
}

int main(void) {
    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int> > commands = { {2, 5, 3}, {4, 4, 1}, {1, 7, 3} };

    vector<int> rst = solution(array, commands);

    for (int i = 0 ; i < rst.size(); ++i) {
        cout << rst[i] << endl;
    }

    return 0;
}