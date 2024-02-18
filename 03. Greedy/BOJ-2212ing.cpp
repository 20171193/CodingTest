// 백준 2212번 센서

// k개의 구간으로 나누었을 때 모든 구간차의 합이 최소가 될 수 있게

// 그리디
//  : 구간차를 최대한 작게 k개의 구간으로 나누기

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