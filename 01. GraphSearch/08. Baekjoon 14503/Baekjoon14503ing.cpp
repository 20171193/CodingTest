//// ���� 14503�� �κ� û�ұ�
//
//// 1. ���� ĭ û��
//// 2. �ֺ� ��� ĭ�� û�ҵȰ��
////   1. �� ĭ ����
////   2. ������ �Ұ����ϸ� ����
//// 3. û�ҵ��� ���� �� ĭ�� �ִ� ���
////   1. �ݽð� �������� ȸ��
////   2. �� ������ û�ҵ��� ���� �� ĭ�� ��� ����
////   3. 1������ ���ư�
////
//
//
//// ������ ��
//// - bfs Ž��
//// - �ݽð� �������� ȸ��
//// - ���� �� �κ��� ��� ��������, �κ��� �������� �׻� �� ����
////   - ��, �� ���� �κ��� ��ġ�ϸ� �ش� ������ �� ����.
//
//// 1. ���� ĭ û��
//// 2. ���濡 û�ҵ��� ���� ĭ�� ���ö����� �ݽð� ȸ��
////	1. û�ҵ��� ���� ĭ�� ���� ��� ������ ���󺹱� �� �� ����
////  2. ������ �Ұ����ϸ� ����
////  3. �����ϴٸ� 1�� ���ư�.
//// 3. û�ҵ��� ���� ĭ�� ���� ��� ���� �� 1�� ���ư�.
//
//#include <iostream>
//#include <queue>
//using namespace std;
//
//int n, m,x,y, d, a[51][51], visited[51][51];
//// ��, ��, ��, ��
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
//		// ������ �״��
//		nx = x + dx[(d + 2) % 4];
//		ny = y + dy[(d + 2) % 4];
//		if (nx < 0 || nx >= m || ny < 0 || ny >= n) 
//			return;
//		if (a[ny][nx]) 
//			return;
//	}
//	else
//	{
//		// û������ ���� ������ ���� ��ȯ
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
//	d = d % 2 == 0 ? d : (d + 2) % 4;	// ������ ����� ������ ���� ��Ī
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