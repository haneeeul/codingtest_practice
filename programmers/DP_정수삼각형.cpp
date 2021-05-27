#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int> > memo = triangle;
    
    for (int i = 1; i < triangle.size(); ++i) {
        for (int j = 0; j < triangle[i].size(); ++j) {
            if (j == 0) {
                memo[i][j] += memo[i - 1][j];
            }
            else if (j == triangle[i].size() - 1) {
                memo[i][j] += memo[i - 1][j - 1];
            }
            else {
                memo[i][j] += max(memo[i - 1][j - 1], memo[i - 1][j]);
            }
        }
    }
    
    answer = *max_element(memo[memo.size() - 1].begin(), memo[memo.size() - 1].end());
    
    return answer;
}