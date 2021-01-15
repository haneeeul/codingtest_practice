#include <iostream>
#include <string.h> // strstr()

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
	int T = 10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int dum, cnt = 0;
        char word[10], str[1000];
        
        cin >> dum;
        cin >> word; // the word for searching
        cin >> str;

        char * ptr = strstr(str, word);

        while (ptr != NULL) {
            cnt++;
            ptr = strstr(ptr + 1, word);
        }

        
        cout << "#" << test_case << " " << cnt << endl;
	}
	return 0;
}