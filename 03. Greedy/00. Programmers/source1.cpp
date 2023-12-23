#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// ��� ����� �����ؾ���.
// ���ſ� ��� + ������ ��������� �¿��

// ù��° �õ� 
// ���, ȿ���� ���
int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end(), greater<>());

    int j = people.size() - 1;
    for (int i = 0; i < people.size(); i++)
    {
        int _limit = limit - people[i];
        for (j; j > i; j--)
        {
            if (_limit - people[j] >= 0)
            {
                j--;
                break;
            }
            break;
        }
        answer++;
    }

    return answer;
}

// �ι�° �õ� : ���� �� ������ Ǯ��
// ���, ȿ���� ���
int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end(), greater<>());

    int small = people.size() - 1;
    for (int big = 0; big <= small; big++)
    {
        if (limit - (people[big] + people[small]) >= 0)
        {
            small--;
        }
        answer++;
    }

    return answer;
}