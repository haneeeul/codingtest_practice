#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    sort(nums.begin(), nums.end());
    int temp = 0;
    int size = 0;
    for (auto num : nums) {
        if (size == nums.size() / 2) break;
        if (temp != num) {
            temp = num;
            size += 1;
        }
        else {
            continue;
        }
    }
    
    answer = size;
    return answer;
    
    /*
    #include <unordered_map>
    
    unordered_map<int, int> hash;

    for (auto num: nums) {
        hash[num] += 1; // 키값의 중복을 제거하는 자료구조
    }

    return min(hash.size(), nums.size() / 2);
    */
}