// ���� 2195�� ���ڿ� ����

// copy = sub_str
// ���� ���Ի���Ͽ� s�� p�� 

// ����for�� 1,000,000

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

			if (p[idx] == s[j]) {	// ���� ���ڿ��� �߰��� ���
				cnt++;
				idx++;				// ���� ����Ȯ���� ���� p�� idx++
			}
			else {
				cnt = 0;
				idx = i;
			}
			mx = max(cnt, mx);	// ���� �������� �ߺ��Ǵ� ���ڰ� �� ���� ���
			// ex)	s = abbaa,	p = aaaaaa
			//		copy(0,1)���� copy(3,2)�� ȿ����
		}
		++ret;
		i += mx;
	}

	cout << ret << '\n';

	return 0;
}
