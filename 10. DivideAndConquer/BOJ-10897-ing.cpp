// 백준 10897번 Inherited disease
//
// D세대의 정민이 자식을 낳으면 그 자식은 D + 1 세대
//
// 세대 별 자식 수
// 0 = 1
// 1 = 2
// 2 = 6
// 3 =
// if n > 0
// s(n) = n + 1 * s(n - 1)


#include <iostream>
using namespace std;

typedef long long ll;

const int MOD_NUMBER = 1000000007;
int d, di[101];

//       number : 현재 세대에 부여되는 번호
//            k : 세대 (레벨)
//    parentCnt : 부모의 수
// parentNumber : 이전 세대에서 부모가 몇번째 자식이었는지
void go(int number, int k, int parentCnt, int parentNumber)
{
	if (k >= d) return;

	// k의 di[k]번째 자식 찾기
	// s(n) = n+1 * s(n-1)
	if (k == 0)
	{
		cout << 1 << '\n';
		go(1, 1, 1, 1);
	}
	else
	{
		ll childCnt = (parentCnt * (k + 1)) % MOD_NUMBER;				            // k세대의 총 자식의 수
		ll childPerParent = k <= 1 ? 1 : (childCnt / parentCnt) % MOD_NUMBER;		// 총 자식의 수 / 부모의 수 = 각 부모에 속한 자식의 수

		// 몇번째 부모의 몇번째 자식인지?
		// 부모 : parentNumber
		// 자식 : childPerParent * (parentNumber-1) + di[k]
		ll result = (number + childPerParent * (parentNumber - 1) + di[k]) % MOD_NUMBER;

		cout << result << '\n';
		go((number + childCnt) % MOD_NUMBER, k + 1, childCnt % MOD_NUMBER, result - number);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> d;
	for (int i = 0; i < d; i++)
	{
		cin >> di[i];
	}
	go(0, 0, 0, 0);

	return 0;
}