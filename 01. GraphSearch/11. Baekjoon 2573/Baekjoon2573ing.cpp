// ���� 2573�� ����

// ������ ���̰� 1�⸶�� �پ��ִ� 0�� ����� ĭ�� ������ŭ �پ��.
// ������ �� ��� �̻����� �и��Ǵ� ������ �ð��� ���϶�.

// - 1. ���� ���� ���ϱ� (������ 2�� �̻��� �Ǹ� break)
// - 2. �� ������ �پ��ִ� 0�� ���� ���ϱ�
// - Ž�� �������� 
// - 1. ������ �ΰ��� �������� ���
// - 2. ������ �ΰ��� ���������� ���� ���ϰ� ��� ��� ������ ���� ��� 
#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
#include <map>
using namespace std;

int n, m, a[301][301], visited[301][301];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

map<pair<int, int>, int> mountain;

void go(int y, int x)
{
	visited[y][x] = 1;
	if (mountain[{y, x}] < 1) return;

	// ���� ���̱�
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n)
			continue;
		if (visited[ny][nx])
			continue;
		if (a[ny][nx] == 0) {
			mountain[{y, x}]--;
			continue;
		}
	}

	// ���� ���� Ž��
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || nx >= m - 1 || ny < 1 || ny >= n - 1) continue;
		if (visited[ny][nx]) continue;
		if (a[ny][nx] == 0) continue;
		if (mountain[{ny, nx}] < 1) continue;

		visited[ny][nx] = 1;
		go(ny, nx);
	}
}

int search()
{
	int ret = 0;

	bool flag = 1;
	while (flag)
	{
		++ret;

		// ��������
		int domain = 0;

		// ����Ž��
		for (auto iter = mountain.begin(); iter != mountain.end(); iter++)
		{
			if (visited[iter->first.first][iter->first.second]) continue;
			if (iter->second < 1) continue;

			++domain;
			if (domain >= 2)
				return ret - 1;	//������ 2�� �̻��� ���

			go(iter->first.first, iter->first.second);
		}

		if (domain < 1)
			return 0;	// ������ �������� �ʴ°��

		// ���� ������ �ʿ� ����
		for (auto iter = mountain.begin(); iter != mountain.end(); iter++)
		{
			a[iter->first.first][iter->first.second] = iter->second;
		}
		memset(visited, 0, sizeof(visited));
	}

	return ret;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] > 0) mountain.insert({ {i,j},a[i][j] });
		}
	}
	cout << search() << '\n';

	return 0;
}
