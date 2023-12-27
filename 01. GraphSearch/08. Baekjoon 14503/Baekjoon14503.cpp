// 백준 14503번 로봇 청소기

// 1. 현재 칸 청소
// 2. 주변 모든 칸이 청소된경우
//   1. 한 칸 후진
//   2. 후진이 불가능하면 종료
// 3. 청소되지 않은 빈 칸이 있는 경우
//   1. 반시계 방향으로 회전
//   2. 앞 방향이 청소되지 않은 빈 칸일 경우 전진
//   3. 1번으로 돌아감
//


// 생각할 점
// - bfs 탐색
// - 반시계 방향으로 회전
// - 맵의 끝 부분은 모두 벽이지만, 로봇의 시작점은 항상 빈 공간
//   - 즉, 맨 끝에 로봇이 위치하면 해당 공간은 빈 공간.

// 1. 현재 칸 청소
// 2. 전방에 청소되지 않은 칸이 나올때까지 반시계 회전
//	1. 청소되지 않은 칸이 없을 경우 방향을 원상복구 한 뒤 후진
//  2. 후진이 불가능하면 종료
//  3. 가능하다면 1로 돌아감.
// 3. 청소되지 않은 칸이 있을 경우 전진 후 1로 돌아감.


#include <iostream>
#include <queue>
using namespace std;

int n, m, rx, ry, rd, a[51][51];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1,0,1,0 };

// 0북, 1동, 2남, 3서 
// 회전 - 반시계 (-1 + 4)%4

int bfs()
{
	int ret = 1;
	queue<pair<int, int>> q;
	q.push({ ry,rx });
	a[ry][rx] = 2;

	while (q.size())
	{
		pair<int, int> temp = q.front();
		q.pop();
		bool fnd = false;
		for (int i = 1; i <= 4; i++)
		{
			int nx = temp.second + dx[(rd - i + 4) % 4];
			int ny = temp.first + dy[(rd - i + 4) % 4];

			// 맵의 끝은 벽
			// 로봇이 벽에서 출발했더라도 방문체크를 한 뒤 탐색을 실시하기때문에 문제없음.
			if (nx < 1 || nx >= m - 1 || ny < 1 || ny >= n - 1) continue;
			if (a[ny][nx] > 0) continue;

			q.push({ ny,nx });
			rd = (rd - i + 4) % 4;	// 방향 갱신
			a[ny][nx] = 2;	// 청소
			fnd = true;
			ret++;
			break;
		}

		// 후진
		if (!fnd)
		{
			int nx = temp.second - dx[rd];
			int ny = temp.first - dy[rd];

			// 후진하면 벽인 경우 
			if (nx < 1 || nx >= m - 1 || ny < 1 || ny >= n - 1) return ret;
			if (a[ny][nx] == 1) return ret;
			// 청소되지 않은 공간일 경우
			if (a[ny][nx] == 0) ret++;
			q.push({ ny,nx });
		}
	}
	return ret;
}

int main()
{
	cin >> n >> m;
	cin >> ry >> rx >> rd;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << bfs() << '\n';

	return 0;
}