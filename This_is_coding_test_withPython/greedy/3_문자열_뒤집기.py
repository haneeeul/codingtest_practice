# 문자열 뒤집기
# 직접 풀이
import numpy

data = input()
mem = list(0 for i in range(len(data)))

for i, a in enumerate(data):
    if len(data) == (i + 1):
        break

    if a == data[i + 1]:
        mem[i + 1] = mem[i]
    else:
        mem[i + 1] += (mem [i] + 1)

print(mem)
# 1을 뒤집을지 0을 뒤집을지 세지 않아서 <- 틀린 이유
# 총 몇번 뒤집어야 하는지만 셌다. (경우의 수를 구분하지 않음)
# 0이 아닌 최솟값을 찾는 방법은?

x = numpy.array(mem)
print(min(x[numpy.where(x > 0)]))

# 풀이
'''
data = input()
count_0 = 0 # 전부 0으로 바꾸는 경우
count_1 = 0 # 전부 1로 바꾸는 경우

# 첫번째 원소에 대해서 처리
# input()은 항상 string으로 입력을 받는다
if data[0] == '1':
    count_0 += 1
else:
    count_1 += 1

# 두번째 원소부터 모든 원소를 확인하며
for i in range(len(data) - 1):
    if data[i] != data[i + 1]:
        if data[i + 1] == '1':
            count_0 += 1 # 다음 수가 1이므로 다음 수 1을 0으로 뒤집는다.
        else:
            count_1 += 1 # 다음 수가 0이므로 다음 수 0을 1로 뒤집는다.

print(min(count_0, count_1))
'''