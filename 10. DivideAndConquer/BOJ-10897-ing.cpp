// ���� 10897�� Inherited disease
//
// D������ ������ �ڽ��� ������ �� �ڽ��� D + 1 ����
//
// ���� �� �ڽ� ��
// 0 = 1
// 1 = 2
// 2 = 6
// 3 =
// if n > 0
// s(n) = n + 1 * s(n - 1)


#include <iostream>
using namespace std;

typedef long long ll;

const int MOD_NUMBER = 1000000007;
int d, di[101];

//       number : ���� ���뿡 �ο��Ǵ� ��ȣ
//            k : ���� (����)
//    parentCnt : �θ��� ��
// parentNumber : ���� ���뿡�� �θ� ���° �ڽ��̾�����
void go(int number, int k, int parentCnt, int parentNumber)
{
	if (k >= d) return;

	// k�� di[k]��° �ڽ� ã��
	// s(n) = n+1 * s(n-1)
	if (k == 0)
	{
		cout << 1 << '\n';
		go(1, 1, 1, 1);
	}
	else
	{
		ll childCnt = (parentCnt * (k + 1)) % MOD_NUMBER;				            // k������ �� �ڽ��� ��
		ll childPerParent = k <= 1 ? 1 : (childCnt / parentCnt) % MOD_NUMBER;		// �� �ڽ��� �� / �θ��� �� = �� �θ� ���� �ڽ��� ��

		// ���° �θ��� ���° �ڽ�����?
		// �θ� : parentNumber
		// �ڽ� : childPerParent * (parentNumber-1) + di[k]
		ll result = (number + childPerParent * (parentNumber - 1) + di[k]) % MOD_NUMBER;

		cout << result << '\n';
		go((number + childCnt) % MOD_NUMBER, k + 1, childCnt % MOD_NUMBER, result - number);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> d;
	for (int i = 0; i < d; i++)
	{
		cin >> di[i];
	}
	go(0, 0, 0, 0);

	return 0;
}