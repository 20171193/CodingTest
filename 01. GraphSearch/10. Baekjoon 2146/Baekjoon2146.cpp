// ���� 2146�� �ٸ� �����

// - bfs�� ����Ž��
// - �� ������ �������� ���� �������� ���� ª�� ���� ����

#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int n, a[101][101], visited[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int bfs()
{
	int domain = 0;

	// ���� Ž�� (1,2,...,domain ����)
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (visited[y][x]) continue;
			if (a[y][x] == 0) continue;
			++domain;	// ������ ���� ����
			queue<pair<int, int>> q;
			q.push({ y,x });
			a[y][x] = domain;
			visited[y][x] = 1;
			while (q.size())
			{
				pair<int, int> temp = q.front(); q.pop();
				for (int i = 0; i < 4; i++)
				{
					int nx = dx[i] + temp.second;
					int ny = dy[i] + temp.first;
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (visited[ny][nx]) continue;
					if (a[ny][nx] == 0) continue;

					visited[ny][nx] = 1;
					a[ny][nx] = domain;		// ������ ���� ���� �ο�
					q.push({ ny,nx });
				}
			}
		}
	}


	int mn = 987654321;
	// ������ �ּ� ���� Ž��
	for (int i = 1; i <= domain; i++)
	{
		// visited�迭 �ʱ�ȭ
		memset(visited, 0, sizeof(visited));
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				// i�� ������ �������� Ž��
				if (a[y][x] == i)
				{
					queue<pair<int, int>> q;
					q.push({ y,x });
					visited[y][x] = 1;
					while (q.size())
					{
						pair<int, int> temp = q.front(); q.pop();
						for (int j = 0; j < 4; j++)
						{
							int nx = dx[j] + temp.second;
							int ny = dy[j] + temp.first;
							if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
							if (visited[ny][nx])	// �̹� �湮�� �� �ϰ�� 
							{
								// �Ÿ� ���� 
								visited[ny][nx] = min(visited[temp.first][temp.second] + 1, visited[ny][nx]);
								continue;
							}

							// ���� Ž���ϴ� ������ ��� ��� 1�� �ʱ�ȭ
							if (a[ny][nx] == i) visited[ny][nx] = 1;
							// �� ������ ��� �Ÿ�+1
							else if (a[ny][nx] == 0) visited[ny][nx] = visited[temp.first][temp.second] + 1;
							// �ٸ� ������ ã�� ��� ���� ª�� �Ÿ� ����
							// �������� �������� �Ÿ��� �ƴ� �ٸ��� ���� ����̱� ������ -1
							else
							{
								mn = min(visited[temp.first][temp.second] - 1, mn);
								continue;
							}
							q.push({ ny,nx });
						}
					}

				}
			}
		}
	}
	return mn;
}

int main()
{
	cin >> n;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cin >> a[y][x];
		}
	}

	cout << bfs() << '\n';

	return 0;
}