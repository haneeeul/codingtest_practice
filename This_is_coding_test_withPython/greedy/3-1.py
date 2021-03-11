# 2019 국가 교육기관 코딩 테스트
# 큰 수의 법칙
# 핵심: 입력값 중에서 가장 큰 수와 두번째로 큰 수만 저장한다.
# 연속으로 더할 수 있는 횟수는 K번이므로 가장 큰 수를 K번 더하고
# 두번째로 큰 수를 한 번 더하는 연산을 반복한다.

# N, M, K를 공백으로 구분하여 입력받기
n, m, k = map(int, input().split())

# N개의 수를 공백으로 구분하여 입력받기
data = list(map(int, input().split()))

data.sort() # 입력받은 수를 정렬하기
first = data[n - 1] # 가장 큰 수 (최대 K번 더할 수 있다.)
second = data[n - 2] # 두번째로 큰 수

result = 0

while True:
    for i in range(k): # 가장 큰 수를 K번 더한다
        if m == 0:
            braek
        result += first
        m -= 1 # 더한 횟수를 차감한다
    if m == 0: # M이 0이라면 반복문 탈출
        break
    result += second # 두번째로 큰 수를 한 번 더해준다
    m -= 1 # 더한 횟수를 차감한다.

print(result) # 답 출력