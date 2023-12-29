// ���� 2493�� ž
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;
stack<pair<int, int>> st;
vector<int> printVec;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		if (st.empty()) printVec.push_back(0);
		else
		{
			// ���� ������� ž���� ���� ž���� ���ÿ��� pop
			while (!st.empty() && st.top().second < temp)
			{
				st.pop();
			}
			if (st.empty()) printVec.push_back(0);
			else printVec.push_back(st.top().first + 1);
		}
		// �ε����� ���� ����
		st.push({ i,temp });
	}

	for (int i : printVec)
	{
		cout << i << " ";
	}

	return 0;
}
