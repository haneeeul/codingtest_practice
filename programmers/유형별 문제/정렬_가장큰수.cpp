#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> arr;

bool comp(string a, string b) {
    // 숫자를 더해 비교해서 더 큰 숫자 순서대로 정렬
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    // string str = "";
    // for (auto i : numbers) {
    //     if (i > 999) {
    //         // 4자리수
    //         for (int j = 1000; j > 0; j /= 10) {
    //             str += to_string(i / j);
    //             i = i % j;
    //         }
    //     }
    //     else if (i > 99) {
    //         // 3자리수
    //         for (int j = 100; j > 0; j /= 10) {
    //             str += to_string(i / j);
    //             i = i % j;
    //         }
    //     }
    //     else if (i > 9) {
    //         // 2자리수
    //         for (int j = 10; j > 0; j /= 10) {
    //             str += to_string(i / j);
    //             i = i % j;
    //         }
    //     }
    //     else {
    //         // 1자리수
    //         str += to_string(i);
    //     }
    //    
    //     arr.push_back(str);
    //     str.clear();
    // }
    
    for (auto num : numbers) {
        arr.push_back(to_string(num));
    }
    
    sort(arr.begin(), arr.end(), comp);
    
    if (*(arr.begin()) == "0") {
        answer = "0";
    }
    else {
        for (auto a : arr) {
            answer += a;
        }
    }

    return answer;
}