# 모함가 길드
# 최대한 많은 그룹을 만드려면 공포도가 낮은 사람들을 먼저 그룹으로 내보내야 한다 (소수정예가 많아지도록)
# 직접 작성
n = map(int, input().split())

data = list(map(int, input().split()))
rst = 0

# list sorting
# default(asc): list.sort()
# (desc): list.sort(reverse=True)5

data.sort()

for a in data:
    rst += 1
    for i in range (0, a):
        if (a < data[i]):
            break
            rst -= 1
        data.remove(data[i])

print(rst) # 오답

# 풀이
'''
n = int(input())
data = list(map(int, input().split()))
data.sort()

rst = 0 # 총 그룸의 수
cnt = 0 # 현재 그룹에 포함된 모험가의 수

for i in data:
    cnt += 1 # 현재 그룹에 모험가 포함
    if cnt >= i: # 현재 그룹에 포함된 모험가의 수가 현재 공포도(i) 이상이라면 그룹 결성
        rst += 1
        cnt = 0 # 현재 그룹의 모험가 수 초기화

print(rst)
'''