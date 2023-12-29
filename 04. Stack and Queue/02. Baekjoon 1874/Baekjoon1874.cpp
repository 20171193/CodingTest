// ���� 1874�� ���� ����

// 1~n ���� ���ÿ� �־��ٰ� �̾� �þ���� �ϳ��� ������ ���� �� ����.
// ���ÿ� push�ϴ� ������ �ݵ�� ���������� ��Ŵ.
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
		st.push(i); // ���ÿ� push
		answer += '+';

		if (index < n && st.size())
		{
			while (a[index] == st.top())
			{
				// �������� ������ �ش��ϴ� ���� ������ �ֻ����� �ִٸ� pop
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

