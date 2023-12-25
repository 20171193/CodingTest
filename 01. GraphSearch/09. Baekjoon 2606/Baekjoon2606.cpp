//백준 2606 virus

//네트워크상 연결되어 있는 컴퓨터 끼리 바이러스에 걸린다
//컴퓨터 수, 네트워크 상에서 연결되어 있는 정보

//! 노드 - 인접 노드 정보

//해당 컴퓨터를 통해 바이러스가 걸리게 되는 컴퓨터의 수 출력

//입력
//첫째 줄 : 컴퓨터의 수 <= 100
//둘째 줄 : 연결되어 있는 컴퓨터 쌍의 수
//이어서 : 한 쌍씩 연결된 번호 쌍

//출력
//1번을 기준으로 바이러스에 걸리게 되는 컴퓨터의 수

//BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int node[101];
vector<int> edge[101];
bool visited[101] = { 0, };

void BFS(int start)
{
	queue<int> neighbor;

	neighbor.push(start);

	int count_virus = 0;

	while (!neighbor.empty())
	{
		int temp = neighbor.front();

		visited[temp] = true;

		neighbor.pop();


		for (auto iter = edge[temp].begin();
			iter != edge[temp].end();
			++iter)
		{
			if (visited[*iter] != true)
			{
				neighbor.push(*iter);
			}
		}
	}

	for (int i = 0; i < sizeof(visited) / sizeof(bool); i++)
	{
		if (visited[i] == true && i != 1)
		{
			count_virus++;
		}
	}

	cout << count_virus << endl;
}

int main()
{
	int num_node, num_edge = 0;

	cin >> num_node;
	cin >> num_edge;

	for (int i = 0; i < num_edge; i++)
	{
		int a, b = 0;

		cin >> a >> b;

		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	BFS(1);

	return 0;
}
