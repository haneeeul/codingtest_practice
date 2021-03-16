# 곱하기 혹은 더하기
# 최대한 많은 곱하기를 찾아내자
# 직접 풀이

# 연속된 문자열 입력 처리
data = input()

# 연속된 문자열로 받아서 한개씩 숫자로 변경
rst = int(data[0])

for a in data[1:]:
    num = int(a)
    if num == 0 or rst == 0:
        rst += num
    else:
        rst *= num

print(rst) # 오답, 1은 곱하기보다는 더하는 것이 유리하다! 11111 입력 시 오답(정답: 5)

# 풀이
'''
data = input()

# 첫번째 문자를 숫자로 변경하여 대입
rst = int(data[0])

for i in range(1, len(data)):
    # 두 수 중에 하나라도 0 또는 1인 경우는 더한다
    num = int(data[i])
    if num <= 1 or rst <= 1:
        rst += num
    else:
        rst *= num

print(rst)
'''