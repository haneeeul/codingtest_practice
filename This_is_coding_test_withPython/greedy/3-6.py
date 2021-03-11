# N이 100억 이상의 수가 되는 경우, 빠르게 동작하기 위해서는
# N이 K의 배수가 될 때까지 1씩 빼는 것도 방법이 된다.
import time

n, k = map(int, input().split())
result = 0

#start = time.time()
while True:
    # (N == K로 나누어 떨어지는 수, target)가 될 때까지 1씩 빼기
    target = (n // k) * k
    result += (n - target)
    n = target
    # N이 K보다 작을 때(더 이상 나눌 수 없을 때) 반복문 탈출
    if n < k:
        break
    # K로 나누기
    result += 1
    n //= k

# 마지막으로 남은 수에 대하여 1씩 빼기
result += (n - 1)
print(result)
#print("time(sec) : ", time.time() - start) 
'''
time(sec) :  4.982948303222656e-05 # 3-6 
time(sec):  5.412101745605469e-05 # 3-5(내코드)
'''