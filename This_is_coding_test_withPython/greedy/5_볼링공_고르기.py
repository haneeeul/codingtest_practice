# 볼링공 고르기
# 직접 풀이
n, m = map(int, input().split())
data = list(map(int, input().split()))
rst = 0

data.sort()

for i in range(0, len(data) - 1):
    for j in range(i + 1, len(data)):
        if data[i] != data[j]:
            rst += 1

print(rst) # 시간복잡도 O(n^2) ㅠㅠ

# 풀이
'''
n, m = map(int, input().split())
data = list(map(int, input().split()))

# 1부터 10까지의 무게를 담을 수 있는 리스트 생성
array = [0] * 11

for x in data:
    # 각 무게에 해당하는 볼링공의 개수 세기
    array[x] += 1

rst = 0
# 1부터 m까지의 각 무게에 대하여 처리
for i in range(1, m + 1):
    # 총 볼링공은 n개
    n -= array[i] # 무게가 i인 볼링공의 개수(A가 선택할 수 있는 개수) 제외
    rst += array[i] * n # B가 선택하는 경우의 수와 곱해주기
'''