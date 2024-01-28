// ���� 5904�� Moo ����

#include <iostream>
using namespace std;

typedef long long ll;

// ������ �� ����

// s(0) = 3 = = "moo"									// m�� �� 1��
// 														// m�� ��ġ : 0

														// int curPos = s(0)length() = 3
// s(1) = 10 = k+3 + s(k-1)*2 = s(0) + "mooo" + s(0)	// m�� �� 3��
//														// 1��° m�� ��ġ : curPos
//														// 2��° m�� ��ġ : curPos + s(0).length()
// 														// 3��° m�� ��ġ : s(0).length()*2 + k+3
//														// curPos += s(1).length()

// ��ȭ��
// s(n).length = s(n-1).length * 2 + n - 1 + 3
//   m�� ��ġ = 1. s(n)�� ���۵Ǵ� ���� ��ǥ
//            = 2. ��ǥ + s(n)
//			  = 3. ��ǥ + s(n) + n+3	 

ll n;
int ret = -1;
//   pos : s(count)�� �ۼ��� ��ġ
// count : s(count)
//   len : ���� ������ ���� 

void back(int k, ll len, ll num)
{
	// 0��° ������ ���
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

	// �߰� ������ ��ġ
	if ((num >= midLeft && num <= midRight))
	{
		if (num == midLeft)
			ret = 1;
		else
			ret = 0;
		return;
	}
	else if (num < midLeft)	// ù��° ������ ��ġ
	{
		back(k - 1, (len - (k + 3)) / 2, num);
	}
	else // ����° ������ ��ġ
	{
		back(k - 1, (len - (k + 3)) / 2, num - midRight);
	}
}


void go(int k, ll len)
{
	if (len > n)
	{
		// k-- : �ڷ� ���ư��� n�� ��ǥ Ž��
		back(k, len, n);
		return;
	}

	// ���� ������ ���̰� n���� Ŀ�������� ������ ��� �÷���
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