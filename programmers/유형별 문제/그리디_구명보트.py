def solution(people, limit):
    answer = 0
    
    # 내림차순 정렬
    people.sort(reverse=True)
    
    left = 0
    right = len(people) - 1
    
    while left < right:
        sum = people[left] + people[right]
        # 가장 작은 사람과 큰 사람을 같이 태울 수 없다면
        # 큰 사람만 태워서 보낸다
        if sum > limit:
            left += 1
        # 가장 작은 사람과 큰 사람을 같이 태울 수 있다면
        # 둘이 같이 태워서 보낸다
        else:
            left += 1
            right -= 1
        # 어찌되었든 배 하나가 출발한다
        answer += 1
    
    # 마지막 사람이 아직 안탐(짝이 안지어진 경우)
    # 모두 탄 경우 left와 right가 크로스 된다
    if left == right:
        answer += 1
    
    return answer