#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    // 시작지점, 끝나는 지점 순서대로 정렬
    sort(routes.begin(), routes.end());
    
    //int start = routes[0][0];
    int end = routes[0][1];
    
    for (int i = 1; i < routes.size(); ++i) {
        // 사실 시작지점을 고려하지 않아도 된다.
        // 때문에 이 부분을 주석처리해도 통과
        /*
        if (start <= routes[i][0] && routes[i][0] <= end) {
            // 다음 차량 경로의 시작지점이 현재 경로 안에 있다면
            // 시작지점 갱신
            start = routes[i][0];
        }
        */
        
        // if (start <= routes[i][1] && routes[i][1] <= end) {
        if (routes[i][1] <= end) {
            // 다음 차량 경로의 끝지점이 현재 경로 안에 있다면
            // 끝지점 갱신
            end = routes[i][1];
        }
        
        // 다음 차량 경로의 시작 지점이 현재 경로 안에 없다면
        // 단속카메라 추가
        if (end < routes[i][0]) {
            answer += 1;
            //start = routes[i][0];
            end = routes[i][1];
        }
    }
    
    return answer;
}