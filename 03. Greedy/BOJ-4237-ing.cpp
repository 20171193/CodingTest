// 백준 4237 비 단조성
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t, n, a[30001];
vector<int> answer;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int prev = a[0], cnt = 1, ret = 0;

		for (int i = 1; i < n; i++)
		{
			if (cnt % 2 && prev > a[i])
				cnt++;
			else if (!(cnt % 2) && prev < a[i])
				cnt++;
			else
			{
				ret = max(cnt, ret);
				cnt = 1;
			}

			prev = a[i];
		}

		ret = max(cnt, ret);
		answer.push_back(ret);
	}

	for (int i : answer)
		cout << i << '\n';

	return 0;
}