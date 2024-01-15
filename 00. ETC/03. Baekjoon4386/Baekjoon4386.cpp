// 백준 4386번 별자리 만들기

// n개의 별들을 이어 별자리를 하나 만듦.
// 모든 별들은 직/간접적으로 이어져 있어야 함.
// 선을 잇는 비용은 두 별 사이의 거리

// 1. 제일 가까운 노드부터 연결
// 2. 연결되어있는 노드 중 남은 노드와 가장 가까운 노드를 찾아 연결

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

// 두 점사이의 거리 리턴
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
			// 연결된 별이 없는 경우
			// 1번 별과 가장 가까운 별 연결
			for (int j = 1; j < n; j++)
			{
				float dist = ReturnDistance(a[0], a[j]);
				// 연결 별
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
			// 연결된 별이 있는 경우
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
