#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 1000;
    if (s.length() == 1) {
        return 1;
    }

    vector<pair<string, int> > compres;
    int len = s.length();
    string temp = s;
    string piece;

    for (int i = 1; i < len / 2 + 1; i++) {
        for (int j = 0; j < len; j += i) {
            piece = temp.substr(j, i);

            if (compres.empty()) {
                compres.push_back(make_pair(piece, 1));
                //cout << "first push_back: " << piece << " and the number of count is " << 1 << endl;
                continue;
            }
            if (!piece.compare(compres.back().first)) { // 현재 단어가 직전 단어 조각과 같은 경우
                compres.back().second += 1;
                //cout << "add number 1 and the piece value is " << piece << endl;
            }
            else { // 현재 단어가 직전 단어 조각과 같지 않은 경우
                compres.push_back(make_pair(piece, 1));
                //cout << "push_back: " << piece << " and the number of count is " << 1 << endl;
            }
        }
        int totalLen = 0;
        for (int k = 0; k < compres.size(); k++) {
            if (compres[k].second > 1) { // 1개인 경우는 문자열 길이에 포함하지 않는다
                totalLen += (compres[k].second / 10) + 1; // 자릿수 더해주기
            }
            totalLen += compres[k].first.length();
            //cout << "piece is " << compres[k].first << " and length is " << compres[k].first.length() << endl;
        }
        compres.clear();
        if (totalLen < answer) answer = totalLen;
        //cout << "totalLen is " << totalLen << endl;
    }
    return answer;
}

int main(void) {
    string s;
    cin >> s;
    int rst = solution(s);
    cout << "Answer is " << rst << endl;
    return 0;
}