// ���� 11286�� ���� ��

// �迭�� ���� x(x �� 0)�� �ִ´�.
// �迭���� ������ ���� ���� ���� ����ϰ�, �� ���� �迭���� �����Ѵ�.
// ������ ���� ���� ���� �������� ����, ���� ���� ���� ����ϰ�, �� ���� �迭���� �����Ѵ�.

#include <iostream>
#include <queue>
#include <math.h>
#include <vector>
using namespace std;

struct compare
{
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))	// ������ ���� ���
			return a > b;
		else
			return abs(a) > abs(b);
	}
};

priority_queue<int, vector<int>, compare> pq;
vector<int> answer;
int n;

// 0�Է� - ������ ���� ���� �� ���, �迭���� ����
// 0<�Է� - �迭�� �߰�

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		if (temp == 0)
		{
			if (pq.size())
			{
				answer.push_back(pq.top()); pq.pop();
			}
			else
			{
				answer.push_back(0);
			}
		}
		else
		{
			pq.push(temp);
		}
	}

	for (int i : answer)
	{
		cout << i << '\n';
	}

	return 0;
}