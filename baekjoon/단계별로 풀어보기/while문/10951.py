while True:
    try:
        A, B = map(int, input().split(' '))
        print(A+B)
    except EOFError:
        break

'''
import sys

lines = sys.stdin.readlines() # 파일의 끝까지 다 가져온다
for line in lines:
    A, B = map(int, line.split())
    print(A+B)
'''