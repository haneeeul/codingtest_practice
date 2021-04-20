/////////////////////////////////////////////////////////////////////////////////////////////
// 모의 sw 역량 테스트 1953. 탈주범 검거
// 시간 제한 : 최대 50개 테이트 케이스를 모두 통과하는데, C/C++/Java 모두 1초
// 메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
// 파이프가 옆에 존재한다고 무조건 연결 가능한 것이 아니다
// 옆에 있는 파이프가 연결이 가능한 모양이어야 한다!!
// 12,708 kb
// 메모리
// 18 ms
// 실행시간
// 3,453
// 코드길이
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

struct node {
    int x, y, t;
};

// 파이프별 이동 가능 방향
vector<int> pipes[8] = { {},
    {0, 1, 2, 3}, // 1. 상하좌우
    {0, 1}, // 2. 상하
    {2, 3}, // 3. 좌우
    {0, 3}, // 4. 상우
    {1, 3}, // 5. 하우
    {1, 2}, // 6. 하좌
    {0, 2}, // 7. 상좌
};
 
// 0: 상, 1: 하, 2: 좌, 3: 우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int connected[4][8] = {
    {0, 1, 1, 0, 0, 1, 1, 0},
    {0, 1, 1, 0, 1, 0, 0, 1},
    {0, 1, 0, 1, 1, 1, 0, 0},
    {0, 1, 0, 1, 0, 0, 1, 1}
};

vector<vector<int> > board;
vector<vector<int> > visited;

int BFS(int n, int m, int r, int c, int l) {
    queue<node> q;
    int loc = 0;
    
    q.push({r, c, 1});

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int times = q.front().t;
        cout << "[" << x << "][" << y << "] : " << times << endl;
        q.pop();

        if (times <= l) {
            cout << "loc add\n";
            loc += 1;
        }
        else {
            cout << "break\n";
            break;
        }

        visited[x][y] = 1;

        for (int k = 0; k < pipes[board[x][y]].size(); k++) {
            int nx = x + dx[pipes[board[x][y]][k]];
            int ny = y + dy[pipes[board[x][y]][k]];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (connected[pipes[board[x][y]][k]][board[nx][ny]] && visited[nx][ny] == 0) {
                    visited[nx][ny] = 1;
                    q.push({nx, ny, times + 1});
                }
            }
        }
    }

    return loc;
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
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		int N, M, R, C, L;
        int answer = 1;
        cin >> N >> M >> R >> C >> L;

        board.clear();
        board.assign(N, vector<int>(M, 0));
        visited.clear();
        visited.assign(N, vector<int>(M, 0));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> board[i][j];
            }
        }

        if (L == 1) answer = 1;
        else {
            answer = BFS(N, M, R, C, L);
        }

        cout << "#" << test_case << " " << answer << '\n';
		/////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}