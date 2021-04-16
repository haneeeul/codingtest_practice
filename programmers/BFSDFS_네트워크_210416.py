visited = [0 for i in range(200)]

def bfs(start, n, computers):
    queue = []
    queue.append(start)
    
    while queue:
        curr = queue.pop()
        visited[curr] = 1
        for i in range(0, len(computers[curr])):
            if computers[curr][i] == 1 and visited[i] == 0:
                queue.append(i)

def dfs(start, n, computers):
    visited[start] = 1
    for i in range(0, n):
        if computers[start][i] == 1 and visited[i] == 0:
            visited[i] = 1
            dfs(i, n, computers)
    

def solution(n, computers):
    answer = 0
    
    for i in range(0, n):
        if visited[i] == 0:
            #bfs(i, n, computers)
            dfs(i, n, computers)
            answer += 1
    
    return answer