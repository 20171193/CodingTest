// 백준 8979번 올림픽

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<vector<int>> vec;

bool cmp(vector<int> a, vector<int> b)
{
	for (int i = 1; i < 4; i++)
	{
		if (a[i] == b[i])
			continue;
		return a[i] > b[i];
	}
	return a[0] > b[0];
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		vector<int> temp(4);
		for (int j = 0; j < 4; j++)
		{
			cin >> temp[j];
		}
		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end(), cmp);

	int rank = 1, count = 0;
	if (vec[0][0] != k)
	{
		for (int i = 1; i < vec.size(); i++)
		{
			bool isSame = true;
			for (int j = 1; j < 4; j++)
			{
				if (vec[i][j] != vec[i - 1][j])
				{
					isSame = false;
					break;
				}
			}

			if (isSame)
			{
				count++;
			}
			else if (count)
			{
				rank += count + 1;
				count = 0;
			}
			else rank++;


			if (vec[i][0] == k) break;
		}
	}
	cout << rank << '\n';

	return 0;
}
