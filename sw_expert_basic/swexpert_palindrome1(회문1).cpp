#include <iostream>
#include <vector>
#include <string>
#include <cstring> // memset()

using namespace std;

int find_palindrome(const vector<vector<char> > &board, int length);

int main(int argc, char** argv)
{
    int test_case;
	int T = 10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int len, cnt = 0;
        vector<vector<char> > board(16, vector<char>(8));

        cin >> len;
        for (int i = 0; i < 8; ++i) {
            string str;
            cin >> str;
            for (int j = 0; j < 8; ++j) {
                board[i][j] = str[j];
            }
        }

        // like decalcomanie!
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                board[8 + i][j] = board[j][i];
            }
        }
        // find palindrome
        if (len == 1) {
            cnt = 64;
        }
        else {
            cnt = find_palindrome(board, len);
        }
        cout << "#" << test_case << " " << cnt << endl;
	}
	return 0;
}

int find_palindrome(const vector<vector<char> > &board, int length) {

    int count = 0;
    
    // compare to both end-side of string
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (j + (length - 1) > 7) break; // check boundary

            bool check = true;
            for (int k = 0; k < (j + length) / 2; ++k) {
                if ((j + length - 1) - k > 7 || j + k > 7) break; // check boundary

                if (board[i][j + k] == board[i][(j + length - 1) - k]) {}
                else {
                    check = false;
                    break;
                }
            }
            if (check) count++;
        }
    }
    return count;
}