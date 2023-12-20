//// ���� 2583�� ���� ���ϱ�
//
//// - m*n
//// - ��ĥ�� �� �� ���� ����, ���� ũ��
//
//// 1. ��ĥ�ϱ�
//// 2. ��ĥ���� ���� �� Ž�� (ũ�� ī����, ���� �и�)
//
//#include <iostream>
//#include <queue>
//using namespace std;
//
//int m, n, k, a[101][101];
//int dx[4] = { 1, 0, -1, 0 };
//int dy[4] = { 0, -1, 0, 1 };
//
//int bfs(int y, int x) {
//	queue<pair<int, int>> q;
//	a[y][x] = -1;
//	q.push({ y,x });
//
//	int cnt = 1;
//	while (q.size()) {
//		pair<int, int> temp = q.front();
//		q.pop();
//
//		for (int i = 0; i < 4; i++) {
//			int nx = dx[i] + temp.second;
//			int ny = dy[i] + temp.first;
//
//			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
//			if (a[ny][nx] == -1) continue;
//
//			q.push({ ny,nx });
//			a[ny][nx] = -1;
//			cnt++;
//		}
//	}
//	return cnt;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> m >> n >> k;
//
//	// �Է�
//	for (int i = 0; i < k; i++) {
//		int ldx = 0, ldy = 0, rtx = 0, rty = 0;
//		cin >> ldx >> ldy >> rtx >> rty;
//
//		// ��ĥ
//		for (int y = ldy; y < rty; y++) {
//			for (int x = ldx; x < rtx; x++) {
//				a[y][x] = -1;
//			}
//		}
//	}
//		
//	// ������ ���̸� ������������ �����ϱ� ���� �켱���� ť 
//	priority_queue<int, vector<int>, greater<int>> pq;
//
//	// Ž��
//	for (int y = 0; y < m; y++) {
//		for (int x = 0; x < n; x++) {
//			if (a[y][x] == 0) {
//				pq.push(bfs(y,x));
//			}
//		}
//	}
//
//	cout << pq.size() << '\n';
//	while (pq.size()) {
//		cout << pq.top() << " "; pq.pop();
//	}
//
//	return 0;
//}