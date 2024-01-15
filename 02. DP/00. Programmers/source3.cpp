// 프로그래머스 레벨2 숫자 변환하기

// dp + bfs 풀이
#include <string>
#include <vector>
#include <queue>
using namespace std;

int dp[1000001];

int solution(int x, int y, int n)
{
    int answer = 0;

    queue<int> q;
    q.push(x);
    dp[x] = 1;
    while (q.size())
    {
        int temp = q.front(); q.pop();
        for (int i = 1; i <= 3; i++)
        {
            int nPos = 0;
            if (i == 1) nPos = temp + n;
            else nPos = temp * i;

            if (nPos > y) continue;

            if (dp[nPos])
            {
                dp[nPos] = min(dp[nPos], dp[temp] + 1);
            }
            else
            {
                dp[nPos] = dp[temp] + 1;
                q.push(nPos);
            }
        }
    }
    answer = dp[y] - 1;

    return answer;
}
