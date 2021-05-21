/*
* 플로이드-워셜 알고리즘(Floyd-Warshall Algorithm) 사용:
* 다익스트라, 벨만-포드가 한 정점에서 다른 정점으로 가는 최단거리라면
* 플로이드-워셜은 모든 노드에서 모든 노드로 가는 최단거리를 구하는 알고리즘
* 시간복잡도가 O(n^3)인데, (i -> j 로 가는 과정과 i -> k(모든 정점) -> j 로 가는 과정을 비교하기 때문에)
* 이 문제는 노드의 수가 최대 100개이므로 시간초과에서 안전한 편
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int> > rst(n + 1, vector<int>(n + 1, 0));
    
    // 경기 결과
    // 0 : 모름
    // -1 : 짐
    // 1 : 이김
    
    for (int i = 0; i < results.size(); ++i) {
        // 경기 결과 저장
        rst[results[i][0]][results[i][1]]  = 1;
        rst[results[i][1]][results[i][0]]  = -1;
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            
            if (i == j) {
                continue;
            }
            
            // 오답
            // if (rst[i][j] == 1) {
            //     for (int k = 1; k <= n; ++k) {
            //         if (rst[j][k] == 1) {
            //             rst[i][k] = 1;
            //         }
            //     }
            // }
            
            if (rst[j][i] == 1) {
                for (int k = 1; k <= n; ++k) {
                    if (rst[i][k] == 1) {
                        rst[j][k] = 1;
                    }
                }
            }
            else if (rst[j][i] == -1) {
                for (int k = 1; k <= n; ++k) {
                    if (rst[i][k] == -1) {
                        rst[j][k] = -1;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            if (rst[i][j] == 1 || rst[i][j] == -1) cnt += 1;
        }
        if (cnt == n - 1) answer++;
    }
    
    
    return answer;
}