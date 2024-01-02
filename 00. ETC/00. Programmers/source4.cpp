// ���α׷��ӽ� ����2 �� �ʰ�
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }

    int prev = -1;
    while (pq.size() && pq.top() < K) {
        if (prev < 0) {
            prev = pq.top();
            pq.pop();
            continue;
        }
        else {
            int temp = prev + pq.top() * 2;
            pq.pop();
            pq.push(temp);
            answer++;
            prev = -1;
        }
    }

    if (prev != -1 && prev < K) {
        answer++;   // prev�� �����ִٸ� ������ �ѹ� �� �������.
        // �ѹ� �� ������ pq.top()>= K �̱� ������ ����. 
    }

    if (pq.empty()) return -1;   // pq���� ��� K �̻��� ���� �׻� ����ֱ� ������ 
    // pq�� ����ٸ� ��� ������ ���ں� ������ K �̻����� ���� �� ���� ���

    return answer;
}