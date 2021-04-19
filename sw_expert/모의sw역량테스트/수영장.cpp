/////////////////////////////////////////////////////////////////////////////////////////////
// 모의 sw 역량테스트 1952. 수영장
// 시간 : 50개 테스트케이스를 합쳐서 C의 경우 3초 / C++의 경우 3초 / Java의 경우 3초 / Python의 경우 15초
// 메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
// DP 문제라는 것에서 힌트를 얻어 코드 작성
// 코드 스펙
// 12,688 kb
// 메모리
// 14 ms
// 실행시간
// 2,959
// 코드길이
/////////////////////////////////////////////////////////////////////////////////////////////

/*
    코드가 아주 좋아서 참고용...
#include<stdio.h>
int t, tc, ans;
int A, B, C, D;
int plan[12];
 
void dfs(int depth, int cost) {
 
    if (depth >= 12) {
        if (ans > cost)
            ans = cost;
        return;
    }
 
    dfs(depth + 1, cost + plan[depth]);
    dfs(depth + 3, cost + C);
 
}
 
int main(void) {
    scanf("%d", &t);
 
    while (tc < t) {
        tc++;
        scanf("%d %d %d %d", &A, &B, &C, &D);
        for (int i = 0; i < 12; i++) {
            scanf("%d", &plan[i]);
            plan[i] *= A;
            if (plan[i] > B) plan[i] = B;
        }
 
        ans = D;
 
        dfs(0, 0);
 
 
 
        printf("#%d %d\n", tc, ans);
    }
}
*/
// 훨씬 빠르고 메모리도 아주 조금 필요로 한다... 문제를 잘 이해해서 이런 코드를 짜도록 하자
// 144 kb
// 메모리
// 5 ms
// 실행시간
// 512
// 코드길이

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		int daily, monthly, quarterly, yearly;
        vector<int> plans(12, 0);
        vector<int> answer(12 + 3, 0);
        int ans = 0;

        cin >> daily >> monthly >> quarterly >> yearly;
        for (int i = 0; i < 12; i++) {
            cin >> plans[i];
        }

        plans.push_back(0); // 13월(11월 12월 다음 해 1월로 3개월 정액권)
        plans.push_back(0); // 14월(12월 다음 해 1월 2월로 3개월 정액권)

        answer[0] = 0; // 0월 
        answer[1] = min(daily * plans[0], monthly);
        //cout << "1월 금액 : " << min(daily * plans[0], monthly) << endl;
        answer[2] = min(daily * plans[1], monthly) + answer[1];
        //cout << "2월 금액 : " << min(daily * plans[1], monthly) << endl;
        //cout << "2월까지의 금액 : " << min(daily * plans[1], monthly) + answer[1] << endl;

        for (int i = 3; i < 15; i++) {
            answer[i] = min(min(daily * plans[i - 1], monthly) + answer[i - 1], quarterly + answer[i - 3]);

            /* cout << daily * plans[i - 1] << " " << monthly << endl;
            cout << i << "월 금액 : " << min(daily * plans[i - 1], monthly) << endl;
            cout << "3개월 끊으면 지금까지 금액 : " << quarterly + answer[i - 3] << endl;
            cout << i << "월까지의 금액 : " << answer[i] << endl;
            cout << endl; */
        }

        if (*(answer.end() - 1)  > yearly) {
            ans = yearly;
        }
        else {
            ans = *(answer.end() - 1);
        }

        cout << "#" << test_case << " " << ans << '\n';

		/////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;
    //정상종료시 반드시 0을 리턴해야합니다.
}

