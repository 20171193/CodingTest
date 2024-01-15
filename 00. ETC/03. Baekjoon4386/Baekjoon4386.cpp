// ���� 4386�� ���ڸ� �����

// n���� ������ �̾� ���ڸ��� �ϳ� ����.
// ��� ������ ��/���������� �̾��� �־�� ��.
// ���� �մ� ����� �� �� ������ �Ÿ�

// 1. ���� ����� ������ ����
// 2. ����Ǿ��ִ� ��� �� ���� ���� ���� ����� ��带 ã�� ����

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int n, visited[101];
float cost;
pair<float, float> a[101];
vector<int> vec;

// �� �������� �Ÿ� ����
float ReturnDistance(pair<float, float> n1, pair<float, float> n2)
{
	return sqrt(pow(abs(n1.first - n2.first), 2) + pow(abs(n1.second - n2.second), 2));
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string xPos = "", yPos = "";
		cin >> xPos >> yPos;
		a[i].first = stof(xPos);
		a[i].second = stof(yPos);
	}

	while (vec.size() < n)
	{
		float min = 987654321.0f;
		int target = 0;
		if (vec.empty())
		{
			// ����� ���� ���� ���
			// 1�� ���� ���� ����� �� ����
			for (int j = 1; j < n; j++)
			{
				float dist = ReturnDistance(a[0], a[j]);
				// ���� ��
				if (min > dist)
				{
					min = dist;
					target = j;
				}
			}
			vec.push_back(0);
			visited[0] = 1;
		}
		else
		{
			// ����� ���� �ִ� ���
			for (int i = 0; i < vec.size(); i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (visited[j]) continue;
					float dist = ReturnDistance(a[vec[i]], a[j]);
					if (min > dist)
					{
						min = dist;
						target = j;
					}
				}
			}
		}
		vec.push_back(target);
		visited[target] = 1;
		cost += min;
	}

	cout << cost << '\n';

	return 0;
}
