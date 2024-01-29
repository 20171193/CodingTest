// 백준 21870번 시철이가 사랑한 GCD

// GCD = 최대 공약수
// 유클리드 호제법 (최대 공약수 도출 알고리즘)
// A, B 중 큰 수를 작은 수로 나누었을 때 나누어 떨어지지 않는다면
// 그 나머지로 작은 수와 계속 나누어 나누어 떨어진다면 그 수가 최대 공약수가 됨.

// 1. 매물번호를 나타내는 정수 배열 S
// 2. 원소를 왼쪽부터 S.length/2 개를 선택하거나, 오른쪽부터 S.length/2 개를 선택.
//		만일 S의 원소가 단 한개라면 그 원소를 선택
// 3. 선택한 원소들의 GCD를 구함.
// 4. 선택하지 않은 원소의 배열 S를 다시 2번부터 반복.
// 5. 3번에서 구한 GCD의 합의 최댓값으로 정답 도출.

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