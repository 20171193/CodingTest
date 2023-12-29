// ���α׷��ӽ� ����2 Ʃ��

#include <string>
#include <vector>
#include <queue>
using namespace std;

int tp[100001];

vector<int> solution(string s) {
    vector<int> answer;

    string prev = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            prev += s[i];
        }
        else
        {
            if (!prev.length()) continue;
            else
            {
                // �ش� ���� �ߺ��� Ƚ��
                tp[stoi(prev)]++;
                prev = "";
            }
        }
    }

    // ���� ���� ������ Ʃ���� �迭�� �պκп� ��ġ.
    // PrioriyQueue�� ����Ͽ� PQ ������ ���� ���� �󵵼��� Ʃ���� ��ġ��Ŵ.
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < 100001; i++)
    {
        if (tp[i]) pq.push({ tp[i], i });
    }
    while (pq.size())
    {
        answer.push_back(pq.top().second);
        pq.pop();
    }

    return answer;
}