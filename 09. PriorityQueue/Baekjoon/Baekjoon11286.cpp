// 백준 11286번 절댓값 힙

// 배열에 정수 x(x ≠ 0)를 넣는다.
// 배열에서 절댓값이 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다.
// 절댓값이 가장 작은 값이 여러개일 때는, 가장 작은 수를 출력하고, 그 값을 배열에서 제거한다.

#include <iostream>
#include <queue>
#include <math.h>
#include <vector>
using namespace std;

struct compare
{
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))	// 절댓값이 같은 경우
			return a > b;
		else
			return abs(a) > abs(b);
	}
};

priority_queue<int, vector<int>, compare> pq;
vector<int> answer;
int n;

// 0입력 - 절댓값이 가장 작은 값 출력, 배열에서 제거
// 0<입력 - 배열에 추가

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		if (temp == 0)
		{
			if (pq.size())
			{
				answer.push_back(pq.top()); pq.pop();
			}
			else
			{
				answer.push_back(0);
			}
		}
		else
		{
			pq.push(temp);
		}
	}

	for (int i : answer)
	{
		cout << i << '\n';
	}

	return 0;
}