import heapq

def solution(operations):
    answer = []
    queue = []
    stack = []
    
    for op in operations:
        if op[0] == 'I':
            num = int(op[2:])
            heapq.heappush(queue, num)
        
        elif op[0] == 'D' and len(queue) < 1:
            continue
        elif op[0] == 'D' and len(op) > 3:
            # 최솟값 삭제
            heapq.heappop(queue)
            
        elif op[0] == 'D' and len(op) <= 3:
            # 최댓값 삭제
            '''
            while queue:
                stack.append(heapq.heappop(queue))
            
            stack.pop()
            
            while stack:
                heapq.heappush(queue, stack.pop())
            '''
            # pop() value가 최댓값임을 보장하지는 않음
            #queue.pop() # 또한 최대를 보장하지는 않음
            queue.remove(max(queue))
            
    if not queue:
        answer.append(0)
        answer.append(0)
    else:
        # heap은 가장 작은 값이(python의 힙은 min_heap임) 우선순위에 존재하도록 보장하는 자료구조이지
        # 가장 뒤에 있는 값이 가장 큰 값임을 보장하지는 않는다.
        #answer.append(queue[-1]) # 최대인지 아닌지 알 수 없음
        answer.append(max(queue))
        answer.append(queue[0])
    
    return answer