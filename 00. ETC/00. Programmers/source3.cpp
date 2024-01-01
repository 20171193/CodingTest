// ���α׷��ӽ� ����2 k�������� �Ҽ� ���� ���ϱ�

// k���� ��ȯ�ϱ�, �Ҽ� ���ϱ� 

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

// k���� ��ȯ
string ret(int n, int k)
{
    string str = "";
    int temp = n;

    while (temp)
    {
        str += (temp % k + '0');
        temp /= k;
    }
    return string(str.rbegin(), str.rend());
}

// �Ҽ�����? true / false
bool isPrime(long long num)
{
    if (num < 2) return false;
    if (num == 2) return true;

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;

    string _k = ret(n, k);

    string temp = "";

    for (int i = 0; i < _k.length(); i++)
    {
        if (temp.length() > 0 && _k[i] == '0')
        {
            if (isPrime(stoll(temp))) answer++;
            temp = "";
        }
        else
        {
            temp += _k[i];
        }
    }

    if (!temp.empty())
    {
        if (isPrime(stoll(temp))) answer++;
    }


    return answer;
}