// 백준 1374번 강의실

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, cnt;
vector<pair<int, int>> vec;
priority_queue<int, vector<int>, greater<>> pq;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		vec.push_back({ b,c });
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++)
	{
		if (pq.empty())
			cnt++;
		else if (pq.top() > vec[i].first)
			cnt++;
		else
			pq.pop();

		pq.push(vec[i].second);
	}

	cout << cnt << '\n';
	return 0;
}