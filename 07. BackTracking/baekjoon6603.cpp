// ���� 6603�� �ζ�
// ���� �ζ� {1 ~ 49}
// k(k > 6)���� ���� ��� ���� S�� ���� ���� �� ���� ������ ��ȣ�� �����ϴ� ��.

// - �ߺ��� ������� ���� : ������ Ǯ�� 
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