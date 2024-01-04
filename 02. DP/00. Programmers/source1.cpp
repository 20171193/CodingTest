// ���α׷��ӽ� ����2 �����Ա�

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
            if (i == 0) // ù ��
            {
                dp[i][j] = land[i][j];
            }
            else
            {
                int mx = -1, index = -1;
                for (int k = 0; k < 4; k++) // ���� �� Ȯ��
                {
                    if (j == k) continue;   // ���� ���� ��� continue;

                    if (mx < dp[i - 1][k])  // ���� ū �� +
                    {
                        mx = dp[i - 1][k];
                        index = k;
                    }
                }
                // dp[i][j] = land[i][j] + (dp[i-1][k(k�� j�� �ƴ�)] �� ���� ū ��) 
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