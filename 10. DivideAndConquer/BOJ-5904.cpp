// 백준 5904번 Moo 게임

#include <iostream>
using namespace std;

typedef long long ll;

// 수열의 총 길이

// s(0) = 3 = = "moo"									// m은 총 1개
// 														// m의 위치 : 0

														// int curPos = s(0)length() = 3
// s(1) = 10 = k+3 + s(k-1)*2 = s(0) + "mooo" + s(0)	// m은 총 3개
//														// 1번째 m의 위치 : curPos
//														// 2번째 m의 위치 : curPos + s(0).length()
// 														// 3번째 m의 위치 : s(0).length()*2 + k+3
//														// curPos += s(1).length()

// 점화식
// s(n).length = s(n-1).length * 2 + n - 1 + 3
//   m의 위치 = 1. s(n)이 시작되는 곳의 좌표
//            = 2. 좌표 + s(n)
//			  = 3. 좌표 + s(n) + n+3	 

ll n;
int ret = -1;
//   pos : s(count)를 작성할 위치
// count : s(count)
//   len : 현재 수열의 길이 

void back(int k, ll len, ll num)
{
	// 0번째 수열의 경우
	if (k == 0)
	{
		if (num == 1)
			ret = 1;
		else
			ret = 0;
		return;
	}

	//    l  r
	// moomooomoo
	ll midLeft = (len - (k + 3)) / 2 + 1;
	ll midRight = midLeft + k + 2;

	// 중간 지점에 위치
	if ((num >= midLeft && num <= midRight))
	{
		if (num == midLeft)
			ret = 1;
		else
			ret = 0;
		return;
	}
	else if (num < midLeft)	// 첫번째 지점에 위치
	{
		back(k - 1, (len - (k + 3)) / 2, num);
	}
	else // 세번째 지점에 위치
	{
		back(k - 1, (len - (k + 3)) / 2, num - midRight);
	}
}


void go(int k, ll len)
{
	if (len > n)
	{
		// k-- : 뒤로 돌아가며 n의 좌표 탐색
		back(k, len, n);
		return;
	}

	// 현재 수열의 길이가 n보다 커질때까지 수열을 계속 늘려줌
	k++;
	go(k, k + 3 + (len * 2));
}

int main()
{
	cin >> n;
	go(0, 3);
	ret == 1 ? cout << "m" : cout << "o";
	cout << '\n';
	return 0;
}