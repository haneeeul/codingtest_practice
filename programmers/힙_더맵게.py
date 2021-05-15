import heapq

# priority queue 만들기 (default: min_heap)
heap = []

def solution(scoville, K):
    answer = 0
    
    if len(scoville) < 2:
        if scoville[0] < K:
            return -1
        else:
            return 0
    
    # 리스트를 우선순위큐(min_heap)으로 변경
    # O(n)
    heapq.heapify(scoville)
    
    while len(scoville) >= 1:
        top = heapq.heappop(scoville)

        if top >= K:
            break;
        elif len(scoville) == 0 and top < K:
            answer = -1
            break
            
        top2 = heapq.heappop(scoville)
        heapq.heappush(scoville, top + top2 * 2)
        answer += 1

    
    
    return answer