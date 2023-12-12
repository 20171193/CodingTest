//// 백준 2828번 사과 담기 게임
//
//// - 스크린 n 칸
//// - 바구니 m 칸 (1, m)
//// - 바구니 이동거리의 최솟값
//
//// 1. 바구니 범위 설정 (left, right=m)
//// 2. 사과가 떨어지는 좌표에 맞춰 바구니 이동
////   a. 범위 내 : 이동x
////   b. 좌측 : left - apple
////   c. 우측 : apple - right
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
//		// 범위 내 
//		if (basket.first <= a[i] && basket.second >= a[i]) continue;
//		// 좌측
//		if (basket.first > a[i]) {
//			temp = basket.first - a[i];
//			basket.first -= temp;
//			basket.second -= temp;
//		}
//		// 우측
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