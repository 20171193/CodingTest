// 백준 2195번 문자열 복사

// copy = sub_str
// 가장 적게사용하여 s를 p로 

// 이중for문 1,000,000

#include<iostream>
#include<string>
using namespace std;

int ret;
string s, p;
int main()
{
	cin >> s >> p;

	int i = 0;
	while (i < p.length())
	{
		int mx = 0;
		int cnt = 0;
		int idx = i;
		for (int j = 0; j < s.length(); j++)
		{
			if (idx >= p.length()) break;

			if (p[idx] == s[j]) {	// 같은 문자열을 발견한 경우
				cnt++;
				idx++;				// 다음 문자확인을 위해 p의 idx++
			}
			else {
				cnt = 0;
				idx = i;
			}
			mx = max(cnt, mx);	// 같은 문자지만 중복되는 문자가 더 많은 경우
			// ex)	s = abbaa,	p = aaaaaa
			//		copy(0,1)보다 copy(3,2)가 효율적
		}
		++ret;
		i += mx;
	}

	cout << ret << '\n';

	return 0;
}
