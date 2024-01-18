// 백준 13904번 과제
// PriorityQueue
#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;

struct HomeWork
{
	int d;
	int w;
	HomeWork(int d, int w)
	{
		this->d = d;
		this->w = w;
	}
};
struct cmpDay {
	bool operator()(HomeWork& a, HomeWork& b)
	{
		return a.d < b.d;
	}
};
struct cmpValue {
	bool operator()(HomeWork& a, HomeWork& b)
	{
		return a.w < b.w;
	}
};

int n, maxDay, ret;

vector<HomeWork> vec;
priority_queue<HomeWork, vector<HomeWork>, cmpDay> dayFrontQ;
priority_queue<HomeWork, vector<HomeWork>, cmpValue> valueFrontQ;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int day = 0, value = 0;
		cin >> day >> value;
		vec.push_back({ day,value });
	}

	for (int i = 0; i < vec.size(); i++)
	{
		dayFrontQ.push(vec[i]);
	}

	maxDay = dayFrontQ.top().d;
	for (int i = maxDay; i >= 1; i--)
	{
		while (dayFrontQ.size() && dayFrontQ.top().d == i)
		{
			valueFrontQ.push(dayFrontQ.top()); dayFrontQ.pop();
		}

		if (valueFrontQ.size())
		{
			ret += valueFrontQ.top().w; valueFrontQ.pop();
		}
	}

	cout << ret << '\n';

	return 0;
}
