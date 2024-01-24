// ���� 9663 N-Queen

// ���, ��Ʈ��ŷ
// �� ������ ���� ������ �ùٸ� ��ġ���� üũ
// ��� ���� ���� ���ΰ�� == n���� ���� ������ ��� ī����

#include <iostream>
using namespace std;

int n, ret, arr[16];

bool checkPos(int x)
{
	for (int i = 0; i < x; i++)
	{
		// ��ġ�� ���� ���� ���� �ٸ� ���� �����ϴ��� Ȯ��

		// ex)
		// i = 0, arr[i] = 1
		// x = 1, arr[x] = 1 
		// 0�� 1�࿡ ���� �����ϴµ� 1�� 1�࿡ ���� ��ġ�� ��� false

		// ex)
		// arr[x] - arr[i] = 2    ==>    �࿡���� ���� (width)
		//			 x - i = 2    ==>    �������� ���� (height)
		//      width = height    ==>    �밢�� �� ����
		// ���� ���̿� ���� ���̰� ���� ��� = �밢���� ���� false
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
		// x���� i�� �� �Ҵ�
		arr[x] = i;
		// �ٸ� ���� ������ �� ���ٸ� �ش� ��ġ�� ��ġ �Ϸ�
		// ���� �� Ž��
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
