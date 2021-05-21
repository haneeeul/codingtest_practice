def solution(name):
    answer = 0
    
    # A로 시작하므로
    # A를 기준으로 최소로 움직여서 상하 이동하는 횟수 저장
    nextMin = [min(ord(i) - ord('A'), ord('Z')- ord(i) + 1) for i in name]
    # [0, 1, 2, 3, 4, ... , 11, 12, 13, 12, 11, 10, ... , 3, 2, 1]
    # [A, B, C, D, E, ... ,  L,  M,  N,  O,  P,  Q, ... , X, Y, Z]
    # A에서 상하로 가는 최단 횟수
    
    idx = 0
    
    while True:
        answer += nextMin[idx]
        nextMin[idx] = 0 # 만들고자 한 알파벳으로 바꾼 경우
        
        # 모두 만들고자 한 알파벳으로 바꾼 경우에
        # 리스트의 총 합은 0이다
        if sum(nextMin) == 0:
            break
        
        # 좌우 이동의 조건 : 좌우로 적게 이동하는 경우를 선택
        left = 1
        right = 1
        while nextMin[idx - left] == 0:
            left += 1
        while nextMin[idx + right] == 0:
            right += 1
        
        answer += left if left < right else right
        idx += -left if left < right else right
    
    return answer