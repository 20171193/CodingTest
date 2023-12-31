// ���α׷��ӽ� ����2 �ֽİ���
#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());

    stack<pair<int, int>> own;

    int curP = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        // �ֽ��� �϶���
        if (curP > prices[i])
        {
            while (!own.empty())
            {
                if (own.top().second > prices[i])
                {
                    answer[own.top().first] = i - own.top().first;
                    own.pop();
                }
                else break;
            }
        }
        own.push({ i, prices[i] });
        curP = prices[i];
    }

    // ���� �� ó��
    while (!own.empty())
    {
        answer[own.top().first] = prices.size() - own.top().first - 1;
        own.pop();
    }

    return answer;
}