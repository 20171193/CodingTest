//// 백준 3474 교수가 된 현우
//
//// - 자연수N에 대해 N!의 오른쪽 끝에 있는 0의 개수
//// - 범위 1~10억
//
//// ver. 무식하게풀기 
//// 1. N! 구하기
//// 2. 10으로 나눈 나머지가 없을 경우 cnt++
//// 3. 나머지가 생기면 continue
//// 4. 무조건 시간초과
//
//// ver. 소인수분해
//// 1. 뒷자리가 10 = 1*10
//// 2. 즉, N!까지의 2의 개수와 5의 개수를 구해 10을 만들 수 있는 개수
//// 3. ex) 2 = 3개, 5 = 2개 --> 10 = 2개
//
//
//#include <iostream>
//using namespace std;
//
//typedef long long ll;
//
//int t, num, cnt, two, five;
//ll temp;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> t;
//	while (t--) {
//		cin >> num;
//		temp = 1; two = 0; five = 0;
//		for (int i = 2; i <= num; i++) {
//			temp *= i;
//
//			if(temp % 2 == 0)
//		}
//		
//		
//	}
//
//	return 0;
//}