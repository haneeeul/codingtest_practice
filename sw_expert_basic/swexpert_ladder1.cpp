#include<iostream>
#include<cstring>

using namespace std;

int map[100][100];
bool findX(int y, int x);

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int x = 0;
        int y = 0;
        int rst = 0;
        memset(map, 0, sizeof(map));
        
        // doesn't work 
        //freopen("input.txt", "r", stdin);
        
        cin >> rst;
        for (y = 0; y < 100; ++y) {
            for (x = 0; x < 100; ++x) {
                cin >> map[y][x];
            }
        }
        
        for (x = 0; x < 100; ++x) {
            if (map[0][x] == 1) {
                if (findX(0, x)) {
                    rst = x;
                    break;
                }
            }
        }
        cout << "#" << test_case << " " << rst << endl;
	}
	return 0;
}

bool findX(int y, int x) {

    bool find = false;
    int visited[100][100];
    memset(visited, 0, sizeof(visited));

    while (y < 100) {
        visited[y][x] = 1;
        if (map[y][x] == 2) {
            find = true;
            /*cout << "map[y][x] value: " << map[y][x] << endl;
            cout << "y: " << y << " x: " << x << endl;
            cout << "find answer" << endl;*/
            break;
        }
        if (x - 1 >= 0 && map[y][x - 1] == 1 && visited[y][x - 1] == 0) {
            x--;
        }
        else if (x + 1 < 100 && map[y][x + 1] == 1 && visited[y][x + 1] == 0) {
            x++;
        }
        else {
            y++;
        }
    }
    return find;
}