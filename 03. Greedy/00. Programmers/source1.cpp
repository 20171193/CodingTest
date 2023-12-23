#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 모든 사람을 구출해야함.
// 무거운 사람 + 가벼운 사람순으로 태우기

// 첫번째 시도 
// 통과, 효율성 통과
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

// 두번째 시도 : 조금 더 간단한 풀이
// 통과, 효율성 통과
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