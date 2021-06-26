#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    
    int curr_w = 0;
    int idx = 0;
    while (1) {
        // 마지막 트럭이 출발한 이후
        if (idx == truck_weights.size()) {
            answer += bridge_length;
            break;
        }

        // 시간이 1초 흐른다
        answer += 1;

        // 큐의 크기 == 흐른 시간이므로
        // 시간이 다리를 건널만큼 흐르면
        // 다리에서 하나가 빠져 나온다.
        // 트럭이 빠져나오면 현재 무게 감소
        // 그냥 시간이 지나면 0 감소
        if (q.size() == bridge_length) {
            curr_w -= q.front();
            q.pop();
        }

        // 트럭에 더 올라갈 수 있는 경우
        // 트럭을 하나 더 보내고
        // 현재 다리 위에 있는 무게가 증가한다
        if (curr_w + truck_weights[idx] <= weight) {
            q.push(truck_weights[idx]);
            curr_w += truck_weights[idx];
            idx += 1;
        }
        // 트럭이 더 올라가지 못하는 경우
        // 시간이 흐른 것을 확인하기 위해
        // 큐에 0을 추가한다.
        else {
            q.push(0);
        }
    }

    return answer;
}