//// 백준 14503번 로봇 청소기
//
//// 1. 현재 칸 청소
//// 2. 주변 모든 칸이 청소된경우
////   1. 한 칸 후진
////   2. 후진이 불가능하면 종료
//// 3. 청소되지 않은 빈 칸이 있는 경우
////   1. 반시계 방향으로 회전
////   2. 앞 방향이 청소되지 않은 빈 칸일 경우 전진
////   3. 1번으로 돌아감
////
//
//
//// 생각할 점
//// - bfs 탐색
//// - 반시계 방향으로 회전
//// - 맵의 끝 부분은 모두 벽이지만, 로봇의 시작점은 항상 빈 공간
////   - 즉, 맨 끝에 로봇이 위치하면 해당 공간은 빈 공간.
//
//// 1. 현재 칸 청소
//// 2. 전방에 청소되지 않은 칸이 나올때까지 반시계 회전
////	1. 청소되지 않은 칸이 없을 경우 방향을 원상복구 한 뒤 후진
////  2. 후진이 불가능하면 종료
////  3. 가능하다면 1로 돌아감.
//// 3. 청소되지 않은 칸이 있을 경우 전진 후 1로 돌아감.
//
//#include <iostream>
//#include <queue>
//using namespace std;
//
//int n, m,x,y, d, a[51][51], visited[51][51];
//// 북, 서, 남, 동
//int dx[4] = {0,-1,0,1};
//int dy[4] = {1,0,-1,0};
//
//void go()
//{
//	visited[y][x] = 1;
//
//	int i = 0, nx = 0, ny = 0; 
//	for (i; i < 4; i++)
//	{
//		nx = x + dx[(d+1+i)%4];
//		ny = y + dy[(d+1+i)%4];
//		if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
//		if (visited[ny][nx]) continue;
//		if (a[ny][nx]) continue;
//		
//		break;
//	}
//
//	if (i == 4)	//go back 
//	{
//		// 방향은 그대로
//		nx = x + dx[(d + 2) % 4];
//		ny = y + dy[(d + 2) % 4];
//		if (nx < 0 || nx >= m || ny < 0 || ny >= n) 
//			return;
//		if (a[ny][nx]) 
//			return;
//	}
//	else
//	{
//		// 청소하지 않은 곳으로 방향 전환
//		d = (d + 1 +i) % 4;
//	}
//	x = nx;
//	y = ny;
//	go();
//}
//
//int main()
//{
//	cin >> n >> m;
//	cin >> x >> y >> d;
//	d = d % 2 == 0 ? d : (d + 2) % 4;	// 문제의 방향과 설정한 방향 매칭
//	
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cin >> a[i][j];
//		}
//	}
//	
//	go();
//
//	int cnt = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cnt += visited[i][j];
//		}
//	}
//	cout << cnt << '\n';
//
//	return 0;
//}
