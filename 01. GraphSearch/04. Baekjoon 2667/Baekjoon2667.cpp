// 백준 2667번 단지번호붙이기

// 정사각형 모양의 지도가 있음
// 1은 집이 있는 곳, 0은 집이 없는곳, 단지를 나누어 번호를 붙이려함.
// 대각선상의 집은 연결된 것이 아님.
// 단지수를 출력, 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력.

// 입력
// 지도의 크기 N(5<=N<=25)
// 지도 (0 or 1)

// 출력
// 총 단지수
// 단지내 집의 수를 오름차순으로 정렬하여 하나씩 출력

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int N, count_house, map[26][26];
bool visited[26][26] = { false, };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0, 1, 0, -1 };

vector<int> complex;

void BFS()
{
	queue<pair<int, int>> neighbor;

	// 탐색을 시작할 집을 찾는다.
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1		  // 해당 노드가 집이고
				&& visited[i][j] == false) // 방문하지 않았을 경우
			{
				neighbor.push(make_pair(i, j));	// 큐에 push 후 탐색 실시

				while (!neighbor.empty())
				{
					// 큐의 front 값 복사 후 제거
					pair<int, int> frontQ = neighbor.front();

					neighbor.pop();

					if (visited[frontQ.first][frontQ.second] == false)	// 방문하지 않은 경우
					{
						visited[frontQ.first][frontQ.second] = true;	// 방문체크

						count_house++;	// 단지에 집 추가

						for (int d = 0; d < 4; d++)		// 네개 방향 체크 (상하좌우)
						{
							pair<int, int> target = make_pair(frontQ.first + dx[d], frontQ.second + dy[d]);

							if (0 <= target.first && target.first < N				// 맵 범위 내 존재하고
								&& 0 <= target.second && target.second < N
								&& map[target.first][target.second] == 1			// 집이며
								&& visited[target.first][target.second] == false)	// 방문하지 않았을 경우
							{
								neighbor.push(target);	// 큐에 push
							}
						}
					}
				}
				// 탐색이 종료 된 경우
				complex.push_back(count_house);	// 단지 추가
				count_house = 0;				// 단지 내 집 수 초기화
			}
		}
	}
}

int main()
{
	cin >> N;
	// 맵 정보 저장
	for (int i = 0; i < N; i++)
	{
		string temp = "";
		cin >> temp;
		for (int j = 0; j < temp.length(); j++)
		{
			map[i][j] = temp[j] - '0';
		}
	}

	BFS();

	cout << complex.size() << endl;

	sort(complex.begin(), complex.end());

	for (auto iter = complex.begin();
		iter != complex.end();
		++iter)
	{
		cout << *iter << endl;
	}

	return 0;
}