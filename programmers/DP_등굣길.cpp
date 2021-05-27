#include <string>
#include <vector>

using namespace std;

const long long modul = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<long long> > map(n + 1, vector<long long>(m + 1, 0));
    
    map[1][1] = 1;
    
    
// 이렇게 세로와 가로의 첫번째 줄을 1로 채울 경우,
// (1, 0) 또는 (0, 1) 이 웅덩이일 때
// 줄 전체가 갈 수 없는데 갈 수 있는 길로 표시가 된다.
    
//     for (int x = 1; x <= m; ++x) {
//         map[1][x] = 1;
//     }
    
//     for (int y = 1; y <= n; ++y) {
//         map[y][1] = 1;
//     }
    
    // 웅덩이 표시
    for (auto p : puddles) {
        map[p[1]][p[0]] = -1;
    }
    
    for (int y = 1; y <= n; ++y) {
        for (int x = 1; x <= m; ++x) {
            if (map[y][x] == -1) continue;
            if (y - 1 > 0 && map[y - 1][x] > -1) {
                map[y][x] += map[y - 1][x] % modul;
            }
            if (x - 1 > 0 && map[y][x - 1] > -1) {
                map[y][x] += map[y][x - 1] % modul;
            }
        }
    }
    
    answer = map[n][m] % modul;
    return answer;
}