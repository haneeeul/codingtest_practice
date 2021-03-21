# 문자열 압축
# 2020 카카오 신입 공채
# https://programmers.co.kr/learn/courses/30/lessons/60057
# 기본 코드가 제공됨
# 직접 구현 (프로그래머스에는 c++로 구현)

'''
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int len = s.length();
    int answer = len;
    if (s.length() == 1) {
        return 1;
    }

    vector<pair<string, int> > compres;
    string temp = s;
    string piece;

    for (int i = 1; i < len / 2 + 1; i++) {
        for (int j = 0; j < len; j += i) {
            piece.clear();
            piece = temp.substr(j, i);

            if (compres.empty()) {
                compres.push_back(make_pair(piece, 1));
                continue;
            }
            if (!piece.compare(compres.back().first)) { // 현재 단어가 직전 단어 조각과 같은 경우
                compres.back().second += 1;
            }
            else { // 현재 단어가 직전 단어 조각과 같지 않은 경우
                compres.push_back(make_pair(piece, 1));
            }
        }
        int totalLen = 0;
        for (int k = 0; k < compres.size(); k++) {
            if (compres[k].second > 1) { // 1개인 경우는 문자열 길이에 포함하지 않는다
                totalLen += (compres[k].second / 10) + 1; // 자릿수 더해주기
            }
            totalLen += compres[k].first.length();
        }
        compres.clear();
        if (totalLen < answer) answer = totalLen;
    }
    return answer;
}
'''

def solution(s):
    answer = len(s)
    # 1개 단위(step)부터 압축 단위를 늘려가며 확인
    for step in range(1, len(s) // 2 + 1):
        compressed = ""
        ## 문자열 파싱
        prev = s[0:step] # 앞에서부터 step만큼의 문자열 추출
        count = 1
        # 단위(stop) 크기만큼 증가시키며 이전 문자열과 비교
        for j in range(step, len(s), step):
            # 이전 상태와 동일하다면 압축 횟수(count) 증가
            if prev == s[j:j + step]:
                count += 1
            # 다른 문자열이 나왔다면(더 이상 압축하지 못하는 경우라면)
            else:
                compressed += str(count) + prev if count >= 2 else prev
                prev = s[j : j + step] # 다시 상태 초기화
                count = 1
        # 남아있는 문자열에 대해서 처리
        compressed += str(count) + prev if count >= 2 else prev
        # 만들어지는 압축 문자열이 가장 짧은 것이 정답
        answer = min(answer, len(compressed))
    return answer