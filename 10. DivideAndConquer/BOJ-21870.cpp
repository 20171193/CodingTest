// ���� 21870�� ��ö�̰� ����� GCD

// GCD = �ִ� �����
// ��Ŭ���� ȣ���� (�ִ� ����� ���� �˰���)
// A, B �� ū ���� ���� ���� �������� �� ������ �������� �ʴ´ٸ�
// �� �������� ���� ���� ��� ������ ������ �������ٸ� �� ���� �ִ� ������� ��.

// 1. �Ź���ȣ�� ��Ÿ���� ���� �迭 S
// 2. ���Ҹ� ���ʺ��� S.length/2 ���� �����ϰų�, �����ʺ��� S.length/2 ���� ����.
//		���� S�� ���Ұ� �� �Ѱ���� �� ���Ҹ� ����
// 3. ������ ���ҵ��� GCD�� ����.
// 4. �������� ���� ������ �迭 S�� �ٽ� 2������ �ݺ�.
// 5. 3������ ���� GCD�� ���� �ִ����� ���� ����.

#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

int n, ret;
vector<int> v;
deque<int> dq;

int GCD(int x, int y)
{
	if (y == 0)
		return x;
	else
		return GCD(y, x % y);
}
int GCDArray(vector<int> vec, int start, int count)
{
	if (count == 1)
		return vec[start];
	else if (count == 2)
		return GCD(vec[start], vec[start + 1]);
	else
		return GCD(vec[start], GCDArray(vec, start + 1, count - 1));
}
int GetGCD(int baseNum)
{
	if (dq.size() == 1)
	{
		int retNum = dq.back(); dq.pop_back();
		return retNum;
	}

	vector<int> temp;
	if (dq.front() < baseNum)
	{
		while (dq.size() && dq.front() <= baseNum)
		{
			temp.push_back(dq.front()); dq.pop_front();
		}
	}
	else
	{
		while (dq.size() && dq.back() >= baseNum)
		{
			temp.push_back(dq.back()); dq.pop_back();
		}
	}

	return GCDArray(temp, 0, temp.size());
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	for (int i : v) dq.push_back(i);

	while (dq.size())
	{
		ret += GetGCD(dq.size() / 2);
	}
	cout << ret << '\n';
	return 0;
}