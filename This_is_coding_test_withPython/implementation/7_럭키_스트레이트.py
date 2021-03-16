# https://www.acmicpc.net/problem/18406
# 직접 구현

score = input()

left = 0
right = 0

for i in range(0, int(len(score) / 2)):
    left += int(score[i])

for i in range(int(len(score) / 2), len(score)):
    right += int(score[i])

if left == right:
    print("LUCKY")
else:
    print("READY")

# 풀이
'''
n = input() # string
length = len(n)
summary = 0

# 왼쪽 부분의 자릿수의 합 더하기
for i in range(length // 2):
    summary += int(n[i])

# 오른쪽 부분의 자릿수의 합 빼기
for i in range(length // 2, length):
    summary -= int(n[i])

# 왼쪽 부분과 오른쪽 부분의 자릿수 합이 동일한지 검사
if summary == 0:
    print("LUCKY")
else:
    print("READY")
'''