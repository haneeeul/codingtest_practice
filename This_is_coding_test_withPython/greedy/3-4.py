# 이중 반복문을 사용한 방법
n, m = map(int, input().split())

result = 0
for i in range(n):
    data = list(map(int, input().split()))
    min_value = 10001
    # 직접 작성한 코드 (min(), max() 아예 사용하지 않음)
    for j in range(m):
        if min_value > data[j]:
            min_value = data[j]
    
    if min_value > result:
        result = min_value

    # 예제 코드 
    # for a in data:
    #     min_value = min(min_value, a)
    # result = max(result, min_value)

print(result)   