// 백준 4779번 칸토어 집합

// 1. -가 3^n개
// 2. 3등분 후 가운데 문자열을 공백으로 변경.
// 3. 모든 선의 길이가 1일때까지 반복

// 나누고 삭제를 **반복**
// 3^n에서 1이 될때까지 **반복** - 분할 정복(Divide And Conquer)

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <memory.h>
using namespace std;

vector<string> answer;

void DivideAndConquer(int startPos, int n, bool isSpace, string& str)
{
	if (n < 1)
	{
		return;
	}
	if (isSpace)
	{
		for (int i = startPos; i < startPos + n; i++)
		{
			str[i] = ' ';
		}
	}
	DivideAndConquer(startPos, n / 3, false, str);
	DivideAndConquer(startPos + n / 3, n / 3, true, str);
	DivideAndConquer(startPos + n / 3 * 2, n / 3, false, str);
}

int main()
{
	cin.tie(NULL);						// 입출력 연결 해제 (입출력 반복 시 시간 단축)
	ios_base::sync_with_stdio(false);	// stio와 iostream 동기화를 비활성화 (버퍼 공유 해제)

	int n = -1;
	while (1)
	{
		if ((cin >> n).eof()) break;
		string temp = "";
		temp.resize(pow(3, n));
		memset(&temp[0], '-', pow(3, n));
		DivideAndConquer(0, pow(3, n), false, temp);
		answer.push_back(temp);
	}

	for (string s : answer)
	{
		cout << s << '\n';
	}

	return 0;
}
