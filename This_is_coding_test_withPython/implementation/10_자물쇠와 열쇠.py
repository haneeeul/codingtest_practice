# 자물쇠와 열쇠
# 2020 카카오 신입 공채
# https://programmers.co.kr/learn/courses/30/lessons/60059
# 직접 구현

'''
#include <string>
#include <vector>

using namespace std;

int iscorrect(int x, int y, int N, vector<vector<int>> board, vector<vector<int>> key) {
    int M = key.size();

    for (int i = y, a = 0; i < y + M; i++, a++) {
        for (int j = x, b = 0; j < x + M; j++, b++) {
            board[i][j] = board[i][j] ^ key[a][b];
            if (!board[i][j] && key[a][b]) return -1;
        }
    }

    int cnt = 0;
    for (int i = M - 1; i < M + N - 1; i++) {
        for (int j = M - 1; j < N + M - 1; j++) {
            if (!board[i][j]) cnt++;
        }
    }
    return cnt;
}

vector<vector<int>> rotation(vector<vector<int>> key) {
    int s = key.size();
    vector<vector<int>> rst(s, vector<int>(s, 0));

    for (int i = 0, j = 0; i < s; i++, j++) {
        for (int a = s - 1, b = 0; a >= 0; a--, b++) {
            rst[j][b] = key[a][i];
        }
    }
    return rst;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    int N = lock.size();
    int M = key.size();
    vector<vector<int>> board(2 * M + N - 2, vector<int>(2 * M + N - 2, 0));

    for (int i = M - 1, a = 0; i < M - 1 + N; i++, a++) {
        for (int j = M - 1, b = 0; j < M - 1 + N; j++, b++) {
            board[i][j] = lock[a][b];
        }
    }

    for (int i = 0; i < M + N - 1; i++) {
        for (int j = 0; j < M + N - 1; j++) {
            vector<vector<int>> nextkey = key;

            for (int k = 0; k < 4; k++) {
                if (iscorrect(j, i, N, board, nextkey) == 0) {
                    answer = true;
                    return answer;
                }
                nextkey = rotation(nextkey);
            }

        }
    }
    answer = false;
    return answer;
}
'''

def rotate_90_degree(key):
    row = len(key)
    col = len(key[0])
    
    rst = [[0] * row for _ in range(col)]

    for i in range(row):
        for j in range(col):
            rst[j][(row - 1) - i] = key[i][j]
    return rst

def check_lock_status(m, n, lock):

    for i in range(n):
        for j in range(n):
            if lock[m - 1 + i][m - 1 + j] != 1:
                return False
    return True


def solution(key, lock):
    n = len(lock)
    m = len(key)

    temp_lock = [[0] * (n + (m - 1) * 2) for _ in range((n + (m - 1) * 2))]
    for i in range(n):
        for j in range(n):
            temp_lock[m - 1 + i][m - 1 + j] = lock[i][j]

    for rotation in range(4):
        key = rotate_90_degree(key)

        for x in range(n * 2 - 1):
            for y in range(n * 2 - 1):
                for i in range(m):
                    for j in range(m):
                        temp_lock[x + i][y + j] += key[i][j]
                
                if check_lock_status(m, n, temp_lock) == True:
                    return True
                else:
                    for i in range(m):
                        for j in range(m):
                            temp_lock[x + i][y + j] -= key[i][j]

    return False
    ## 런타임 에러 발생

if __name__ == "__main__":
    lock_size = int(input())
    key_size = int(input())

    # input_lock = [[0] * lock_size for _ in range(lock_size)]
    # input_key = [[0] * key_size for _ in range(key_size)]

    input_lock = [[0] for _ in range(lock_size)]
    input_key = [[0] for _ in range(key_size)]

    for i in range(key_size):
        input_key[i] = list(map(int, input().split()))
        # for j in range(key_size):
        #     input_key[i][j] = map(int, input().split())

    for i in range(lock_size):
        input_lock[i] = list(map(int, input().split()))
        # for j in range(lock_size):
        #     input_lock[i][j] = map(int, input().split())

    result = solution(input_key, input_lock)

    if result == True:
        print("true")
    else:
        print("false")

# 풀이
'''
# 2차원 리스트 90도 회전하기
def rotate_a_matrix_by_90_degree(a):
    n = len(a) # 행 길이 계산
    m = len(a[0]) # 열 길이 계산
    result = [[0] * n for _ in range(m)] # 결과 리스트
    for i in range(n):
        for j in range(m):
            result[j][n - i - 1] = a[i][j]
    return result

# 자물쇠의 중간 부분이 모두 1인지 확인
def check(new_lock):
    lock_length = len(new_lock) // 3
    for i in range(lock_length, lock_length * 2):
        for j in range(lock_length, lock_length * 2):
            if new_lock[i][j] != 1:
                return False
    return True

def solution(key, lock):
    n = len(lock)
    m = len(key)
    # 자물쇠의 크기를 기존의 3배로 변환
    new_lock = [[0] * (n * 3) for _ in range(n * 3)]
    # 새로운 자물쇠의 중앙 부분에 기존의 자물쇠 넣기
    for i in range(n):
        for j in range(n):
            new_lock[i + n][j + n] = lock[i][j]

    # 4가지 방향에 대해서 확인
    for rotation in range(4):
        key = rotate_a_matrix_by_90_degree(key) # 열쇠 회전
        for x in range(n * 2):
            for y in range(n * 2):
                # 자물쇠에 열쇠를 끼워 넣기
                for i in range(m):
                    for j in range(m):
                        new_lock[x + i][y + j] += key[i][j]
                # 새로운 자물쇠에 열쇠가 정확히 들어 맞는지 검사
                if check(new_lock) == True:
                    return True
                # 자물쇠에서 열쇠를 다시 빼기
                for i in range(m):
                    for j in range(m):
                        new_lock[x + i][y + j] -= key[i][j]
    return False
'''