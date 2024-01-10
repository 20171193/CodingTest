// 백준 15650번 N과 M (2)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> vec;
int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		vec.push_back(i);
	}

	vector<int> temp;
	for (int i = 0; i < n; i++)
	{
		if (i < m) temp.push_back(0);
		else temp.push_back(1);
	}

	do {
		for (int i = 0; i < temp.size(); i++)
		{
			if (!temp[i]) cout << vec[i] << ' ';
		}
		cout << '\n';
	} while (next_permutation(temp.begin(), temp.end()));

	return 0;
}