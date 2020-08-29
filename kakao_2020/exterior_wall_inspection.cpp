#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b) {
    return a > b;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = -1;

    // next_permutation() ����� ���� �̸� �������� ����
    //sort(dist.begin(), dist.end(), desc); // ���α׷��ӽ�: greater<>() ����
    sort(dist.begin(), dist.end()) // ascending order also work

    for (int i = 0; i < weak.size(); i++) {
        
        // ���� �ܺ��� ��ġ���� ����ؼ� ������ �ܺ� ��ġ���� �� ��,
        // ������ �ܺ� ~ ó�� �ܺ������� �Ÿ��� ���� ���ϱ� ���� 
        // (n + ó�� �ܺ��� ����)�� weak�� �߰����ش�.
        int temp = weak[0] + n;
        for (int j = 1; j < weak.size(); j++) {
            weak[j - 1] = weak[j]; // ��ĭ�� ������ �б�
        }
        weak[weak.size() - 1] = temp;

        bool permu = true; // while�� Ż�� ����
        while (permu) {
            int idx_weak = 0;
            int idx_dist = 0;

            for (idx_dist = 0; idx_dist < dist.size(); idx_dist++) {
                int fin = weak[idx_weak] + dist[idx_dist];
                while (fin >= weak[idx_weak]) { // ���� idx_dist ģ���� �� �� �� �ִٸ�
                    idx_weak++; // ���� �������� �̵�
                    if (idx_weak == weak.size()) { // ������ ����(���Ƽ� ó�� ������. ���� weak[0])���� �����ߴٸ� while�� Ż��
                        break;
                    }
                }
                // while�� Ż���� ������ ������ �������� ������ ������, �� �� �� ��� ���� Ȯ��
                if (idx_weak == weak.size()) {
                    break;
                }
            }

            // ���������� �����ߴٸ� answer �� ����
            if (idx_weak == weak.size()) {
                if (answer == -1 || idx_dist + 1 < answer) {
                    answer = idx_dist + 1;
                }
            }
            // ģ������ ������ �ٲ㼭 �ٽ� ��Ʈ��ŷ
            permu = next_permutation(dist.begin(), dist.end());
        }
    }
    return answer;
}

int main(void) {
    return 0;
}
