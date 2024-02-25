// 백준 11725번 트리의 부모 찾기

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> node[100001];
int n, parent[100001];

int main()
{
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int s = 0, e = 0;
		cin >> s >> e;
		node[s].push_back(e);
		node[e].push_back(s);
	}

	queue<int> q;
	q.push(1);
	parent[1] = 100001;

	while (q.size())
	{
		int cur = q.front(); q.pop();
		for (int i = 0; i < node[cur].size(); i++)
		{
			if (parent[node[cur][i]])
				continue;

			parent[node[cur][i]] = cur;
			q.push(node[cur][i]);
		}
	}

	for (int i = 2; i <= n; i++)
	{
		cout << parent[i] << '\n';
	}

	return 0;
}