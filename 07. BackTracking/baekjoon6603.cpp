// 백준 6603번 로또
// 독일 로또 {1 ~ 49}
// k(k > 6)개의 수를 골라 집합 S를 만든 다음 그 수만 가지고 번호를 선택하는 것.

// - 중복을 허용하지 않음 : 순열로 풀이 
// s.size() P k

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int k = 1;
	while (1)
	{
		cin >> k;
		if (k == 0) break;
		vector<int> vec;
		for (int i = 0; i < k; i++)
		{
			int temp = 0;
			cin >> temp;
			vec.push_back(temp);
		}
		vector<int> perVec;
		for (int i = 0; i < k; i++)
		{
			if (i < 6) perVec.push_back(0);
			else perVec.push_back(1);
		}

		do
		{
			for (int i = 0; i < perVec.size(); i++)
			{
				if (!perVec[i]) cout << vec[i] << ' ';
			}
			cout << '\n';
		} while (next_permutation(perVec.begin(), perVec.end()));
		cout << '\n';
	}
	return 0;
}