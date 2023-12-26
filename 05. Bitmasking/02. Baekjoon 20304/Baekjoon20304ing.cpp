// 백준 20304번 비밀번호 제작

// - 안전거리 : 두 비밀번호의 서로 다른 자리의 개수
// - ex) 3(0011), 8(1000) -> 3
// - 안전도 : 안전거리의 최솟값
// - 안전도가 가장 높게끔 바꾸려함.  

// 3(0011), 8(1000), 4(0100), 7(0111)
// xor 연산
// 같으면 false, 다르면 true

#include <iostream>
#include <map>
using namespace std;

int n, m, mx, a[100001];
map<int, int> _m;

// 1 0001
// 2 0010
// 3 0011
// 4 0100
// 5 0101
// 6 0110
// 7 0111
// 8 1000

// 

/// <summary>
/// 비트마스킹
/// </summary>
int SafeDistance(int n1, int n2)
{
	int ret = 0;

	// xor연산
	// 같다면 false, 다르면 true
	int result = n1 ^ n2;
	if (result & (1 << 0)) ret++;
	for (int i = 1; i <= result; i *= 2)
	{
		if (result & i) ret++;
	}

	return ret;
}



int main()
{
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
		_m.insert({ a[i], 1 });	// 이미 사용된 비밀번호의 중복을 피함.
	}


	for (int i = 0; i <= n; i++)
	{
		if (_m.find(i) != _m.end()) continue;
		int mn = 987654321;
		for (int j = 0; j < m; j++)
		{
			// 안전도 
			//  : 새로 시도한 비밀번호 i와 이미 시도한 비밀번호 a[j~m]간의 안전거리 중 작은값
			mn = min(SafeDistance(a[j], i), mn);
		}
		// 안전도 중 최댓값
		mx = max(mn, mx);
	}

	cout << mx << '\n';

	return 0;
}