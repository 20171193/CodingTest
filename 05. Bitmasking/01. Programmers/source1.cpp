#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int operCnt = numbers.size();

    // ��Ʈ����ŷ
    // ��Ʈ�� ���������� +
    // ���������� -
    // Ÿ�� �ѹ��� 1~1000�̱� ������ ��� ��Ʈ�� �����ִ� ���� ����. => (i >= 1)
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