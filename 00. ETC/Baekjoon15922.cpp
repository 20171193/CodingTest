// 백준 15922번 아우으 우아으이야!!

// -10억 ~ 10억

#include <iostream>
using namespace std;

typedef long long ll;

int n;
ll x, y, sum;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	pair<ll, ll> prev = { 0,0 };
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		if ((prev.first == 0 && prev.second == 0))
			sum += abs(y - x);
		else if (prev.second >= y)
			continue;
		else if (prev.second <= x)
			sum += abs(y - x);
		else
			sum += abs(y - prev.second);

		prev = { x,y };
	}

	cout << sum << '\n';

	return 0;
}

