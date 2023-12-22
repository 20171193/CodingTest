#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int operCnt = numbers.size();

    // 비트마스킹
    // 비트가 켜져있으면 +
    // 꺼져있으면 -
    // 타겟 넘버는 1~1000이기 때문에 모든 비트가 꺼져있는 경우는 없음. => (i >= 1)
    for (int i = 1; i < (1 << operCnt); i++)
    {
        int sum = 0;
        for (int j = 0; j < operCnt; j++)
        {
            if (i & (1 << j))
            {
                sum += numbers[j];
            }
            else
            {
                sum -= numbers[j];
            }
        }

        if (sum == target)
        {
            answer++;
        }
    }

    return answer;
}