/////////////////////////////////////////////////////////////////////////////////////////////
// 모의 sw 역량테스트 1949. 등산로 조성
// 시간 : 51개 테스트케이스를 합쳐서 C의 경우 3초 / C++의 경우 3초 / Java의 경우 3초 / Python의 경우 15초
// 메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
// DFS 사용 - BFS는 실패
// 코드 스펙
// 12,696 kb
// 메모리
// 224 ms // k만큼 고도를 낮추는 과정에서 전부 다 돌아서 매우 느리다 거의 파이썬 친구임
// 실행시간
// 4,579
// 코드길이
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

vector<vector<int> > board;

int DFS(int x, int y) {

    int nx, ny, ret = 0;

    for (int n = 0; n < 4; n++) {
        nx = x + dx[n];
        ny = y + dy[n];
        if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board.size()) {
            // 등산로를 만들기 위해서는 더 작은 곳으로만 이동이 가능하므로
            if (board[nx][ny] < board[x][y]) {
                int temp = DFS(nx, ny);
                if (ret < temp) ret = temp;
            }
        }
    }

    // 등산로 1개 조성
    return ret + 1;
}

int main(int argc, char** argv)
{
    // 입출력 속도
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

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
		int N, K, rst;
        int start = -1;
        
        cin >> N;
        cin >> K;

        board.clear();
        board.assign(N, vector<int>(N, 0));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> board[i][j];
                // 최고점 찾기
                if (board[i][j] > start) {
                    start = board[i][j];
                }
            }
        }

        int answer = 1;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                // 모든 길에 대해서 1~k 만큼 고도를 내려본다.
                for (int k = 0; k <= K; k++) {
                    board[i][j] -= k;

                    for (int a = 0; a < N; a++) {
                        for (int b = 0; b < N; b++) {
                            if (board[a][b] == start) {
                                rst = DFS(a, b);
                                if (rst > answer) {
                                    answer = rst;
                                }
                            }
                        }
                    }

                	board[i][j] += k;
            	}
            }
        }
        
        cout << "#" << test_case << " " << answer << '\n';
		/////////////////////////////////////////////////////////////////////////////////////////////

	}
	return 0;
    //정상종료시 반드시 0을 리턴해야합니다.
}