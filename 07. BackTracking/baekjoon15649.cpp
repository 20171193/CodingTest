// ���� 15649 N�� M (1)

// 1���� n���� �ڿ��� �� �ߺ� ���� m���� �� ����
// 1 <= m <= n <= 8

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, a[9], used[9];

void go(int _n, int r)
{
	if (r == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!used[i])
		{
			used[i] = 1;
			a[_n] = i;
			go(_n + 1, r + 1);
			used[i] = 0;
		}
	}
}

int main()
{
	cin >> n >> m;
	go(0, 0);

	return 0;
}

