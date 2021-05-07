# 뱀
# 삼성전자 SW 역량테스트
# https://www.acmicpc.net/prolblem/3190
# 직접 풀이

n = int(input()) # 게임판의 크기
k = int(input()) # 사과 개수

board = [[0] * (n + 1) for _ in range(n + 1)]
snake = [[0] * (n + 1) for _ in range(n + 1)]
command = []

## 여기서 언더스코어는 값을 무시한다는 뜻(사용하지 않는 값)
for _ in range(k):
    x, y = map(int, input().split())
    board[x][y] = 1

l = int(input())
for _ in range(l):
    x, c = input().split()
    command.append((int(x), c))

def simulation():
    global snake[1][1] = 1
    while (global command.empty() != True):
        command.pop()
        
