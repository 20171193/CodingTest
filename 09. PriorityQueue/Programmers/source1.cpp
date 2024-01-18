// 프로그래머스 레벨2 튜플

#include <string>
#include <vector>
#include <queue>
using namespace std;

int tp[100001];

vector<int> solution(string s) {
    vector<int> answer;

    string prev = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            prev += s[i];
        }
        else
        {
            if (!prev.length()) continue;
            else
            {
                // 해당 수가 중복된 횟수
                tp[stoi(prev)]++;
                prev = "";
            }
        }
    }

    // 가장 많이 등장한 튜플이 배열의 앞부분에 위치.
    // PrioriyQueue를 사용하여 PQ 상위에 가장 많은 빈도수의 튜플을 위치시킴.
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < 100001; i++)
    {
        if (tp[i]) pq.push({ tp[i], i });
    }
    while (pq.size())
    {
        answer.push_back(pq.top().second);
        pq.pop();
    }

    return answer;
}