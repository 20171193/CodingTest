// ���� 4779�� ĭ��� ����

// 1. -�� 3^n��
// 2. 3��� �� ��� ���ڿ��� �������� ����.
// 3. ��� ���� ���̰� 1�϶����� �ݺ�

// ������ ������ **�ݺ�**
// 3^n���� 1�� �ɶ����� **�ݺ�** - ���� ����(Divide And Conquer)

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <memory.h>
using namespace std;

vector<string> answer;

void DivideAndConquer(int startPos, int n, bool isSpace, string& str)
{
	if (n < 1)
	{
		return;
	}

	if (isSpace)
	{
		for (int i = startPos; i < startPos + n; i++)
		{
			str[i] = ' ';
		}
	}

	DivideAndConquer(startPos, n / 3, false, str);
	DivideAndConquer(startPos + n / 3, n / 3, true, str);
	DivideAndConquer(startPos + n / 3 * 2, n / 3, false, str);
}

int main()
{
	int n = -1;
	while (1)
	{
		if ((cin >> n).eof()) break;
		string temp = "";
		temp.resize(pow(3, n));
		memset(&temp[0], '-', pow(3, n));
		DivideAndConquer(0, pow(3, n), false, temp);
		answer.push_back(temp);
	}

	for (string s : answer)
	{
		cout << s << '\n';
	}

	return 0;
}
