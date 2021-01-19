#include <iostream> //cin.getline()
#include <string> //getline()
#include <cstring> // memset()

using namespace std;

/*
enum Number {
    ZRO,
    ONE,
    TWO,
    THR,
    FOR,
    FIV,
    SIX,
    SVN,
    EGT,
    NIN
};
*/

int StringToNumber(string str_num) {
    if (str_num == "ZRO") return 0;
    if (str_num == "ONE") return 1;
    if (str_num == "TWO") return 2;
    if (str_num == "THR") return 3;
    if (str_num == "FOR") return 4;
    if (str_num == "FIV") return 5;
    if (str_num == "SIX") return 6;
    if (str_num == "SVN") return 7;
    if (str_num == "EGT") return 8;
    if (str_num == "NIN") return 9;
    return -1;
}

string NumberToString(int num) {
    if (num == 0) return "ZRO";
    if (num == 1) return "ONE";
    if (num == 2) return "TWO";
    if (num == 3) return "THR";
    if (num == 4) return "FOR";
    if (num == 5) return "FIV";
    if (num == 6) return "SIX";
    if (num == 7) return "SVN";
    if (num == 8) return "EGT";
    if (num == 9) return "NIN";
    return "err";
}


int main(int argc, char** argv)
{
    int test_case, T;
    cin >> T;
	
	for(test_case = 1; test_case <= 1; ++test_case)
	{
        string str;
        int count_num [10]; // 0 to 9
        memset(count_num, 0, sizeof(count_num));
        int n = 0;
        
        cin >> str; // dummy input #1, 2, 3 ...
        cin >> n; // the number of word. not length of string
        for (int i = 0; i < n; ++i) {
            cin >> str;
            //cout << "input string: " << str << endl;
            count_num[StringToNumber(str)]++;
        }

        cout << "#" << test_case << "\n";
        for (int i = 0; i < 10; ++i) {
            cout << "count_num[" << i << "] : " << count_num[i] << endl;
            for (int j = 0; j < count_num[i]; ++j) {
                cout << NumberToString(i) << ' '; 
            }
        }
        cout << "\n";
    }
	return 0;
}