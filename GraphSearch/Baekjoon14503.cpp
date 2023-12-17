// ���� 14503�� �κ� û�ұ�

// 1. ���� ĭ û��
// 2. �ֺ� ��� ĭ�� û�ҵȰ��
//   1. �� ĭ ����
//   2. ������ �Ұ����ϸ� ����
// 3. û�ҵ��� ���� �� ĭ�� �ִ� ���
//   1. �ݽð� �������� ȸ��
//   2. �� ������ û�ҵ��� ���� �� ĭ�� ��� ����
//   3. 1������ ���ư�
//


// ������ ��
// - bfs Ž��
// - �ݽð� �������� ȸ��
// - ���� �� �κ��� ��� ��������, �κ��� �������� �׻� �� ����
//   - ��, �� ���� �κ��� ��ġ�ϸ� �ش� ������ �� ����.

#include <iostream>
#include <queue>
using namespace std;

struct robot {
	int x, y, d;
};

int n, m,cnt, a[51][51], visited[51][51];
// d - ��, ��, ��, �� (������ �ݴ�� ����)
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
	// input ��, ��, ��, ��
	// convert ��, ��, ��, ��
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