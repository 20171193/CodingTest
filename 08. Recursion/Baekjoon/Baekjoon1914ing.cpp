// 백준 1914번 하노이 탑

// 시간초과

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

long long k;
int n;
stack<int> st[3];
vector<pair<int, int>> answer;
void go(int _n, int start, int end)
{
	int middle = 3 - (start + end);
	if (_n == 1)
	{
		k++;
		st[end].push(st[start].top());
		st[start].pop();
		if (n > 20) return;
		answer.push_back({ start + 1, end + 1 });
		return;
	}

	go(_n - 1, start, middle);
	go(1, start, end);
	go(_n - 1, middle, end);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = n; i >= 1; i--)
	{
		st[0].push(i);
	}
	go(n, 0, 2);

	cout << k << '\n';
	if (n > 20) return 0;
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i].first << ' ' << answer[i].second << '\n';
	}

	return 0;
}