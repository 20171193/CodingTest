// 백준 1874번 스택 수열

// 1~n 수를 스택에 넣었다가 뽑아 늘어놓아 하나의 수열을 만들 수 있음.
// 스택에 push하는 순서는 반드시 오름차순을 지킴.
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n, a[100001];
string answer = "";
stack<int> st;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int index = 0;
	for (int i = 1; i <= n; i++)
	{
		st.push(i); // 스택에 push
		answer += '+';

		if (index < n && st.size())
		{
			while (a[index] == st.top())
			{
				// 만들어야할 수열에 해당하는 값이 스택의 최상위에 있다면 pop
				st.pop();
				answer += '-';
				index++;

				if (!st.size()) break;
			}
		}
	}
	if (st.size())
		cout << "NO" << '\n';
	else
	{
		for (char c : answer)
		{
			cout << c << '\n';
		}
	}
	return 0;
}

