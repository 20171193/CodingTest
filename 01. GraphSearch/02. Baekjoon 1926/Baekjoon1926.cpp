//// 백준 1926번 그림
//
//// 그림의 개수와 넓이가 가장 넓은 것의 넓이를 출력
//
//// - bfs
//// - 영역의 개수, 영역의 크기
//
//#include <iostream>
//#include <queue>
//#include <math.h>
//using namespace std;
//
//int n, m, cnt, mw, a[501][501], visited[501][501];
//int dx[4] = { 1, 0, -1, 0 };
//int dy[4] = { 0, 1, 0, -1 };
//
//void bfs()
//{
//	for (int y = 0; y < n; y++)
//	{
//		for (int x = 0; x < m; x++)
//		{
//			if (visited[y][x]) continue;
//			if (!a[y][x]) continue;
//
//			int tc = 1;
//			cnt++;
//			queue<pair<int,int>> q;
//			q.push({ y,x });
//			visited[y][x] = 1;
//			while (q.size())
//			{
//				pair<int, int> temp = q.front();
//				q.pop();
//				for (int i = 0; i < 4; i++)
//				{
//					int nx = temp.second + dx[i];
//					int ny = temp.first + dy[i];
//					
//					if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
//					if (visited[ny][nx]) continue;
//					if (!a[ny][nx]) continue;
//
//					tc++;
//					visited[ny][nx] = 1;
//					q.push({ ny,nx });
//				}
//			}
//			mw = max(tc, mw);
//		}
//	}
//	return;
//}
//
//int main()
//{
//	cin >> n >> m;
//	for (int y = 0; y < n; y++)
//	{
//		for (int x = 0; x < m; x++) 
//		{
//			cin >> a[y][x];
//		}
//	}
//
//	bfs();
//	cout << cnt << '\n';
//	cout << mw << '\n';
//
//	return 0;
//}