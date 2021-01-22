#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
	int T = 10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int len, number, answer = 0;
        string str, num_str, answer_str = "";
        bool isFirst = false;
        cin >> len;
        cin >> str;


        for (int i = 0; i < len; ++i) {
            if (47 < str[i] && str[i] < 58) {
                num_str += str[i];
                if (str[i + 1] == '+' || str[i + 1] == '\0') {
                    number = stoi(num_str);
                    answer += number;
                    answer_str += num_str;
                    num_str.clear();
                }
            }
            else {
                if (number == answer) {
                    continue;
                }
                answer_str += '+';
            }
        }
        answer_str += '+'; // last operator '+'
        //cout << "postfix: " << answer_str << endl;
        cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}