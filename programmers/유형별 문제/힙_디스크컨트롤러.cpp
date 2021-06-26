#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct comp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
        // 실행 시간이 작은 순서대로 정렬
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0, time = 0, idx = 0;

    // jobs 를 시작 시간 순서로 정렬한다.
    sort(jobs.begin(), jobs.end());

    priority_queue<vector<int>, vector<vector<int> >, comp > pq;

    // 인덱스가 존재하는 잡의 개수보다 커진 경우
    // 또는 우선순위 큐가 빈 경우에 반복문 종료
    while (idx < jobs.size() || !pq.empty()) {
        // 현재 잡의 시작 시간이
        // 시작할 수 있는 시간 (== time)보다 작거나 같은 경우
        // 현재 잡을 우선순위 큐에 넣는다.
        if (jobs.size() > idx && time >= jobs[idx][0]) {
            pq.push(jobs[idx]);
            // 다음 잡이 실행 가능한지 확인하기 위해 계속 진행
            idx++;
            continue;
        }


        // 대기 중인 잡이 있다면
        // 다음 잡을 실행하지 않고 먼저 처리
        if (!pq.empty()) {
            // 다음 작업 시작 가능 시간 = 직전 잡이 끝난 시간 + 진행할 잡의 실행 시간
            time += pq.top()[1];
            // 진행할 잡이 대기한 시간만큼 총 시간을 더해준다
            // 총 실행 시간 = 현재 시간 - 진행할 잡의 시작 시간
            answer += time - pq.top()[0];
            pq.pop();
        }
        // 대기 중인 잡이 없다면 다음 잡을 실행
        else {
            // 현재 잡의 시작 시간이
            // 시작할 수 있는 시간보다 크고
            // 대기하고 있는 잡은 없으므로
            // 현재 잡의 시작 시간으로 시작 가능 시간을 설정한다.
            time = jobs[idx][0];
        }
    }

    answer = answer / jobs.size();

    return answer;
}