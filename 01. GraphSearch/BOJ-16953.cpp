// น้มุ 16953น๘ A->B

#include <iostream>
#include <math.h>
#include <iostream>
using namespace std;

typedef long long ll;

const int INF = 987654321;
int a, b, ret = INF;

void go(ll n, int count)
{
	if (n > b)
		return;
	if (n == b)
	{
		ret = min(count, ret);
		return;
	}

	go(n * 2, count + 1);
	go((n * 10) + 1, count + 1);
}

int main()
{
	cin >> a >> b;
	go(a, 1);

	if (ret == INF)
		cout << -1 << '\n';
	else
		cout << ret << '\n';
	return 0;
}