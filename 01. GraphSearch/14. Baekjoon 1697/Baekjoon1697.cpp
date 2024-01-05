// 백준 1697번 숨바꼭질

#include <iostream>
#include <queue>
using namespace std;

int n, k, visited[200001];

// 최소 탐색 > 0
// 최대 탐색 < 100000*2

void bfs()
{
	queue<int> q;
	visited[n] = 1;
	q.push(n);

	while (q.size())
	{
		int temp = q.front();
		q.pop();

		int nPos[3] = { temp + 1, temp - 1, temp * 2 };
		for (int i = 0; i < 3; i++)
		{
			if (nPos[i] < 0 || nPos[i] >= 200000) continue;
			if (visited[nPos[i]])
			{
				visited[nPos[i]] = min(visited[temp] + 1, visited[nPos[i]]);
				continue;
			}

			q.push(nPos[i]);
			visited[nPos[i]] = visited[temp] + 1;
		}
	}
}

int main()
{
	cin >> n >> k;
	bfs();
	cout << visited[k] - 1 << '\n';
	return 0;
}