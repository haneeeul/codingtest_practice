#include <iostream>
#include <cctype> // isdigit()
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
		valid = false;
	}
	Node(int rt, int l, int r, string c, bool v) : root(rt), left(l), right(r), data(c), valid(v) {}
	int root;
	int left;
	int right;
	string data;
	bool valid;
};

bool traversal(vector<Node> &t, int idx) {

	bool left, right;
	if (isdigit(t[idx].data[0])) {
		if (t[idx].left == -1 && t[idx].right == -1) {
			t[idx].valid = true;
		}
	} else {
		if (t[idx].left != -1 && t[idx].right != -1) {
			left = traversal(t, t[idx].left);
			right = traversal(t, t[idx].right);
			if (left && right) {
				t[idx].valid = true;
			}
		}
	}
	return t[idx].valid;
}

int main(int argc, char** argv)
{
    int test_case;
	int T = 10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{	
		int cnt;
		string input;
		vector<Node> tree;
		cin >> cnt;

		tree.resize(cnt + 1);
		for (int i = 1; i <= cnt; ++i) {
			cin >> tree[i].root;
			cin >> tree[i].data;
			// complete binary tree
			if (i * 2 <= cnt) {
				cin >> tree[i].left;
			} else {
				tree[i].left = -1;
			}
			if (i * 2 < cnt) {
				cin >> tree[i].right;
			} else {
				tree[i].right = -1;
			}
			tree[i].valid = false;
		}

		bool answer = traversal(tree, 1);
        cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}