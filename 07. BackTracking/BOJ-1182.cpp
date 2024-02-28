// 백준 1182번 부분수열의 합

// 부분수열 구하기
#include <iostream>
using namespace std;

int n, s, ret, a[21];

void go(int k, int r, int c, int sum)
{
	if (r > n) return;
	if (c >= k)
	{
		if (sum == s) ret++;
		return;
	}

	go(k, r + 1, c + 1, sum + a[r]);
	go(k, r + 1, c, sum);
}

int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++)
		go(i, 0, 0, 0);

	cout << ret << '\n';

	return 0;
}