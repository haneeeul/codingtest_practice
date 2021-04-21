#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int N;
string s;
int result = INT_MIN;

int calculate(int a, int b, char op) { 
    switch (op) { 
        case '+': 
            return a + b;
        case '-': 
            return a - b;
        case '*': 
            return a * b;
    }
}

void func(int idx, int value) { 
    // 인덱스가 식의 길이 N과 같아지면 현재 결과값과 정답 중 큰 것을 반환
    if (idx >= N) { 
        result = max(result, value);
        return;
    }

    // 현재 idx가 숫자인 경우 일단 연산자에 + 추가
    char op = (idx >= 1 ? s[idx - 1] : '+');

    // 0 + 첫번째 숫자
    // 앞결과 (연산자) 현재 인덱스 숫자
    int temp = calculate(value, s[idx] - '0', op);

    // 다음 숫자 인덱스를 넣고 재귀
    // 괄호 사용하지 않고 계산하는 방법
    func(idx + 2, temp);

    // 인덱스가 마지막 숫자 + 마지막 연산자보다 작으면
    // 괄호을 씌워서 결과가 큰지 작은지 판단
    if (idx < N - 2) { 
        // 괄호를 먼저 계산해본다.
        // char to int : char - '0'(48 빼는 거!)
        temp = calculate(s[idx] - '0', s[idx + 2] - '0', s[idx + 1]);

        // 괄호 계산 결과를 사용해서 다시 계산
        temp = calculate(value, temp, op);

        func(idx + 4, temp);
    }
} 

int main(void) { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    cin >> s;
    func(0, 0);
    cout << result << "\n";
    return 0;
}