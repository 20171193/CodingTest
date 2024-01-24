// 백준 11724번 연결 요소의 개수

// 영역의 개수 구하기 - bfs탐색
#include <iostream>
#include <queue>
using namespace std;

int n, m, u, v, ret, a[1001][1001], visited[1001];

void bfs()
{
	queue<int> q;
	for (int i = 1; i < n; i++)
	{
		if (!visited[i])
		{
			ret++;
			q.push(i);
			visited[i] = 1;
			while (q.size())
			{
				int temp = q.front(); q.pop();

				for (int i = 0; i < n; i++)
				{
					if (i == temp) continue;
					if (visited[i]) continue;
					if (!a[temp][i]) continue;

					visited[i] = 1;
					q.push(i);
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		a[u][v] = 1;
		a[v][u] = 1;
	}
	bfs();
	cout << ret << '\n';
	return 0;
}