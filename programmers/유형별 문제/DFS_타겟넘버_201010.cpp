#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Count = 0;
void DFS(int idx, int num, int target, vector<int> & numbers);

int solution(vector<int> numbers, int target) {
    int answer = 0;

    DFS(0, 0, target, numbers);

    answer = Count;
    return answer;
}

void DFS(int idx, int num, int target, vector<int> &numbers) {
    if (idx == numbers.size()) {
        if (num == target) {
            Count += 1;
        }
        return;
    }
    
    DFS(idx + 1, num + numbers[idx], target, numbers);
    DFS(idx + 1, num - numbers[idx], target, numbers);

    return;
}

int main(void) {
    vector<int> arr;
    int n, temp, target;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        arr.push_back(temp);
    }
    cin >> target;

    int rst = solution(arr, target);

    cout << rst << endl;
    return 0;
}