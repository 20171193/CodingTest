// 백준 9205번 맥주 마시면서 걸어가기

// - 맥주 한 박스 : 20개
// - 50미터에 한 병씩 (적어도 49미터에는 한 병을 마셔야함.)
// - 편의점에서 빈 병을 버리고 맥주 구매가능.

// bfs

#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <math.h>
using namespace std;

int t, n, cur;
bool visited[101];
vector<pair<int, int>> a;

bool canGo(int n) {
	int nx = a[n].second;
	int ny = a[n].first;
	if (abs(ny - a[cur].first) + abs(nx - a[cur].second) <= 1000) return true;
	else return false;
}

bool bfs() {
	memset(visited, false, sizeof(visited));
	queue<int> q;
	visited[0] = true;
	q.push(0);	
	while (q.size()) {
		cur = q.front(); q.pop();

		for (int i = 1; i < n + 2; i++) {
			if (visited[i]) continue;
			if (!canGo(i)) continue;

			if (i == n + 1) return true;
			visited[i] = true;
			q.push(i);
		}
	}
	return false;
}

int main() {
	cin >> t;
	
	while (t--) {
		// input
		cin >> n;

		// 0 = home
		// n+1 = festival
		for (int i = 0; i < n+2; i++) {
			int x = 0, y = 0;
			cin >> x >> y;
			a.push_back({ y,x });
		}

		if (bfs()) cout << "happy" << '\n';
		else cout << "sad" << '\n';

		a.clear();
	}

	return 0;
}