#include <iostream>
#include <vector>

using namespace std;

vector<int> preorder;
vector<int> postorder;

void find_postorder(int start, int end) {

    if (start > end) {
        return;
        // 모순
    }

    bool only_left = true;
    int root = preorder[start]; // root
    preorder[start] = 0; // preorder에 존재하는 원래 값을 0으로 치환 (중복으로 postorder에 들어가는 것을 막기 위해)
    postorder.push_back(root);

    for (int i = start + 1; i <= end; ++i) {
        if (preorder[i] > root) {
            only_left = false;
            find_postorder(i, end);
            find_postorder(start + 1, i - 1);
        }
        if (preorder.size() == postorder.size()) return;
    }

    // child가 left만 존재하는 경우
    if (only_left) {
        find_postorder(start + 1, end);
    }
}

int main(void) {
    
    int n;
    while (cin >> n) { // file의 경우 EOF에서 루프문 탈출
        preorder.push_back(n);
    } // console 입력 시 ctrl + z 눌러야 한다

    find_postorder(0, preorder.size() - 1);
    
    for (int i = postorder.size() - 1; i >= 0; --i) {
        cout << postorder[i] << '\n';
    }

    return 0;
}
