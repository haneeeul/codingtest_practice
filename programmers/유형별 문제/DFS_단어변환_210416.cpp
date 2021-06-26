#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int minlen = 50;

void dfs(vector<string>& words, vector<int>& visited, string begin, string target, int idx, int turns) {
    if (begin == target) {
        if (minlen > turns) {
            minlen = turns;
        }
        return;
    }
    
    for (int w = 0; w < words.size(); w++) {
        int cnt = 0;
        for (int i = 0; i < begin.size(); i++) {
            if (begin[i] == words[w][i]) cnt++;
        }

        if (cnt == begin.size() - 1 && visited[w] == 0) {
            visited[w] = 1;
            dfs(words, visited, words[w], target, w, turns + 1);
            visited[w] = 0;
        }
    }
    
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    vector<int> visited(words.size(), 0);
    
    if (find(words.begin(), words.end(), target) == words.end()) {
        answer = 0;
        return answer;
    }
    
    dfs(words, visited, begin, target, 0, 0);
    
    answer = minlen;

    return answer;
}