def dfs(turns, rst, target, numbers):
    if turns >= len(numbers):
        if rst == target:
            global answer
            answer += 1
        return
        # return 위치 조심!
        
    dfs(turns + 1, rst + numbers[turns], target, numbers);
    dfs(turns + 1, rst - numbers[turns], target, numbers);

def solution(numbers, target):
    global answer
    answer = 0
    
    dfs(0, 0, target, numbers)
    
    return answer