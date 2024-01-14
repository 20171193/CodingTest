// 프로그래머스 레벨2 2*n 타일링
// dp 점화식 도출
#include <string>
#include <vector>

using namespace std;

// dp1 = 1
// dp2 = 2
// dp3 = 3
// dp4 = 5
// dp5 = 8

// dp[n] = dp[n-1] + dp[n-2]


int dp[60001];

int solution(int n) {
    int answer = 0;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];

        if (dp[i] > 100000007)
            dp[i] %= 1000000007;
    }

    answer = dp[n];
    return answer;
}