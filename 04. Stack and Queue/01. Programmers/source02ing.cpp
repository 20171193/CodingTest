#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q; // baseIndex, num

    for (int i = 0; i < priorities.size(); i++)
    {
        // 최대값 갱신
        int mx = *max_element(priorities.begin(), priorities.end());

        for (int j = 0; j < priorities.size(); j++)
        {
            if (priorities[j] == mx)
            {
                q.push({ j,mx });
                priorities[j] = 0;
            }
        }
    }

    while (q.size())
    {
        answer++;
        if (q.front().first == location)
        {
            break;
        }
        else
        {
            q.pop();
        }
    }

    return answer;
}