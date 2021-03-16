# 만들 수 없는 금액
# 왜 그리디인지 이해 불가

# 동전을 다 더해서 모든 경우의 수를 나열하고 찾는게 아니라 (처음 생각한 방법, 오래 걸린다/구현도 어렵다)
# 그냥 작은 것부터 더해보고 미리 설정한 최소값과 비교하는 방법

# 풀이
'''
n = int(input())
data = list(map(int, input().split()))
data.sort() # 최솟값부터

target = 1 # 만들 수 있는 최소 금액은 1원부터 시작합니다
for x in data:
    # 만들 수 없는 금액을 찾았을 때 반복 종료
    if target < x:
        break
    target += x

# 만들 수 없는 금액을 찾았을 때 반복 종료
print(target)
'''