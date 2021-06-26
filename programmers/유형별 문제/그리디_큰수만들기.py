def solution(number, k):
    answer = ''
    
    # 앞부터 큰 수를 채워 넣으면
    # 무조건 큰 수가 된다 (부문문제의 최적해가 전체문제의 최적해:그리디 가능)
    collected = []
    
    for i in range(0, len(number)):
        # list가 비어있지 않고(비어 있으면 not (listname) == True
        # 현재 collected list 가장 뒷자리 숫자가 집어넣을 숫자보다 작고(collected에서 빠져야함)
        # k 가 0보다 크면(지울 수 있는 카운트가 남아있는 경우)
        # 계속 제거
        while collected and collected[-1] < number[i] and k > 0:
            collected.pop()
            k -= 1
            
        # 지울 수 있는 카운트가 없는 경우
        # 일단 collected list 에 다 때려 넣고
        # 반복문 탈출
        # 예) 4567 k=0 인 경우 일단 다 넣고 나간다(k = 0이라서 지울 값이 없음)
        if k == 0:
            collected += number[i:]
            break
            
        # 현재 집어넣으려고 한 값을 집어넣음
        collected.append(number[i])
    
    # collected 의 크기가 (전체 문자열의 길이) - k 보다 큰 경우
    # 충분히 지워지지 않았으므로
    # 뒷자리 k 개를 지워준다
    collected = collected[:-k] if k > 0 else collected
    answer = ''.join(collected)
    
    return answer