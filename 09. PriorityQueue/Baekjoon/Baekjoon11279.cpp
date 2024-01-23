// 백준 11279번 최대 힙
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, less<>> pq;
int n;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	while (n--)
	{
		int temp = 0;
		cin >> temp;
		if (temp == 0)
		{
			if (pq.size())
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else
		{
			pq.push(temp);
		}
	}
	return 0;
}