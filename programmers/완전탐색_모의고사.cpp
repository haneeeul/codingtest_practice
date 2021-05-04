#include <string>
#include <vector>
#include <algorithm>

using namespace std;



vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int answer_cnt[4] = {0, 0, 0, 0};

    int secondary_giveup[4] = {1, 3, 4, 5};
    int idx = 0;

    for (int i = 0; i < answers.size(); ++i) {
        // 1번 수포자
        if (i % 5 == 0) {
            if (answers[i] == 1) {
                answer_cnt[1] += 1;
            }
        }
        else if (i % 5 == 1) {
            if (answers[i] == 2) {
                answer_cnt[1] += 1;
            }
        }
        else if (i % 5 == 2) {
            if (answers[i] == 3) {
                answer_cnt[1] += 1;
            }
        }
        else if (i % 5 == 3) {
            if (answers[i] == 4) {
                answer_cnt[1] += 1;
            }
        }
        else if (i % 5 == 4) {
            if (answers[i] == 5) {
                answer_cnt[1] += 1;
            }
        }

        // 2번 수포자
        if (i % 2 == 0) {
            if (answers[i] == 2) {
                answer_cnt[2] += 1;
            }
        }
        else if (i % 2 == 1) {
            if (answers[i] == secondary_giveup[idx % 4]) {
                answer_cnt[2] += 1;
            }
            idx++;
        }
    }

    int thrice_giveup[5] = {3, 1, 2, 4, 5};
    idx = 0;
    // 3번 수포자
    for (int i = 0; i < answers.size(); i+=2) {
        if (answers[i] == thrice_giveup[idx % 5]) {
            answer_cnt[3] += 1;
        }
        if (answers[i + 1] == thrice_giveup[idx % 5]) {
            answer_cnt[3] += 1;
        }
        idx++;
    }

    int maxx = 0;

    for (int i = 1; i <= 3; i++) {
        if (maxx < answer_cnt[i]) {
            maxx = answer_cnt[i];
        }
    }

    for (int i = 1; i <= 3; i++) {
        if (maxx == answer_cnt[i]) {
            answer.push_back(i);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

// 깔끔한 풀이
/* vector<int> one = {1,2,3,4,5};
vector<int> two = {2,1,2,3,2,4,2,5};
vector<int> thr = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> they(3);
    for(int i=0; i<answers.size(); i++) {
        // 5, 8, 10씩 반복되므로
        if(answers[i] == one[i%one.size()]) they[0]++;
        if(answers[i] == two[i%two.size()]) they[1]++;
        if(answers[i] == thr[i%thr.size()]) they[2]++;
    }
    // 최댓값을 찾는 방법
    int they_max = *max_element(they.begin(),they.end());
    for(int i = 0; i< 3; i++) {
        if(they[i] == they_max) answer.push_back(i+1);
    }
    return answer;
} */
