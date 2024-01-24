// 백준 2963번 섬의 개수
// 섬의 개수 - 영역의 개수 => BFS

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int t, w, h, a[51][51], visited[51][51];
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
vector<int> answer;

void bfs()
{
	int cnt = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (a[i][j] && !visited[i][j])
			{
				cnt++;
				q.push({ i,j });
				visited[i][j] = 1;
				while (q.size())
				{
					pair<int, int> temp = q.front(); q.pop();
					for (int i = 0; i < 8; i++)
					{
						int nx = dx[i] + temp.second;
						int ny = dy[i] + temp.first;
						if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
						if (visited[ny][nx]) continue;
						if (!a[ny][nx]) continue;

						visited[ny][nx] = 1;
						q.push({ ny,nx });
					}
				}
			}
		}
	}

	answer.push_back(cnt);
}

int main()
{
	while (1)
	{
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> a[i][j];
			}
		}

		bfs();
		memset(a, 0, sizeof(a));
		memset(visited, 0, sizeof(visited));
	}

	for (int i : answer)
	{
		cout << i << '\n';
	}

	return 0;
}