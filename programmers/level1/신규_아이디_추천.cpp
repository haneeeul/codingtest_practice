#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";

    for (auto s : new_id) {
        if (s >= 97 && s <= 122) {
            answer += s;
            continue;
        }
        if (s >= 65 && s <= 90) {
            answer += s + 32;
            continue;
        }
        if (s >= 48 && s <= 57) {
            answer += s;
            continue;
        }
        if (s == '.') {
            //if (*(answer.end() - 1) != '.') {
            if (answer.back() != '.') {
                answer += s;
            }
            continue;
        }
        if (s == '_' || s == '-') {
            answer += s;
        }
        
    }
    
    // if (answer[0] == '.') {
    //     answer.erase(0, 1);
    // }
    if (answer.front() == '.') answer.erase(answer.begin());
    
    // if (answer[answer.size() - 1] == '.') {
    //     answer.erase(answer.end() - 1);
    // }
    if (answer.back() == '.') answer.pop_back();
    
    if (answer.size() == 0) {
        answer += "a";
    }
    else {
        if (answer.size() >= 16) {
            answer = answer.substr(0, 15);
            // while (answer[answer.size() - 1] == '.') {
            //     answer.erase(answer.end() - 1);
            // }
            while (answer.back() == '.') answer.pop_back();
        }
    }
    
    if (answer.size() < 3) {
        while (answer.size() < 3) {
            //answer += answer[answer.size() - 1];
            answer += answer.back();
        }
    }
    
    return answer;
}