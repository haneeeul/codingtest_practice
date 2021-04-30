#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int row, col = 0;
    int total = 0;
    for (row = yellow; row > yellow / 2; row--) {
        if (yellow % row != 0) continue;
        col = yellow / row;

        total = row * 2 + col * 2 + 4;
        if (total == brown) {
            answer.push_back(row + 2);
            answer.push_back(col + 2);
            return answer;
        }
    }
}