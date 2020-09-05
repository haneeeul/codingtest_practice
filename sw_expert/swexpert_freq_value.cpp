#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first > b.first;
	}
	else {
		return a.second > b.second;
	}
}

int main(int argc, char** argv) {

	//freopen("input.txt", "r", stdin);
	int score[101];
	vector<pair<int, int> > v;
	int student, test_case;
	cin >> test_case;

	for (int t = 1; t <= test_case; ++t) {

		cin >> student; // stdin test_case value
		memset(score, 0, sizeof(score));
		v.clear();

		for (int i = 0; i < 1000; ++i) {
			cin >> student;
			score[student]++;
		}

		// ÃÖºó°ª Ã£±â
		for (int i = 0; i <= 100; ++i) {
			v.push_back(make_pair(i, score[i]));
		}

		sort(v.begin(), v.end(), comp);

		cout << "#" << t << " " << v.front().first << "\n";
	}

	return 0;
}