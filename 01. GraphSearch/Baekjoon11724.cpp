// 백준 11724번 연결 요소의 개수

// 영역의 개수 구하기 - bfs탐색
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, u, v, ret, visited[1001];
vector<vector<int>> vec(1001);
void bfs()
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			ret++;
			q.push(i);
			visited[i] = 1;
			while (q.size())
			{
				int temp = q.front(); q.pop();

				for (int j = 0; j < vec[temp].size(); j++)
				{
					if (visited[vec[temp][j]]) continue;
					if (!vec[temp][j]) continue;

					visited[vec[temp][j]] = 1;
					q.push(vec[temp][j]);
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
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	bfs();

	cout << ret << '\n';
	return 0;
}