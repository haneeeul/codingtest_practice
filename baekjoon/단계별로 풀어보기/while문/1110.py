n = 1 # 사이클 횟수
origin = input()
num = origin

while True:
    temp = ""
    if len(num) == 1: # 10보다 작은 경우
        temp = num + num
        #print(temp)
    else:
        sum = int(num[0]) + int(num[1])
        #print(sum)
        temp += num[-1:]
        temp += str(sum)[-1:]
        #print(temp)
        
    # 숫자의 시작은 0이 될 수 없다
    # 예) 01 -> 1
    if temp[0] == "0":
        temp = temp[1:]
        
    if temp == origin:
        print(n)
        break
    else:
        n += 1
        num = temp