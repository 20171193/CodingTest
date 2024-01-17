// 백준 2447번 별찍기(10)

// 재귀, 분할정복
// 가운데 공백
// 분할 - 작은 부분 -> 큰 부분 

#include <iostream>
using namespace std;

int n;
char a[6600][6600];

void draw(int x, int y, int _n, bool isSpace)
{
	for (int i = y; i < y + _n; i++)
	{
		for (int j = x; j < x + _n; j++)
		{
			if (isSpace || (i == y + 1 && j == x + 1)) a[i][j] = ' ';
			else a[i][j] = '*';
		}
	}
}

void go(int x, int y, int _n, bool isSpace)
{
	if (_n <= 3)
	{
		draw(x, y, _n, isSpace);
	}
	else
	{
		int div = _n / 3;

		go(x, y, div, isSpace);
		go(x + div, y, div, isSpace);
		go(x + div * 2, y, div, isSpace);

		go(x, y + div, div, isSpace);
		go(x + div, y + div, div, true);	// 가운데는 공백
		go(x + div * 2, y + div, div, isSpace);

		go(x, y + div * 2, div, isSpace);
		go(x + div, y + div * 2, div, isSpace);
		go(x + div * 2, y + div * 2, div, isSpace);
	}
}

int main()
{
	cin >> n;
	go(0, 0, n, false);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j];
		}
		cout << '\n';
	}
	return 0;
}

