#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Node {
public:
	Node() {
		root = 0;
		left = 0;
		right = 0;
		data = "";
	}
	Node(int rt, int l, int r, string c) : root(rt), left(l), right(r), data(c) {}
	int root;
	int left;
	int right;
	string data;
};

string answer = "";

// in-order traversal
void inorder(vector<Node> &t, int idx) {
	if (idx) {
		inorder(t, t[idx].left);
		answer += t[idx].data;
		inorder(t, t[idx].right);
	}
}

int main(int argc, char** argv)
{
    int test_case;
	int T = 10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{	
		int cnt;
		string str;
		vector<Node> tree;
		cin >> cnt;

		tree.resize(cnt + 1);
		for (int i = 1; i <= cnt; ++i) {
			cin >> tree[i].root;
			cin >> tree[i].data;
			// because it is complete binary tree
			if (i * 2 <= cnt) {
				cin >> tree[i].left;
			} else {
				tree[i].left = 0;
			}
			if (i * 2 < cnt) {
				cin >> tree[i].right;
			} else {
				tree[i].right = 0;
			}
		}

		answer.clear();
		inorder(tree, 1);
        cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}