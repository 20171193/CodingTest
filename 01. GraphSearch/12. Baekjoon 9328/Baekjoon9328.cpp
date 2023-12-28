// 백준 9328번 열쇠

// 1층 빌딩에 잠입해 문서를 훔쳐오려함.
// 평면도에는 문서의 위치가 모두 나타나있고
// 빌딩의 문을 열려면 일부 열쇠가 필요함.
// 일부 열쇠는 가지고있고, 일부 열쇠는 빌딩의 바닥에 놓여져 있음.

// . : 빈공간
// * : 벽
// $ : 문서
// 대문자 : 문
// 소문자 : 열쇠
// 대문자 소문자 서로 대칭됨. A의 열쇠는 a

// 훔칠 수 있는 문서의 최대 개수를 출력
// 맵을 다 돌더라도 문서를 최대한으로 훔쳐야함.

// - 문서에서부터 탐색
// - 문서에서 플레이어까지 도달할 수 있는지?
// - 경로상에 문이 있다면, 문에 해당하는 열쇠까지 도달할 수 있는지?
// - 플레이어가 열쇠를 가지고 있는지?

#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

int t, h, w, a[101][101], visited[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

bool ownKey[27];
vector<pair<int, int>> documents;

void bfs()
{
	// 무작정 큐에 push-pop을 실시하며 너비우선탐색을 할 경우
	// 탐색 중 열쇠를 획득했더라도 탐색 중에 이미 지나간 문을 들어갈 수 없음
	// 열쇠를 획득한 경우 visited배열과 queue를 초기화하는 로직이 필요.
	// ex)
	//		1.a열쇠만을 가지고 탐색 -> b열쇠 발견 -> 방문초기화, 처음부터 다시 탐색 
	//		2.a,b열쇠를 가지고 탐색 -> c열쇠 발견 -> 방문초기화, 처음부터 다시 탐색
	//		3.a,b,c열쇠를 가지고 탐색 -> ....
	// 
	//		- 최종적으로 documents위치가 방문된 위치면 카운팅 +
	//		- 결과출력
	// 

	/// <summary>
	/// 맵의 가장자리 중 출발할 수 있는 위치에서 bfs탐색 실시.
	/// 출발할 수 있는 위치는
	/// 1.빈공간 (.)
	/// 2.열쇠 (a-z)
	/// 3.문서 ($)
	/// 4.문 (A-Z) ***현재 가지고있는 열쇠와 대칭되는 문
	/// </summary>
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			bool reset = false;	// 탐색 중 새로운 열쇠를 획득한 경우

			// 첫 시작위치?
			if (i > 0 && i < h - 1)
			{
				if (j > 0 && j < w - 1) continue;	// 맵의 가장자리가 아닐 경우
			}
			if (a[i][j] == '*') continue;	// 시작 위치가 벽일 경우
			if ((a[i][j] >= 'A' && a[i][j] <= 'Z') && !ownKey[a[i][j] - 'A']) continue;	// 시작 위치가 열쇠를 가지지 않은 문 일경우
			if ((a[i][j] >= 'a' && a[i][j] <= 'z') && !ownKey[a[i][j] - 'a']) {	// 시작 위치가 열쇠일 경우 -> 열쇠 획득 -> 탐색이 종료되면 방문초기화, i, j 값 초기화 
				// 반복문을 처음부터 실행하도록함.
				reset = true;
				ownKey[a[i][j] - 'a'] = true;
			}
			visited[i][j] = 1;
			queue<pair<int, int>> q;
			q.push({ i,j });

			while (q.size())
			{
				pair<int, int> temp = q.front();
				q.pop();
				for (int k = 0; k < 4; k++)
				{
					int nx = temp.second + dx[k];
					int ny = temp.first + dy[k];

					if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
					if (visited[ny][nx]) continue;
					if (a[ny][nx] == '*') continue;
					else if ((a[ny][nx] >= 'A' && a[ny][nx] <= 'Z') && !ownKey[a[ny][nx] - 'A']) continue;
					else if ((a[ny][nx] >= 'a' && a[ny][nx] <= 'z') && !ownKey[a[ny][nx] - 'a']) {
						ownKey[a[ny][nx] - 'a'] = true;	// 열쇠 획득
						reset = true;	// 처음부터 탐색 하도록 reset 변수 true로 할당
						memset(visited, false, sizeof(visited));	// 현재 위치에서 재탐색하도록 방문 배열을 먼저 초기화
						while (q.size()) q.pop();	// 큐에 담긴 너비탐색 결과 삭제
					}

					visited[ny][nx] = 1;
					q.push({ ny,nx });
				}
			}
			if (reset)
			{
				i = 0;
				j = -1;
				memset(visited, false, sizeof(visited));
			}
		}
	}
}

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> h >> w;
		for (int i = 0; i < h; i++)
		{
			string temp = "";
			cin >> temp;
			for (int j = 0; j < temp.length(); j++)
			{
				a[i][j] = temp[j];
				if (a[i][j] == '$')
				{
					documents.push_back({ i,j });	// 문서가 존재하는 위치 할당
				}
			}
		}
		string temp = "";
		cin >> temp;
		if (temp[0] != '0')
		{
			for (int i = 0; i < temp.length(); i++)
			{
				ownKey[temp[i] - 'a'] = true;	// 가지고 있는 열쇠 할당
			}
		}
		bfs();

		// 훔친 문서 카운팅 / 출력
		int cnt = 0;
		for (int i = 0; i < documents.size(); i++)
		{
			if (visited[documents[i].first][documents[i].second] == 1) cnt++;
		}
		cout << cnt << '\n';

		memset(a, 0, sizeof(a));
		memset(visited, 0, sizeof(visited));
		memset(ownKey, false, sizeof(ownKey));
		documents.clear();
	}
	return 0;
}

