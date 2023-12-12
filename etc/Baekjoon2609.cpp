// ���� 2609�� �ִ������� �ּҰ����

// ��Ŭ���� ȣ����

#include <iostream>
#include <math.h>
using namespace std;

int A, B, tempA, tempB, remain, minMul, maxDiv;

int main() {
	cin >> A >> B;
	if (A == 0 || B == 0) return 0;
	tempA = A; tempB = B;

	if (tempA < tempB) {
		int temp = tempA;
		tempA = tempB;
		tempB = temp;
	}

	while (tempB != 0) {
		int temp = tempA % tempB;
		tempA = tempB;
		tempB = temp;
	}

	maxDiv = tempA;
	minMul = A * B / maxDiv;

	cout << maxDiv << '\n';
	cout << minMul << '\n';

	return 0;
}