#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

vector<vector<int> > map;
vector<vector<int> > origin;
vector<vector<int> > combIndex;
vector<pair<int, pair<int, int> > > q;
int N, M, D;
int rst = 0; 

void getComb() {
    vector<int> comb;

    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            for (int k = j + 1; k < M; k++) {
                comb.push_back(i);
                comb.push_back(j);
                comb.push_back(k);
                combIndex.push_back(comb);
                comb.clear();
            }
        }
    }

    // for (auto a : combIndex) {
    //     for (auto b : a) {
    //         cout << b << ' ';
    //     }
    //     cout << endl;
    // }
}

int attack(vector<vector<int> > &visited, int y, int x) {
    //cout << "curr 궁수 위치 : " << y << ", " << x << endl;
    vector<pair<int, pair<int, int> > > q;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            // 발사 거리가 D보다 크면 발사 불가
            if (i + j > D) break;
            // 발사 가능한 곳 중에 적이 있는지 확인(중복확인을 위해 visited 사용)
            if (y - i >= 0 && x - j >= 0) {
                if (map[y - i][x - j] == 1 || visited[y - i][x - j] == 1) {
                    //cout << "push cond1 : " << y - i << " " << x - j << endl;
                    q.push_back({i + j, {x - j, y - i}});
                }
            }
            if (y - i >= 0 && x + j < M) {
                if (map[y - i][x + j] == 1 || visited[y - i][x + j] == 1) {
                    //cout << "push cond2 : " << y - i << " " << x + j << endl;
                    q.push_back({i + j, {x + j, y - i}});
                }
            }
        }
    }

    // 적 탐색 실패
    if (q.empty()) {
        return 0;
    }
    else {
        // for (auto a : q) {
        //     cout << "distance : " << a.first << " ";
        //     cout << "location x : " << a.second.first << ", location y : " << a.second.second << endl;
        // }
        
        // 거리순으로 찾은 적 발견
        sort(q.begin(), q.end());
        if (map[q.begin()->second.second][q.begin()->second.first] == 0) {
            return 0;
        }
        else {
            map[q.begin()->second.second][q.begin()->second.first] = 0;
            visited[q.begin()->second.second][q.begin()->second.first] = 1;
            //cout << "kill one\n";
            return 1;
        }
    }
}

int simul(vector<int> idx) {
    
    int kill = 0;
    for (int i = 0; i < N; i++) {

        vector<vector<int> > visited;
        visited.assign(N, vector<int>(M, 0));
        // 공격
        // idx[j] 의 값은 0 ~ M - 1 의 값으로 궁수의 x 좌표를 나타낸다
        for (int j = 0; j < 3; j++) {
            kill += attack(visited, N, idx[j]);
        }

        // 공격 후 적의 이동
        for (int j = N - 1; j > 0; j--) {
            for (int k = 0; k < M; k++) {
                map[j][k] = map[j - 1][k];
            }
        }
        // 적이 이동하고 난 자리는 비워준다
        for (int k = 0; k < M; k++) {
            map[i][k] = 0;
        }
    }

    return kill;
}

void deploy() {
    // 궁수 위치 조합 구하기
    getComb();
    // 궁수의 위치 조합에 따라 전투

    for (int i = 0; i < combIndex.size(); i++) {
        map = origin;

        int temp = simul(combIndex[i]);
        // cout << "result curr stage : " << temp << endl;
        // cout << "----------------------------------------------\n";
        if (temp > rst) {
            rst = temp;
        }
    }

    return;
}

int main(void) {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> D;

    map.assign(N + 1, vector<int>(M , 0));
    origin.assign(N + 1, vector<int>(M , 0));

    int t = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> t;
            origin[i][j] = t;
            map[i][j] = t;
        }
    }

    deploy();

    cout << rst << endl;
    return 0;
}