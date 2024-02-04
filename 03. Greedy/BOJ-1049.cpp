// 백준 1049번 기타줄

#include <iostream>
#include <math.h>
using namespace std;

int n, m, cost, mnSix = 1001, mnOne = 1001;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int six = 0, one = 0;
		cin >> six >> one;
		mnSix = min(six, mnSix);
		mnOne = min(one, mnOne);
	}

	if (mnOne * 6 < mnSix)
		cout << n * mnOne << '\n';
	else if (mnOne * (n % 6) > mnSix)
		cout << (n / 6 + 1) * mnSix << '\n';
	else
		cout << n / 6 * mnSix + n % 6 * mnOne << '\n';
	return 0;
}