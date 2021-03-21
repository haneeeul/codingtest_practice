# 외벽 점검
# 2020 카카오 신입 공채 1차
# https://programmers.co.kr/learn/courses/30/lessons/60062
# 기본 코드 제공됨
'''
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b) {
    return a > b;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = -1;

    // next_permutation() 사용을 위해 미리 내림차순 정렬
    sort(dist.begin(), dist.end(), desc); // 프로그래머스: greater<>() error

    for (int i = 0; i < weak.size(); i++) {
        
        // 시작 외벽의 위치부터 출발해서 마지막 외벽 위치까지 간 후,
        // 마지막 외벽 ~ 처음 외벽까지의 거리를 쉽게 구하기 위해 
        // (n + 처음 외벽의 길이)를 weak에 추가해준다.
        int temp = weak[0] + n;
        for (int j = 1; j < weak.size(); j++) {
            weak[j - 1] = weak[j]; // 한칸씩 앞으로 밀기
        }
        weak[weak.size() - 1] = temp;

        bool permu = true; // while문 탈출 조건
        while (permu) {
            int idx_weak = 0;
            int idx_dist = 0;

            for (idx_dist = 0; idx_dist < dist.size(); idx_dist++) {
                int fin = weak[idx_weak] + dist[idx_dist];
                while (fin >= weak[idx_weak]) { // 현재 idx_dist 친구가 더 갈 수 있다면
                    idx_weak++; // 다음 지점까지 이동
                    if (idx_weak == weak.size()) { // 마지막 지점(돌아서 처음 시작점. 원래 weak[0])까지 도달했다면 while문 탈출
                        break;
                    }
                }
                // while문 탈출의 조건이 마지막 지점까지 도착한 것인지, 더 갈 수 없어서 인지 확인
                if (idx_weak == weak.size()) {
                    break;
                }
            }

            // 마지막까지 도달했다면 answer 값 갱신
            if (idx_weak == weak.size()) {
                if (answer == -1 || idx_dist + 1 < answer) {
                    answer = idx_dist + 1;
                }
            }
            // 친구들의 순서를 바꿔서 다시 백트래킹
            permu = next_permutation(dist.begin(), dist.end());
        }
    }
    return answer;
}
'''