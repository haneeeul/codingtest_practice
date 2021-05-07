#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> board;
long long rst = 3000 + 1;

void DFS(int start, int money, long long q, long long earns, int turns) {
    
    if (earns == q) {
        if (rst > turns) {
            rst = turns;
        }
        return;
    }
    else if (earns < q) {

        DFS(start, money, q, earns + money, turns + 1);

        vector<pair<int, pair<int, int> > > s;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (start != i && board[i][j] != 0 && q - (earns + board[i][j]) == 0) {
                    DFS(j, money, q, earns + board[i][j], turns + 2);
                }
                else if (start != i && board[i][j] != 0 && q - (earns + board[i][j]) > 0) {
                    s.push_back(make_pair(q - (earns + board[i][j]), make_pair(i, j)));
                }
            }
        }
        
        if (!s.empty()) {
            sort(s.begin(), s.end());
            DFS(s[0].second.second, money, q, earns + board[s[0].second.first][s[0].second.second], turns + 2);
        }
        
        for (int i = 0; i < board[start].size(); i++) {
            if (board[start][i] != 0) {
                DFS(i, money, q, earns + board[start][i], turns + 1);
            }
        }
    }
    else {
        return;
    }

    return;
}

vector<long long> solution(int n, int z, vector<vector<int> > roads, vector<long long> queries) {
    vector<long long> answer;

    board.assign(n, vector<int>(n, 0));

    for (int i = 0; i < roads.size(); ++i) {
        board[roads[i][0]][roads[i][1]] = roads[i][2];
    }
    
    for (int i = 0; i < queries.size(); i++) {
        rst = 3000 + 1;
        DFS(0, z, queries[i], 0, 0);
        if (rst == 3000 + 1) rst = -1;
        answer.push_back(rst);
    }
    
    return answer;
}