#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int size = s.size();
    
    if (size % 2) {
        answer += s[size / 2];
    }
    else {
        answer = s.substr(size / 2 - 1, 2);
    }
    
    return answer;
}