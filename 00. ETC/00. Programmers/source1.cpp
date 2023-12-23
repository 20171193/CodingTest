// 프로그래머스 레벨2 점프와 순간이동

using namespace std;

int solution(int n)
{
    int ans = 0;

    while (n >= 10)
    {
        ans += n % 2;
        n /= 2;
    }

    return ans;
}