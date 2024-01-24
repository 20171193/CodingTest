// 백준 9663 N-Queen

// 재귀, 백트래킹
// 각 열마다 퀸을 놓으며 올바른 위치인지 체크
// 모든 열에 퀸이 놓인경우 == n개의 퀸이 놓여진 경우 카운팅

#include <iostream>
using namespace std;

int n, ret, arr[16];

bool checkPos(int x)
{
	for (int i = 0; i < x; i++)
	{
		// 배치한 퀸의 이전 열에 다른 퀸이 존재하는지 확인

		// ex)
		// i = 0, arr[i] = 1
		// x = 1, arr[x] = 1 
		// 0열 1행에 퀸이 존재하는데 1열 1행에 퀸을 배치한 경우 false

		// ex)
		// arr[x] - arr[i] = 2    ==>    행에서의 차이 (width)
		//			 x - i = 2    ==>    열에서의 차이 (height)
		//      width = height    ==>    대각선 상에 존재
		// 가로 길이와 세로 길이가 같은 경우 = 대각선에 존재 false
		if (arr[i] == arr[x] || abs(arr[x] - arr[i]) == x - i) return false;
	}
	return true;
}

void go(int x)
{
	if (x == n)
	{
		ret++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		// x열의 i행 퀸 할당
		arr[x] = i;
		// 다른 퀸을 공격할 수 없다면 해당 위치에 배치 완료
		// 다음 퀸 탐색
		if (checkPos(x)) go(x + 1);
	}
}

int main()
{
	cin >> n;
	go(0);
	cout << ret << '\n';
	return 0;
}
