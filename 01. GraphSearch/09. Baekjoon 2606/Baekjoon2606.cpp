//���� 2606 virus

//��Ʈ��ũ�� ����Ǿ� �ִ� ��ǻ�� ���� ���̷����� �ɸ���
//��ǻ�� ��, ��Ʈ��ũ �󿡼� ����Ǿ� �ִ� ����

//! ��� - ���� ��� ����

//�ش� ��ǻ�͸� ���� ���̷����� �ɸ��� �Ǵ� ��ǻ���� �� ���

//�Է�
//ù° �� : ��ǻ���� �� <= 100
//��° �� : ����Ǿ� �ִ� ��ǻ�� ���� ��
//�̾ : �� �־� ����� ��ȣ ��

//���
//1���� �������� ���̷����� �ɸ��� �Ǵ� ��ǻ���� ��

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
