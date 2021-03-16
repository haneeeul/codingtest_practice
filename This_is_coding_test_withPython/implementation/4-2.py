# 시각
# 하루는 86400초
# 00시 00분 00초 ~ 23시 59분 59초
# 경우의 수는 86400가지 뿐입니다
# 완전탐색문제 -> 전체 데이터의 수가 1,000,000개 이하인 경우 완전탐색에 적절하다
# 답안 예시

# H를 입력받기
h = int(input())

count = 0
for i in range(h + 1):
    for j in range(60):
        for k in range(60):
            # 매 시각 안에 '3'가 포함되어 있다면 count 변수 값 증가
            if '3' in str(i) + str(j) + str(k):
                count += 1

print(count)