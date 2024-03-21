// ���� 9009�� �Ǻ���ġ

// n�� ������ ���� ū ��
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
int t, n, mx, dp[151];

int main()
{
	dp[0] = 0;
	dp[1] = 1;

	cin >> t;
	while (t--)
	{
		cin >> n;
		vec.push_back(n);
		mx = max(n, mx);
	}

	int idx = 2;
	// �ִ񰪱��� �Ǻ���ġ ����
	while (dp[idx] < mx)
		dp[idx++] = dp[idx - 2] + dp[idx - 1];

	for (int i = 0; i < vec.size(); i++)
	{
		vector<int> ans;
		int temp = vec[i];
		while (temp > 0)
		{
			int num = 0;
			while (dp[num] < temp) num++;

			if (dp[num] == temp)
			{
				temp -= dp[num];
				ans.push_back(dp[num]);
			}
			else
			{
				temp -= dp[num - 1];
				ans.push_back(dp[num - 1]);
			}
		}
		sort(ans.begin(), ans.end());
		for (int i : ans)
			cout << i << " ";
		cout << '\n';
	}

	return 0;
}