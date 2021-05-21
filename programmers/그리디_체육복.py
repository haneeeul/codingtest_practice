def solution(n, lost, reserve):
    # 여벌 체육복을 가져온 학생이 체육복을 도난 당한 경우,
    # 본인이 여벌 체육복을 사용해야하므로
    # 미리 제외해준다
    _reserve = [r for r in reserve if r not in lost]
    _lost = [l for l in lost if l not in reserve]
    
    for r in _reserve:
        # 체육복을 빌려줄 수 있는 학생들 중에서
        pre = r - 1
        post = r + 1
        # 앞뒤로 안가져온 학생이 있는 경우 빌려준다(lost에서 제거한다)
        if pre in _lost:
            _lost.remove(pre)
        elif post in _lost:
            _lost.remove(post)
            
    # 체육 수업을 들을 수 있는 사람은 (전체 학생 수) - (체육복이 없는(못빌린) 학생 수)
    return n - len(_lost)