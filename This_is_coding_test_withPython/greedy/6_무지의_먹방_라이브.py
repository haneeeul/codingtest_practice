# 무지의 먹방 라이브
# 2019 카카오 신입 공채
# 직접 풀이(기본 코드 제공 됨)
# https://programmers.co.kr/learn/courses/30/lessons/42891

def solution(food_times, k):
    answer = 0
    find_next = False

    idx = 1

    for i in range(0, len(food_times)):
        idx += 1 # k초
        # 배열을 원형으로 접근 가능하도록
        if i == len(food_times) - 1:
            i = 0
        
        if idx == k:
            if time:
                answer = i + 1
            else:
                for j in range(food_time[i:i - 1]):
                    if food_time[j]:
                        answer = j + 1
                        find_next = True
                        break
                if find_next == False:
                    answer = -1
            break
        
        if food_times[i] > 0:
            food_times[i] -= 1
        else:
            idx -= 1
            continue
            
    return answer # 오답

# 풀이
## 내 사족
'''
import heapq

def solution(food_times, k):
    # 전체 음식을 먹는 시간보다 k가 크거나 같다면 -1
    ## 시간 내에 다 먹은 경우의 수를 미리 생각해보기
    if sum(food_times) <= k:
        return -1

    # 시간이 작은 음식부터 빼야 하므로 우선순위 큐를 이용
    ## 시간이 작은 음식부터 빼야 하는가?
    ## 시간이 작은 음식부터 뺀다
    ## -> 가장 시간이 적게 걸리는 음식을 모두 다 먹기 위해서는
    ## -> (남은 음식 개수) * (가장 시간이 적게 걸리는 음식을 먹는데 걸리는 시간) : 순서가 돌아와야 다 먹을 수 있으므로
    ## 이 방법은 고려해야할 것이 많다.
    ## (남은 시간)이 (가장 시간이 적게 걸리는 음식을 먹기 위한 시간)보다 작다는건
    ## 가장 시간이 적게 걸리는 음식을 먹기 전에 네트워크가 끊긴다는 것으로
    ## 이게 이해가 안되면 그냥 회전하면서 직접 세고, 확인하는 방법으로 구현해야한다. (시간복잡도 커짐)

    ## 그냥 순서대로 먹는다 -> 시간복잡도의 문제(1 <= k <= 20,000,000,000,000)
    q = []
    ## 일반 리스트를 만들고 삽입 시에 리스트에 자료구조 지정
    for i in range(len(food_times)):
        # (음식 시간, 음식 번호) 형태로 우선순위 큐에 삽입
        heapq.heappush(q, (food_times[i], i + 1))

    sum_value = 0 # 먹기 위해 사용한 시간
    previous = 0 # 직전에 다 먹은 음식 시간
    length = len(food_times) # 남은 음식의 개수

    # sum_value + (현재의 음식 시간 - 이전 음식 시간) * 현재 음식 개수와 k 비교
    while sum_value + ((q[0][0] - previous) * length) <= k:
        now = heapq.heappop(q)[0]
        sum_value += (now - previous) * length
        length -= 1 # 다 먹은 음식 제외
        previous = now # 이전 음식 시간 재설정

    # 남은 음식 중에서 몇 번째 음식인지 확인하여 출력
    result = sorted(q, key=lamda x: x[1]) # 음식의 번호 기준으로 정렬
    return result[(k - sum_value) % length][1]
'''

'''
// 로직 이해를 위한 .cpp
#include <bits/stdc++.h>

using namespace std;


bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    // 전체 음식을 먹는 시간보다 k가 크거나 같다면 -1
    long long summary = 0;
    for (int i = 0; i < food_times.size(); i++) {
        summary += food_times[i];
    }
    if (summary <= k) return -1;
    
    // 시간이 작은 음식부터 빼야 하므로 우선순위 큐를 이용
    priority_queue<pair<int, int> > pq;
    for (int i = 0; i < food_times.size(); i++) {
        // (음식 시간, 음식 번호) 형태로 우선순위 큐에 삽입
        pq.push({-food_times[i], i + 1});
    }
    
    summary = 0; // 먹기 위해 사용한 시간
    long long previous = 0; // 직전에 다 먹은 음식 시간
    long long length = food_times.size(); // 남은 음식의 개수

    // summary + (현재의 음식 시간 - 이전 음식 시간) * 현재 음식 개수와 k 비교
    while (summary + ((-pq.top().first - previous) * length) <= k) {
        int now = -pq.top().first;
        pq.pop();
        summary += (now - previous) * length;
        length -= 1; // 다 먹은 음식 제외
        previous = now; // 이전 음식 시간 재설정
    }

    // 남은 음식 중에서 몇 번째 음식인지 확인하여 출력
    vector<pair<int, int> > result;
    while (!pq.empty()) {
        int food_time = -pq.top().first;
        int num = pq.top().second;
        pq.pop();
        result.push_back({food_time, num});
    }
    sort(result.begin(), result.end(), compare); // 음식의 번호 기준으로 정렬
    return result[(k - summary) % length].second;
}
'''