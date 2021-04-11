def solution(array, commands):
    answer = []
    
    for i in range(0, len(commands)):
        subarray = array[commands[i][0] - 1:commands[i][1]]
        subarray.sort()
        answer.append(subarray[commands[i][2] - 1])
    
    return answer