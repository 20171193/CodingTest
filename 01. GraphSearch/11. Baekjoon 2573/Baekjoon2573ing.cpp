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

int n, m, a[301][301], visited[301][301];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

map<pair<int, int>, int> mountain;

void go(int y, int x)
{
	visited[y][x] = 1;
	if (mountain[{y, x}] < 1) return;

	// 빙산 녹이기
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

	// 다음 빙산 탐색
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

		// 영역개수
		int domain = 0;

		// 영역탐색
		for (auto iter = mountain.begin(); iter != mountain.end(); iter++)
		{
			if (visited[iter->first.first][iter->first.second]) continue;
			if (iter->second < 1) continue;

			++domain;
			if (domain >= 2)
				return ret - 1;	//영역이 2개 이상인 경우

			go(iter->first.first, iter->first.second);
		}

		if (domain < 1)
			return 0;	// 영역이 존재하지 않는경우

		// 녹인 빙산을 맵에 적용
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
