// ���� 2212�� ����

// k���� �������� �������� �� ��� �������� ���� �ּҰ� �� �� �ְ�

// �׸���
//  : �������� �ִ��� �۰� k���� �������� ������

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

set<int> input;
int n, k, sensor[10001];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		input.insert(temp);
	}
	vector<int> sensor(input.begin(), input.end());
	sort(sensor.begin(), sensor.end());


	return 0;
}