import sys
num1 = int(sys.stdin.readline()) # input()보다 속도가 빠르다
num2 = int(sys.stdin.readline())

# result = num1 * num2
# rst_units = num1 * (num2 % 10)
# num2 = num2 // 10
# rst_ten_units = num1 * (num2 % 10)
# num2 = num2 // 10
# rst_hnd_units = num1 * num2

# print(rst_units)
# print(rst_ten_units)
# print(rst_hnd_units)
# print(result)

result = num1 * num2
while num2:
    print(num1 * (num2 % 10))
    num2 = num2 // 10

print(result)

'''
num1 = int(input())
num2 = input() # string

print(num1 * int(num2[2]))
print(num1 * int(num2[1]))
print(num1 * int(num2[0]))
print(num1 * int(num2))
'''