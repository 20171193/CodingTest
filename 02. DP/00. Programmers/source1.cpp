// 프로그래머스 레벨2 땅따먹기

#include <iostream>
#include <vector>
using namespace std;

int dp[100001][4];

int solution(vector<vector<int>> land)
{
    int answer = 0;

    for (int i = 0; i < land.size(); i++)
    {
        for (int j = 0; j < land[i].size(); j++)
        {
            if (i == 0) // 첫 행
            {
                dp[i][j] = land[i][j];
            }
            else
            {
                int mx = -1, index = -1;
                for (int k = 0; k < 4; k++) // 이전 행 확인
                {
                    if (j == k) continue;   // 같은 열일 경우 continue;

                    if (mx < dp[i - 1][k])  // 가장 큰 값 +
                    {
                        mx = dp[i - 1][k];
                        index = k;
                    }
                }
                // dp[i][j] = land[i][j] + (dp[i-1][k(k는 j가 아님)] 중 가장 큰 값) 
                dp[i][j] = land[i][j] + mx;
            }
        }
    }


    for (int i = 0; i < 4; i++)
    {
        answer = max(dp[land.size() - 1][i], answer);
    }
    return answer;
}