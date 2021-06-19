#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer;
    int input_x = x;
    int sum = 0;
    
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    
    if (input_x % sum) answer = false;
    else answer = true;
    
    return answer;
}