#include <iostream>

using namespace std;

int exponential(int n, int m);

int main(int argc, char** argv)
{
    int test_case;
	int T = 10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n, m;
        cin >> n; // dummy value(test case number)
        cin >> n;
        cin >> m;
        int answer = exponential(n, m);
        cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}

int exponential(int n, int m) {
    if (m == 1) return n;

    return n * exponential(n, m - 1);
}