#include <iostream>
#include <string>
#include <vector>

#include <algorithm>

using namespace std;

bool compare(const pair<double, int>& a, const pair<double, int>& b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int> > failure;

    for (int i = 1; i <= N; ++i) {
        int reachStage = 0;
        int successStage = 0;
        for (int j = 0; j < stages.size(); ++j) {
            if (stages[j] >= i) {
                successStage += 1;
                if (stages[j] == i) {
                    reachStage += 1;
                }
            }
        }

        if (successStage == 0) {
            failure.push_back(pair<double, int>(0, i));
            continue;
        }

        double temp = (double)reachStage / (double)successStage;
        failure.push_back(pair<double, int>(temp, i));
    }

    sort(failure.begin(), failure.end(), compare);

    for (int i = 0; i < failure.size(); ++i) {
        answer.push_back(failure[i].second);
    }
    return answer;
}

int main(void) {
    int n, m, input;
    vector<int> answer, arr;
    cin >> m;
    cout << "Input value(n): ";
    cin >> n;
    cout << "Enter the value" << endl;
    for (int i = 0; i < m; ++i) {
        cin >> input;
        arr.push_back(input);
    }
    
    answer = solution(n, arr);

    for (int i = 0; i < answer.size(); ++i) {
        cout << answer[i] << "\n";
    }

    return 0;
}