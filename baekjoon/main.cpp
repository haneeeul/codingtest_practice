#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> preorder;
vector<int> inorder;
vector<int> postorder;

void find_preorder(int in_start, int in_end, int post_start, int post_end) {

    if (in_start > in_end || post_start > post_end) {
        return;
    }

    int root = postorder[post_end];
    preorder.push_back(root);

    vector<int>::iterator iter = find(inorder.begin(), inorder.end(), root);
    int left_len = iter - inorder.begin() - in_start;
    //int right_len = in_end - in_start - left_len;

    find_preorder(in_start, in_start + left_len - 1, post_start, post_start + left_len - 1);
    find_preorder(in_start + left_len + 1, in_end, post_start + left_len, post_end - 1);
}

int main(void) {
    
    int N;
    cin >> N;

    inorder.resize(N);
    postorder.resize(N);

    for (int i = 0; i < N; ++i) {
        cin >> inorder[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> postorder[i];
    }

    find_preorder(0, N - 1, 0, N - 1);
    
    for (int i = 0; i < N; ++i) {
        cout << preorder[i] << ' ';
    }

    return 0;
}
