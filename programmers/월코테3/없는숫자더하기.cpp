#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers)
{
    int answer = 45;

    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
    {
        answer -= *(it);
    }
    return answer;
}