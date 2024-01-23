// 백준 1652번 누울 자리를 찾아라

#include <iostream>
#include <string>
using namespace std;

string temp;
int n, horizon, vertical, arr[101][101];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		for (int j = 0; j < n; j++)
		{
			if (temp[j] == '.') arr[i][j] = 1;
			else arr[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
		{

			if (arr[i][j]) count++;
			else
			{
				if (count >= 2) horizon++;
				count = 0;
			}
		}
		if (count >= 2) horizon++;
	}

	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
		{

			if (arr[j][i]) count++;
			else
			{
				if (count >= 2) vertical++;
				count = 0;
			}
		}
		if (count >= 2) vertical++;
	}

	cout << horizon << ' ' << vertical << '\n';

	return 0;
}
