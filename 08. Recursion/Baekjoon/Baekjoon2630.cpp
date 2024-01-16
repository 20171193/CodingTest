// ���� 2630�� ������ �����

// 1�� : �߸� �Ͼ�� ������ ����
// 2�� : �߸� �Ķ��� ������ ����

// ��������, ��� Ǯ��
#include <iostream>
#include <math.h>
using namespace std;

int n, white = 0, blue = 0, a[129][129];
int dx[4] = { 1,0,0,1 };

void go(int x, int y, int _n)
{
	int blueCount = 0;
	for (int i = y; i < y + _n; i++)
	{
		for (int j = x; j < x + _n; j++)
		{
			if (a[i][j]) blueCount++;
		}
	}

	if (!blueCount)	white++;						// ��� ���� ���
	else if (blueCount == pow(_n, 2)) blue++;	// ��� ���� �Ķ���
	else
	{
		go(x, y, _n / 2);					// �� ��
		go(x + _n / 2, y, _n / 2);			// �� ��
		go(x + _n / 2, y + _n / 2, _n / 2);	// �� ��
		go(x, y + _n / 2, _n / 2);			// �� ��
	}
	return;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	go(0, 0, n);
	cout << white << '\n' << blue << '\n';

	return 0;
}
