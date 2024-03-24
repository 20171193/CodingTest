// ���� 1455�� ������||

// �� 0, �� 1
// ��� ���� �ո�����

// �������� �����ؼ� 1�� ���� ��ǥ�� ��� ����
// ���������� 1�� ���� ��ǥ�� �������� ������

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