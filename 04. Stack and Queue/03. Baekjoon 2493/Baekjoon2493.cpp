// 백준 2493번 탑
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
			// 현재 세우려는 탑보다 작은 탑들을 스택에서 pop
			while (!st.empty() && st.top().second < temp)
			{
				st.pop();
			}
			if (st.empty()) printVec.push_back(0);
			else printVec.push_back(st.top().first + 1);
		}
		// 인덱스와 높이 저장
		st.push({ i,temp });
	}

	for (int i : printVec)
	{
		cout << i << " ";
	}

	return 0;
}
