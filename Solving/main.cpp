// 백준 1867번 돌멩이 제거

#include <iostream>
using namespace std;

int n,k,a[501][501];
int main()
{
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int y = 0;
		int x = 0;
		cin >> y >> x;
		a[y][x] = 1;
	}
	return 0;
}

