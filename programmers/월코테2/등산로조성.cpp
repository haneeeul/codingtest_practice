/* 
/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<set>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

vector<vector<int> > board;
vector<vector<int> > length;
vector<vector<int> > visited;

/* 
BFS로 풀기에는 문제가 너무 복잡해진다.
 
int BFS(int x, int y, int n) {

    int curr_x, curr_y, max_len = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    
    while (!q.empty()) {
        curr_x = q.front().first;
        curr_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            if (curr_x + dx[i] >= 0 && curr_x + dx[i] < n && curr_y + dy[i] >= 0 && curr_y + dy[i] < n) {
                if (visited[curr_x + dx[i]][curr_y + dy[i]] == 0 && board[curr_x + dx[i]][curr_y + dy[i]] < board[curr_x][curr_y]) {
                    visited[curr_x + dx[i]][curr_y + dy[i]] = 1;
                    length[curr_x + dx[i]][curr_y + dy[i]] = length[curr_x][curr_y] + 1;
                    if (max_len < length[curr_x + dx[i]][curr_y + dy[i]]) max_len = length[curr_x + dx[i]][curr_y + dy[i]];
                    q.push(make_pair(curr_x + dx[i], curr_y + dy[i]));
                }
            }
        }
    }

    return max_len;
}

int len = 0;

void DFS(int x, int y, int n) {
    len += 1;
    for (int i = 0; i < 4; ++i) {
        if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < n) {
            if (visited[x + dx[i]][y + dy[i]] == 0 && board[x + dx[i]][y + dy[i]] < board[x][y]) {
                visited[x + dx[i]][y + dy[i]] = 1;
                //length[x + dx[i]][y + dy[i]] = length[x][y] + 1;
                DFS(x + dx[i], y + dy[i], n);
            }
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	
	for(test_case = 1; test_case <= T; ++test_case)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		int N, K, rst;
        int start = -1;
        set<int> route;

        cin >> N;
        cin >> K;

        board.clear();
        length.clear();

        board.assign(N, vector<int>(N, 0));
        length.assign(N, vector<int>(N, 0));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> board[i][j];
                if (board[i][j] > start) {
                    start = board[i][j];
                }
            }
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] == start) {
                    /* visited.clear();
                    visited.assign(N, vector<int>(N, 0));

                    visited[i][j] = 1;
                    length[i][j] = 1;

                    rst = BFS(j, i, N);
                    route.insert(rst); 

                    for (int m = 0; m < N; ++m) {
                        for (int n = 0; n < N; ++n) {
                            for (int k = K; k >= 0; --k) {
                                visited.clear();
                                visited.assign(N, vector<int>(N, 0));

                                visited[i][j] = 1;
                                //length[i][j] = 1;    

                                board[m][n] -= k;
                                //rst = BFS(j, i, N);
                                //cout << "i : " << i << " , j : " << j << " rst : " << rst << endl;
                                len = 0;
                                DFS(j, i, N);
                                rst = len;
                                cout << "i : " << i << " , j : " << j << " rst : " << rst << endl;
                                board[m][n] += k;
                                route.insert(rst);
                            }
                        }
                    }
                }
            }
        }
      
        cout << "#" << test_case << " " << << '\n';
		/////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
} */

#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> board;
long long rst = -1;

void DFS(int start, int money, long long q, long long earns, int turns) {

    cout << "q value : " << q << endl;
    cout << "turns : " << turns << endl;
    
    if (earns == q) {
        rst = turns;
        return;
    }
    else if (earns < q) {

        for (int i = 0; i < board[start].size(); i++) {
            if (board[start][i] == 0) continue;
            
            DFS(i, money, q, earns + board[start][i], turns + 1);
        }


        vector<pair<int, pair<int, int> > > s;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (start != i && board[i][j] != 0) {
                    if (q - (earns + board[i][j]) > 0) {
                        s.push_back(make_pair(q - (earns + board[i][j]), make_pair(i, j)));
                    }
                }
            }
        }
    
        if (!s.empty()) {  
            sort(s.begin(), s.end());
            cout << "q value : " << q << "\n\n";
            for (auto a : s) {
                cout << "value " << a.first << endl;
                cout << a.second.first << ", " << a.second.second << endl;
            }      
            DFS(s[0].second.first, money, q, earns + board[s[0].second.first][s[0].second.second], turns + 2);
        }
        cout << "\n";

        DFS(start, money, q, earns + money, turns + 1);

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
        rst = -1;
        DFS(0, z, queries[i], 0, 0);
        answer.push_back(rst);
    }
    
    return answer;
}

int main(void) {
    int n, k, m;
    vector<vector<int> > roads;
    vector<int> temp;

    cin >> n;
    cin >> k;
    cin >> m;

    for (int i = 0; i < m; i++) {

        temp.clear();
        int t;

        for (int j = 0; j < 3; j++) {
            cin >> t;
            temp.push_back(t);
        }
        roads.push_back(temp);
    }

    vector<long long> queries;
    while (cin >> m) {
        queries.push_back(m);
    }

    vector<long long> rst = solution(n, k, roads, queries);

    for(auto a : rst) {
        cout << a << '\n';
    }

    return 0;
}