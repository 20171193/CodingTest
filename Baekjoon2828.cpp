//// ���� 2828�� ��� ��� ����
//
//// - ��ũ�� n ĭ
//// - �ٱ��� m ĭ (1, m)
//// - �ٱ��� �̵��Ÿ��� �ּڰ�
//
//// 1. �ٱ��� ���� ���� (left, right=m)
//// 2. ����� �������� ��ǥ�� ���� �ٱ��� �̵�
////   a. ���� �� : �̵�x
////   b. ���� : left - apple
////   c. ���� : apple - right
//
//
//#include <iostream>
//using namespace std;
//
//#define move aaaa
//
//int n, m, j, move, temp, a[21];
//pair<int, int> basket;
//
//int main() {
//	cin >> n >> m >> j;
//	
//	for (int i = 0; i < j; i++) {
//		cin >> a[i];
//	}
//	basket = { 1, m };
//
//	for (int i = 0; i < j; i++) {
//		// ���� �� 
//		if (basket.first <= a[i] && basket.second >= a[i]) continue;
//		// ����
//		if (basket.first > a[i]) {
//			temp = basket.first - a[i];
//			basket.first -= temp;
//			basket.second -= temp;
//		}
//		// ����
//		else {
//			temp = a[i] - basket.second;
//			basket.first += temp;
//			basket.second += temp;
//		}
//
//		move += temp;
//	}
//
//	cout << move << '\n';
//
//	return 0;
//}