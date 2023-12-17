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

#include <iostream>
#include <queue>
using namespace std;

struct robot {
	int x, y, d;
};

int n, m,cnt, a[51][51], visited[51][51];
// d - 북, 서, 남, 동 (문제와 반대로 설정)
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1,0 };

void go(robot _r, bool b) {
	if (_r.x < 0 || _r.x >= m || _r.y < 0 || _r.y >= n) return;
	if (a[_r.y][_r.x]) return;
	if (visited[_r.y][_r.x]) return;
	bool back = true;
	cnt++;
	visited[_r.y][_r.x] = 1;
	int nd = 0, nx = 0, ny = 0;
	for (int i = 0; i < 4; i++) {
		nd = (_r.d + i) % 4;
		nx = dx[nd] + _r.x;
		ny = dy[nd] + _r.y;
		
		if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
		if (visited[ny][nx]) continue;
		if (a[ny][nx]) continue;

		back = false;
		break;
	}
	if (back) {
		if(!b) _r.d = (_r.d + 2) % 4;
		_r.x += dx[_r.d];
		_r.y += dy[_r.d];
		go(_r, true);
	}
	else {
		_r.d = nd;
		_r.x = nx;
		_r.y = ny;
		go(_r, false);
	}
	
	return;
}

int main() {
	cin >> n >> m;
	// input 북, 동, 남, 서
	// convert 북, 서, 남, 동
	robot r;
	cin >> r.x >> r.y >> r.d;
	if (r.d % 2 != 0) r.d = (r.d + 2) % 4;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> a[y][x];
		}
	}

	go(r,false);
	cout << cnt << '\n';
	return 0;
}