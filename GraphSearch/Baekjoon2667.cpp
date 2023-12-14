// ���� 2667�� ������ȣ���̱�

// ���簢�� ����� ������ ����
// 1�� ���� �ִ� ��, 0�� ���� ���°�, ������ ������ ��ȣ�� ���̷���.
// �밢������ ���� ����� ���� �ƴ�.
// �������� ���, ������ ���ϴ� ���� ���� ������������ �����Ͽ� ���.

// �Է�
// ������ ũ�� N(5<=N<=25)
// ���� (0 or 1)

// ���
// �� ������
// ������ ���� ���� ������������ �����Ͽ� �ϳ��� ���

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

	// Ž���� ������ ���� ã�´�.
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1		  // �ش� ��尡 ���̰�
				&& visited[i][j] == false) // �湮���� �ʾ��� ���
			{
				neighbor.push(make_pair(i, j));	// ť�� push �� Ž�� �ǽ�

				while (!neighbor.empty())
				{
					// ť�� front �� ���� �� ����
					pair<int, int> frontQ = neighbor.front();

					neighbor.pop();

					if (visited[frontQ.first][frontQ.second] == false)	// �湮���� ���� ���
					{
						visited[frontQ.first][frontQ.second] = true;	// �湮üũ

						count_house++;	// ������ �� �߰�

						for (int d = 0; d < 4; d++)		// �װ� ���� üũ (�����¿�)
						{
							pair<int, int> target = make_pair(frontQ.first + dx[d], frontQ.second + dy[d]);

							if (0 <= target.first && target.first < N				// �� ���� �� �����ϰ�
								&& 0 <= target.second && target.second < N
								&& map[target.first][target.second] == 1			// ���̸�
								&& visited[target.first][target.second] == false)	// �湮���� �ʾ��� ���
							{
								neighbor.push(target);	// ť�� push
							}
						}
					}
				}
				// Ž���� ���� �� ���
				complex.push_back(count_house);	// ���� �߰�
				count_house = 0;				// ���� �� �� �� �ʱ�ȭ
			}
		}
	}
}

int main()
{
	cin >> N;
	// �� ���� ����
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