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

int n, m, a[301][301], visited[301][301], meltArr[301][301];


int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

int search()
{
	memset(visited, false, sizeof(visited));	// �湮 �迭 �ʱ�ȭ
	memset(meltArr, 0, sizeof(meltArr));		// ���� �����迭 �ʱ�ȭ
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j]) continue;
			if (a[i][j] < 1) continue;

			ret++;	// ������ �� ++

			// bfsŽ��
			visited[i][j] = 1;
			queue<pair<int, int>> q;
			q.push({ i,j });
			while (q.size())
			{
				pair<int, int> temp = q.front();
				q.pop();

				int meltCount = 0;	// �ֺ��� 0(��)�� ã�� count++
				for (int k = 0; k < 4; k++)
				{
					int nx = temp.second + dx[k];
					int ny = temp.first + dy[k];

					if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
					if (visited[ny][nx]) continue;
					if (a[ny][nx] < 1)
					{
						meltCount++;
						continue;
					}

					visited[ny][nx] = 1;
					q.push({ ny,nx });
				}
				// temp �迭�� ���� ��ġ ����
				meltArr[temp.first][temp.second] = max(0, a[temp.first][temp.second] - meltCount);
			}
		}
	}
	memcpy(a, meltArr, sizeof(a));
	return ret;
}


int solve()
{
	int years = -1;

	// ������ 0�� = return 0
	// ������ 1�� = ����(������ �� �̻����� ���������� �ݺ�)
	// ������ 2�� �̻� = return years
	int domain = 0;
	do {
		domain = search();
		years++;
	} while (domain == 1);

	if (domain == 0) return 0;
	else return years;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << solve() << '\n';

	return 0;
}
