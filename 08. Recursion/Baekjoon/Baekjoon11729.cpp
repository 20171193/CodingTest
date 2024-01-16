// 백준 11729번 하노이 탑 이동 순서
// 재귀 호출
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> answer;

void go(int c, int from, int by, int to)
{
	if (c > 0)
	{
		go(c - 1, from, to, by);
		answer.push_back({ from, to });
		go(c - 1, by, from, to);
	}
}

int main()
{
	cin >> n;
	go(n, 1, 2, 3);
	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i].first << " " << answer[i].second << '\n';
	}
	return 0;
}