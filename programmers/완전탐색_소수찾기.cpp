#include <string>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

vector<vector<int> > perm;
vector<int> temp;
int used[7] = {0, 0, 0, 0, 0, 0, 0};

void permutation(vector<int> &nums, int n, int r) {
    if (temp.size() == r) {
        perm.push_back(temp);
        return;
    }
    
    for (int i = 0; i < n; ++i) {
        if (used[i] == 1) continue;
        used[i] = 1;
        temp.push_back(nums[i]);
        permutation(nums, n, r);
        temp.pop_back();
        used[i] = 0;
    }
}

bool isPrime(int n) {
    // 자신의 제곱근까지만 나눠보기
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> nums;
    set<int> s;
    
    for (auto s : numbers) {
        nums.push_back(s - '0');
    }
    
    for (int i = 1; i <= nums.size(); ++i) {
        permutation(nums, nums.size(), i);
    }
    
    for (int i = 0; i < perm.size(); ++i) {
        string str = "";
        for (int j = 0; j < perm[i].size(); ++j) {
            str += to_string(perm[i][j]);
        }
        
        s.insert(stoi(str));
    }

    for (auto a : s) {
        //cout << a << endl;
        if (isPrime(a) && a != 1 && a != 0) {
            //cout << "Prime is " << a << endl;
            answer++;
        }
    }
    
    return answer;
}