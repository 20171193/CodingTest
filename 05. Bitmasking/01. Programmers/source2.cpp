// ���α׷��ӽ� ����2 �������ǥ
// ��Ʈ����ŷ Ǯ��

#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    while (a != b)
    {
        ++answer;
        if (a > 1)
            a = a % 2 == 0 ? a >> 1 : (a + 1) >> 1;
        if (b > 1)
            b = b % 2 == 0 ? b >> 1 : (b + 1) >> 1;
    }

    return answer;
}