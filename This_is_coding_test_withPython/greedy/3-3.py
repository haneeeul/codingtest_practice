# 2019 국가 교육기관 코딩 테스트
# 숫자 카드 게임

# N, M을 공백으로 구분하여 입력 받기
n, m = map(int, input().split())

result = 0
# 한 줄씩 입력받아 확인
for i in range(n):
    data = list(map(int, input().split()))
    # 현재 줄에서 '가장 작은 수' 찾기
    # min() 사용
    min_value = min(data)
    # '가장 작은 수'들 중에 가장 큰 수 찾기
    result = max(result, min_value)

print(result)