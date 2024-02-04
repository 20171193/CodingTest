// ���� 11501�� �ֽ�

// �ֽ� �ϳ� ���
// �ֽ� �ȱ�
// �ƹ��͵� ���ϱ�

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;

int t, n;

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		ll ret = 0;
		vector<int> price;
		priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> mxPq;
		queue<int> own;
		for (int i = 0; i < n; i++)
		{
			int temp = 0;
			cin >> temp;
			price.push_back(temp);
			mxPq.push({ temp, i });
		}

		for (int i = 0; i < n; i++)
		{
			own.push(price[i]);
			while (mxPq.top().second < i) mxPq.pop();
			if (mxPq.top().second == i)
			{
				int mxPrice = mxPq.top().first; mxPq.pop();
				while (own.size())
				{
					ret += mxPrice - own.front();
					own.pop();
				}
			}
		}

		cout << ret << '\n';
	}
	return 0;
}