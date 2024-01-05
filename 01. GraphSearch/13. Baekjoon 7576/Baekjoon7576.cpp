// ���� 7576�� �丶��

// ���� �丶�� �ֺ��� ���� ���� �丶����� ����.
// 1:����
// 0:���� ����
// -1:����
#include <iostream>
#include <queue>
using namespace std;

int m, n, mx, a[1001][1001], visited[1001][1001];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> q;

bool checkTomato()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0)
				return false;
			else
				mx = max(mx, visited[i][j]);
		}
	}
	return true;
}

void bfs()
{
	// ��¥���� ��üŽ��
	while (q.size())
	{
		pair<int, int> temp = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + temp.second;
			int ny = dy[i] + temp.first;

			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (a[ny][nx] != 0) continue;
			if (visited[ny][nx])
			{
				visited[ny][nx] = min(visited[temp.first][temp.second] + 1, visited[ny][nx]);
				continue;
			}
			q.push({ ny,nx });

			a[ny][nx] = 1;
			visited[ny][nx] = visited[temp.first][temp.second] + 1;
		}
	}
}

int main()
{
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) {
				q.push({ i,j });
				visited[i][j] = 0;
			}
		}
	}
	bfs();
	if (checkTomato()) cout << mx << '\n';
	else cout << -1 << '\n';
	return 0;
}


