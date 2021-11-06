import sys

n = int(sys.stdin.readline())

for i in range(0, n):
    a, b = map(int, sys.stdin.readline().split(' '))
    print(a + b)