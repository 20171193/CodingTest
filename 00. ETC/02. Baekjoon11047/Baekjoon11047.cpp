 //백준 11047번 - 동전 0

 //동전 N 종류, 가치의 합 K  
 //필요한 동전 개수의 최솟값?
 //입력: 첫째 줄 N(1<=N<=10), K(1<=K<=100,000,000)
	//	둘째 줄부터 N개의 줄에 동전의 가치 Ai가 오름차순으로 주어짐.
	//	1<=Ai<=1,000,000  A1 = 1, i >= 2 인 경우에 Ai는 Ai-1 의 배수
 //출력 : 첫째 줄에 K원을 만드는데 필요한 동전 개수의 최솟값을 출력.

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