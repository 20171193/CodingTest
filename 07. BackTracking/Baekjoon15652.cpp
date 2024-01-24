// 백준 15652번 N과 M(4)

#include <iostream>
using namespace std;

int n, m, arr[9];

void go(int num, int c)
{
	if (c == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	//   arr[c] =   i = 1-2-3-4-5
	// arr[c+1] = i+1 = 1-2-3-4-5 
	for (int i = num; i <= n; i++)
	{
		// c는 0부터 카운팅
		arr[c] = i;
		go(i, c + 1);
	}
}

int main()
{
	cin >> n >> m;
	go(1, 0);
	return 0;
}