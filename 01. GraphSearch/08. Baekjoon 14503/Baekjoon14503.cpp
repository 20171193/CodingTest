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

// 1. ���� ĭ û��
// 2. ���濡 û�ҵ��� ���� ĭ�� ���ö����� �ݽð� ȸ��
//	1. û�ҵ��� ���� ĭ�� ���� ��� ������ ���󺹱� �� �� ����
//  2. ������ �Ұ����ϸ� ����
//  3. �����ϴٸ� 1�� ���ư�.
// 3. û�ҵ��� ���� ĭ�� ���� ��� ���� �� 1�� ���ư�.


#include <iostream>
#include <queue>
using namespace std;

int n, m, rx, ry, rd, a[51][51];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1,0,1,0 };

// 0��, 1��, 2��, 3�� 
// ȸ�� - �ݽð� (-1 + 4)%4

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

			// ���� ���� ��
			// �κ��� ������ ����ߴ��� �湮üũ�� �� �� Ž���� �ǽ��ϱ⶧���� ��������.
			if (nx < 1 || nx >= m - 1 || ny < 1 || ny >= n - 1) continue;
			if (a[ny][nx] > 0) continue;

			q.push({ ny,nx });
			rd = (rd - i + 4) % 4;	// ���� ����
			a[ny][nx] = 2;	// û��
			fnd = true;
			ret++;
			break;
		}

		// ����
		if (!fnd)
		{
			int nx = temp.second - dx[rd];
			int ny = temp.first - dy[rd];

			// �����ϸ� ���� ��� 
			if (nx < 1 || nx >= m - 1 || ny < 1 || ny >= n - 1) return ret;
			if (a[ny][nx] == 1) return ret;
			// û�ҵ��� ���� ������ ���
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