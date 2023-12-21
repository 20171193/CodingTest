// 백준 17822번 원판 돌리기

// 반지름이 i -> i번째 원판
// 각각 m개의 정수가 적혀있고, i번째 원판의 j번째 수의 위치는 (i,j)
//
// 1. (i,1) 은/는 (i,2), (i,m)과 인접
// 2. (i,m) 은/는 (i,m-1), (i,1)과 인접
// 3. (i,j) 은/는 (i,j-1), (i,j+1)과 인접 (2<=j<=m-1)
// 4. (1,j) 은/는 (2,j)와 인접
// 5. (n,j) 은/는 (n-1,j)와 인접
// 6. (i,j) 은/는 (i-1,j), (i+1,j)와 인접 (2<=i<=n-1)
//
// 1.번호가 x의 배수인 원판을 d방향으로 k칸 회전시킴.
//  d:0 = 시계
//  d:1 = 반시계
// 2.원판에 수가 남아 있으면, 인접하면서 수가 같은 것을 모두 찾음.
//  1.수가 있는 경우 인접하며 같은 수를 모두 지운다.
//  2.없는 경우 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수에서 1을 빼고, 작은 수에 1을 더함.
// 3.T번 회전시킨 후 원판에 적힌 수의 합을 구해보자.
// 


// 1. 원판의 회전 (시계, 반시계)
// 2. 인접한 수 찾기
//  1. 같은 수가 있다면 모두 지우기 (dfs)
//  2. 없다면 평균을 구하고 각각 평균보다 큰 수는 1빼고, 작은 수는 1 더하기.
//
// - 2차원 배열로 맵처럼 저장.
//

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int n, m, t, _x, _d, _k, a[51][102], d[51];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void go(int c, int r, bool fnd, float sum)
{
	if (r >= m)
	{
		if (!fnd)
		{
			sum /= m;
			for (int i = 0; i < m; i++)
			{
				if (sum == a[c][i]) continue;
				else if (sum > a[c][i])
				{
					a[c][i] += 1;
					a[c][i + m - 1] += 1;
				}
				else
				{
					a[c][i] -= 1;
					a[c][i + m - 1] -= 1;
				}
				a[c][i] = a[c][i] > sum ? a[c][i] - 1 : a[c][i] + 1;
			}
		}
		return;
	}

	int num = a[c][r + d[c]];
	if (!fnd)
	{
		sum += num;
	}

	for (int i = 0; i < 4; i++)
	{
		if (num == a[c + dy[i]][r + d[c] + dx[i]]) {
			fnd = true;
			a[c][r + d[c]] = 0;
			a[c][r + d[c] + m - 1] = 0;

			a[c + dy[i]][r + d[c] + dx[i]] = 0;
			a[c + dy[i]][r + d[c] + dx[i] + m - 1] = 0;
		}
	}
	go(c, r + 1, fnd, sum);
}

int main()
{
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
		copy(a[i], a[i] + m, a[i] + m);
	}

	while (t--)
	{
		// x의 배수인 원판을 d의 방향으로(시계,반시계) k 만큼 회전
		cin >> _x >> _d >> _k;

		// 회전
		for (int i = _x; i <= n; i *= 2)
		{
			if (_d == 0)
				d[i - 1] += 1 * _k;
			else
				d[i - 1] -= 1 * _k;

			d[i - 1] = d[i - 1] < 0 ? m - 1 - (abs(d[i - 1]) % m) : d[i - 1] % m;
		}

		// 탐색
		for (int i = _x; i <= n; i *= 2)
		{
			go(i - 1, 0, false, 0);
		}
	}

	int sum = 0;
	// 합 구하기
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			sum += a[i][j];
		}
	}

	cout << sum << '\n';

	return 0;
}