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
		oprt = "";
		oprd = 0;
	}
	Node(int rt, int l, int r, string c, int n) : root(rt), left(l), right(r), oprt(c), oprd(n) {}
	int root;
	int left;
	int right;
	string oprt;
	double oprd;
};

double Cal(double n1, double n2, char *op) {
	if (*op == '+') {
		return n1 + n2;
	}
	if (*op == '-') {
		return n1 - n2;
	}
	if (*op == '*') {
		return n1 * n2;
	}
	if (*op == '/') {
		if (n2 == 0) {
			cout << "error: Can't divide 0\n";
		}
		return n1 / n2;
	}
	return -1;
}

double traversal(vector<Node> &t, int idx) {
	double leftdata, rightdata;
	if (t[idx].left == -1 && t[idx].right == -1) {
		return t[idx].oprd;
	}
	if (!t[idx].oprt.empty()) {
		leftdata = traversal(t, t[idx].left);
		rightdata = traversal(t, t[idx].right);
		char *op = (char *)t[idx].oprt.c_str();
		switch (*op) {
			case '+' : 
				t[idx].oprd = Cal(leftdata, rightdata, op);
			case '-' : 
				t[idx].oprd = Cal(leftdata, rightdata, op);
			case '*' : 
				t[idx].oprd = Cal(leftdata, rightdata, op);
			case '/' : 
				t[idx].oprd = Cal(leftdata, rightdata, op);
		}
	}
	return t[idx].oprd;
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
			cin >> input;
			if (isdigit(input[0]) == 0) {
				tree[i].oprt = input;
				cin >> tree[i].left;
				cin >> tree[i].right;
			} else {
				tree[i].oprd = stoi(input);
				// str to int: atoi((char *)str.c_str())
				tree[i].left = -1;
				tree[i].right = -1;
			}
		}

		double answer = traversal(tree, 1);
        cout << "#" << test_case << " " << (int)answer << endl;
	}
	return 0;
}