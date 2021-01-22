#include <iostream>
#include <cstring> // memset()
#include <queue>

using namespace std;

int BFS(const int p1[100], const int p2[100]);

int main(int argc, char** argv)
{
    int test_case;
	int T = 10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n, start, dest, answer = 0;
        int path1[100], path2[100];
        memset(path1, 0, sizeof(path1));
        memset(path2, 0, sizeof(path2));
        cin >> n; // dummy value
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> start;
            cin >> dest;
            if (path1[start] == 0) {
                path1[start] = dest;
            }
            else {
                path2[start] = dest;
            }
        }
        /* for (int i = 0; i < 100; ++i) {
            cout << "path1[" << i << "] : " << path1[i] << endl;
            cout << "path2[" << i << "] : " << path2[i] << endl;
        } */

        answer = BFS(path1, path2);
        cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}

int BFS(const int p1[100], const int p2[100]) {
    queue<int> q;
    int check = 0;
    int visited[100];
    memset(visited, 0, sizeof(visited));

    q.push(0); // start point
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        visited[temp] = 1;

        if (temp == 99) {
            check = 1;
            break;
        }
        else {
            if (visited[p1[temp]] == 0) {
                q.push(p1[temp]);
            }
            if (visited[p2[temp]] == 0) {
                q.push(p2[temp]);
            }
        }
    }

    return check;
}