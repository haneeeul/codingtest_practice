#include <iostream>
#include <string>
#include <vector>
//#include <algorithm>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    bool isfirst, corr = true;
    int rst;
    string tmp_q, tmp_w;
    //sort(words.begin(), words.end());

    for (int i = 0; i < queries.size(); i++) {
        tmp_q = queries[i];
        rst = 0;
        for (int j = 0; j < words.size(); j++) {
            tmp_w = words[j];
            //isfirst = false;
            corr = true;
            if (tmp_w.length() == tmp_q.length()) {
                for (int k = 0; k < tmp_w.length(); k++) {
                    if (tmp_q[k] < 64) { // ? 의 아스키코드 63
                    //if (tmp_q[k] < 64 && !isfirst) {
                        //isfirst = true;
                        continue;
                    }
                    else {
                        if (tmp_q[k] - tmp_w[k]) {
                            corr = false;
                            break;
                        }
                    }
                }
            }
            else {
                corr = false;
            }
            if (corr) rst++;
        }
        answer.push_back(rst);
    }

    return answer;
}

int main(void) {
    vector<string> words;
    string word;
    for (int i = 0; i < 5; i++) {
        cin >> word;
        words.push_back(word);
    }
    vector<string> queries;
    for (int i = 0; i < 3; i++) {
        cin >> word;
        queries.push_back(word);
    }
    vector<int> rst = solution(words, queries);

    for (int i = 0; i < rst.size(); i++) {
        cout << rst[i] << endl;
    }
    
    return 0;
}