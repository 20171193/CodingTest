// 백준 13975번 파일 합치기 3

// 1,000,000 완탐 x
// 비싼건 나중으로 미루고 합치기

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;
int t, k;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--)
	{
		// 최솟값 우선순위 큐
		priority_queue<ll, vector<ll>, greater<ll>> pq;

		// input
		cin >> k;
		for (int i = 0; i < k; i++)
		{
			ll temp = 0;
			cin >> temp;
			pq.push(temp);
		}
		ll result = 0;
		// solve 
		// k-1번 실행
		for (int i = 0; i < k - 1; i++)
		{
			ll sum = 0;
			sum += pq.top();
			pq.pop();
			sum += pq.top();
			pq.pop();

			pq.push(sum);
			result += sum;
		}

		cout << result << '\n';
	}
	return 0;
}