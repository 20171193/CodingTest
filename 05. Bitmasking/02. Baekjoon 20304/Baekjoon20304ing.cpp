// ���� 20304�� ��й�ȣ ����

// - �����Ÿ� : �� ��й�ȣ�� ���� �ٸ� �ڸ��� ����
// - ex) 3(0011), 8(1000) -> 3
// - ������ : �����Ÿ��� �ּڰ�
// - �������� ���� ���Բ� �ٲٷ���.  

// 3(0011), 8(1000), 4(0100), 7(0111)
// xor ����
// ������ false, �ٸ��� true

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
/// ��Ʈ����ŷ
/// </summary>
int SafeDistance(int n1, int n2)
{
	int ret = 0;

	// xor����
	// ���ٸ� false, �ٸ��� true
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
		_m.insert({ a[i], 1 });	// �̹� ���� ��й�ȣ�� �ߺ��� ����.
	}


	for (int i = 0; i <= n; i++)
	{
		if (_m.find(i) != _m.end()) continue;
		int mn = 987654321;
		for (int j = 0; j < m; j++)
		{
			// ������ 
			//  : ���� �õ��� ��й�ȣ i�� �̹� �õ��� ��й�ȣ a[j~m]���� �����Ÿ� �� ������
			mn = min(SafeDistance(a[j], i), mn);
		}
		// ������ �� �ִ�
		mx = max(mn, mx);
	}

	cout << mx << '\n';

	return 0;
}