#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> init_input() {

	string input;
	vector<int> num;

	cin >> input;
	for (int i = input.size() - 1; i >= 0; --i) {
		num.push_back(input[i] - '0');
	}

	return num;
}

vector<int> add_large_num(vector<int> &a, vector<int> &b) {

	int add_len, len;
	vector<int> c;

	if (a.size() < b.size()) { 
		add_len = b.size();
		len = b.size() - a.size();
		for (int i = 0; i < len; ++i) {
			a.push_back(0);
		}
		c.assign(b.size() + 1, 0); 
	} else { 
		add_len = a.size();
		len = a.size() - b.size();
		for (int i = 0; i < len; ++i) {
			b.push_back(0);
		}
		c.assign(a.size() + 1, 0);
	}
	
	for (int i = 0; i < add_len; ++i) {
		c[i] += a[i] + b[i];
		if (c[i] > 9) {
			c[i] -= 10;
			c[i + 1] += 1;
		}
	} 

	return c;
}

int main(void) {
	
	char input[2];
	vector<int> a, b;
	
	a = init_input();
	b = init_input();

	vector<int> answer = add_large_num(a, b);

	if (answer[answer.size() - 1]) cout << answer[answer.size() - 1];
	for (int i = answer.size() - 2; i >= 0; --i) {
		cout << answer[i];
	}

	return 0;
}