# 만약 문제의 M이 10000이 아니라 100억이 된다면
# 시간초과의 문제가 발생한다.
# 반복되는 수열의 개념을 적용해보자

# N, M, K를 공백으로 구분하여 입력받기
n, m, k = map(int, input().split())

# N개의 수를 공백으로 구분하여 입력받기
data = list(map(int, input().split()))

data.sort() # 입력받은 수를 정렬하기
first = data[n - 1] # 가장 큰 수 (최대 K번 더할 수 있다.)
second = data[n - 2] # 두번째로 큰 수

# 몫을 구하는 방법
# 1. int(A / B) 
# 2. A // B

# 반복되는 수열을 이용해서 가장 큰 수를 몇 번 더할 수 있는지 계산한다.
count = int(m / (k + 1)) * k + m % (k + 1)

result = first * (count) + second * (m - count)

print(result)