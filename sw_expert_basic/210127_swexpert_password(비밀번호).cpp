#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> & passwordMaker(vector<int> &v) {
	vector<int>::iterator iter = v.begin() + 1;
	while (iter != v.end()) {
		if (*iter == *(iter - 1)) {
			// cout << "--------------------------------------\n";
			// cout << "erase value : " << *(iter - 1) << ", " << *iter << endl;
			iter = v.erase(iter - 1, iter + 1);
			if (iter == v.begin()) {
				iter = v.begin() + 1;
			} else {
				iter--;
			}
		}
		else {
			iter++;
			//cout << "increasing iterator value\n";
		}
		// cout << "curr status : ";
		// for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		// 	cout << *it << " ";
		// }
		// cout << "\n";
	}
	return v;
}

int main(int argc, char** argv)
{
    int test_case;
	int T = 10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{	
		vector<int> origin;
		int len; 
		cin >> len;
	
		cin.ignore();
		for (int i = 0; i < len; ++i) {
			int temp = cin.get() - '0';
			origin.push_back(temp);
		}

		vector<int> rst = passwordMaker(origin);
        cout << "#" << test_case << " ";
		for (vector<int>::iterator it = rst.begin(); it != rst.end(); ++it) {
			cout << *it;
		}
		cout << "\n";
	}
	return 0;
}