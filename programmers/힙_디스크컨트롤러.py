from operator import itemgetter
import heapq

pq = []

def solution(jobs):
    answer = 0
    
    #jobs.sort(key=itemgetter(0)) # 잡을 시작시간으로 정렬
    #jobs.sort() # [][][]...[] 순서대로 정렬
    jobs.sort(key=lambda x : x[0])
    
    idx = 0 # 현재 잡을 가리키고 있는 인덱스
    start = 0
    
    while idx < len(jobs) or len(pq) != 0:
        if idx < len(jobs) and jobs[idx][0] <= start:
            heapq.heappush(pq, (jobs[idx][1], jobs[idx][0]))
            # 시작할 수 있는 시간 전에 도착한 모든 잡을 우선순위 큐에 추가한다
            # 추가할 때는 (우선순위, 값) -> (잡의 실행시간, 잡의 실행 시간)
            idx += 1
            continue
        
        if not pq:
            # 우선순위 큐가 빈 경우: 선행해서 실행할 것이 없는 경우(디스크가 놀고 있는 경우)
            # 다음에 실행할 잡의 시작 시작으로 이동한다
            # 시작 시작을 이동하는 것이므로
            # start += jobs[idx][1] # 실행시간 더해서 이동x
            start = jobs[idx][0]
        else:
            # 우선순위 큐가 비어있지 않은 경우: 선행해서 실행할 것이 있는 경우
            start += pq[0][0]
            answer += start - pq[0][1]
            
            heapq.heappop(pq) # 실행한 잡 제거
    
    return int(answer / len(jobs))