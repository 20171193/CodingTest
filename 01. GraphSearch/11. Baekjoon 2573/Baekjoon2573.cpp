// 백준 2573번 빙산

// 빙산의 높이가 1년마다 붙어있는 0이 저장된 칸의 개수만큼 줄어듦.
// 빙산이 두 덩어리 이상으로 분리되는 최초의 시간을 구하라.

// - 1. 빙산 영역 구하기 (영역이 2개 이상이 되면 break)
// - 2. 각 빙산의 붙어있는 0의 개수 구하기
// - 탐색 종료조건 
// - 1. 영역이 두개로 나누어진 경우
// - 2. 영역이 두개로 나누어지기 전에 빙하가 모두 녹아 영역이 없는 경우 
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
	memset(visited, false, sizeof(visited));	// 방문 배열 초기화
	memset(meltArr, 0, sizeof(meltArr));		// 빙산 템프배열 초기화
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j]) continue;
			if (a[i][j] < 1) continue;

			ret++;	// 영역의 수 ++

			// bfs탐색
			visited[i][j] = 1;
			queue<pair<int, int>> q;
			q.push({ i,j });
			while (q.size())
			{
				pair<int, int> temp = q.front();
				q.pop();

				int meltCount = 0;	// 주변의 0(물)을 찾아 count++
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
				// temp 배열에 녹인 수치 적용
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

	// 영역이 0개 = return 0
	// 영역이 1개 = 루프(영역이 둘 이상으로 나뉠때까지 반복)
	// 영역이 2개 이상 = return years
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
