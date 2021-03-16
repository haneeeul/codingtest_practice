# 문자열 재정렬
# Facebook interview
# 직접 구현

data = input()
rst = []
num = 0

for a in (data):
    ## 이제는 외우자 좀 0 == 48, A == 65, a == 97
    if ord(a) > 64:
        rst.append(a)
    else:
        num += int(a)

rst.sort()
rst.append(str(num))

print(''.join(rst)) # 오답. 숫자가 없는 경우 (결과값이 0이 된다) 고려하지 않음
# 정답 BDKSHE -> BDEHKS
# 오답 BDKSHE -> BDEHKS0

# 풀이
'''
data = input()
result = []
value = 0

# 문자를 하나씩 확인하며
for x in data:
    # 알파벳인 경우 결과 리스트에 삽입
    if x.isalpha():
        result.append(x)
    # 숫자는 따로 더하기
    else:
        value += int(x)

# 알파벳을 오름차순으로 정렬
result.sort()

# 숫자가 하나라도 존재하는 경우 가장 뒤에 삽입
if value != 0:
    result.append(str(value))

# 최종 결과 출력(리스트를 문자열로 변환하여 출력)
print(''.join(result))
'''