// 백준 1455번 뒤집기||

// 앞 0, 뒤 1
// 모든 면을 앞면으로

// 원점부터 시작해서 1이 나온 좌표를 계속 갱신
// 최종적으로 1이 나온 좌표를 기준으로 뒤집기

#include <iostream>
using namespace std;

int n, m, a[101][101];

void Reverse(int x, int y)
{
	for (int i = 0; i <= y; i++)
	{
		for (int j = 0; j <= x; j++)
		{
			a[i][j] = a[i][j] == 1 ? 0 : 1;
		}
	}
}

bool Check()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 1)
				return false;
		}
	}
	return true;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string temp = "";
		cin >> temp;
		for (int j = 0; j < m; j++)
		{
			a[i][j] = temp[j] - '0';
		}
	}

	int ret = 0;
	while (!Check())
	{
		int x = -1, y = -1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == 1)
				{
					y = i;
					x = j;
				}
			}
		}

		if (x == -1 && y == -1)
			break;

		Reverse(x, y);
		ret++;
	}

	cout << ret << '\n';

	return 0;
}