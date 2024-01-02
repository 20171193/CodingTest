// 프로그래머스 레벨2 더 맵게
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
        answer++;   // prev가 남아있다면 무조건 한번 더 섞어야함.
        // 한번 더 섞으면 pq.top()>= K 이기 때문에 종료. 
    }

    if (pq.empty()) return -1;   // pq에는 섞어서 K 이상의 수가 항상 들어있기 때문에 
    // pq가 비었다면 모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우

    return answer;
}