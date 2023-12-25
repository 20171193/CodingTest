 //���� 11047�� - ���� 0

 //���� N ����, ��ġ�� �� K  
 //�ʿ��� ���� ������ �ּڰ�?
 //�Է�: ù° �� N(1<=N<=10), K(1<=K<=100,000,000)
	//	��° �ٺ��� N���� �ٿ� ������ ��ġ Ai�� ������������ �־���.
	//	1<=Ai<=1,000,000  A1 = 1, i >= 2 �� ��쿡 Ai�� Ai-1 �� ���
 //��� : ù° �ٿ� K���� ����µ� �ʿ��� ���� ������ �ּڰ��� ���.

 //ex)  10 4200
	//	1
	//	5
	//	10
	//	...
	//	50000

#include <iostream>

int coin[11];

int main()
{
	int N, K = 0;

	std::cin >> N >> K;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> coin[i];
	}
 	
	int top = N-1;
	int count = 0;

	while (top >= 0)
	{
		if (K / coin[top] == 0)
		{
			top--;
		}
		else
		{
			int numcoin = K / coin[top];
			count += numcoin;
			K %= coin[top];
			top--;
		}
	}

	std::cout << count;

	return 0;
}