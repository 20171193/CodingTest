// 백준 2146번 다리 만들기

// - bfs로 영역탐색
// - 각 영역을 시작으로 다음 영역까지 가장 짧은 길이 도출

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

	// 영역 탐색 (1,2,...,domain 영역)
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (visited[y][x]) continue;
			if (a[y][x] == 0) continue;
			++domain;	// 영역별 고유 숫자
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
					a[ny][nx] = domain;		// 영역별 고유 숫자 부여
					q.push({ ny,nx });
				}
			}
		}
	}


	int mn = 987654321;
	// 영역간 최소 길이 탐색
	for (int i = 1; i <= domain; i++)
	{
		// visited배열 초기화
		memset(visited, 0, sizeof(visited));
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				// i번 영역을 시작으로 탐색
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
							if (visited[ny][nx])	// 이미 방문한 곳 일경우 
							{
								// 거리 갱신 
								visited[ny][nx] = min(visited[temp.first][temp.second] + 1, visited[ny][nx]);
								continue;
							}

							// 현재 탐색하는 영역일 경우 모두 1로 초기화
							if (a[ny][nx] == i) visited[ny][nx] = 1;
							// 빈 영역일 경우 거리+1
							else if (a[ny][nx] == 0) visited[ny][nx] = visited[temp.first][temp.second] + 1;
							// 다른 영역을 찾은 경우 가장 짧은 거리 갱신
							// 영역에서 영역간의 거리가 아닌 다리를 놓는 경우이기 때문에 -1
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