# 2018 E 기업 알고리즘 대회
# 1이 될 때까지
# N이 항상 K보다 크거나 같은 경우만 주어진다.

# 스스로 작성한 코드
import time

n, k = map(int, input().split())
count = 0;

#start = time.time()
while n != 1:
    if (n % k == 0):
        n /= k
    else:
        n -= 1

    count += 1

print(count)
#print("time(sec): ", time.time() - start)

# 단순하게 푸는 답안 예시
'''
n, k = map(int, input().split())
result = 0

# N이 K 이상이라면 K로 계속 나누기
while n >= k:
    # N이 K로 나누어 떨어지지 않는다면 N에서 1씩 빼기
    while n % k != 0:
        n -= 1
        result += 1
    # K로 나누기
    n //= k
    result += 1

# 마지막으로 남은 수에 대하여 1씩 빼기
while n > 1:
    n -= 1
    result += 1

print(result)
'''