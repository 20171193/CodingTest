// ���α׷��ӽ� ����2 ������� �� ���� ����

// �������� Ǯ��
// - Ʋ�ȴ� ���� 
//  : ��� �� �Ű������� ����� 2���� ���Ϳ� ���ο� ���� ����ؼ� �Ҵ��.
// - �ذ�
//  : ������ 2���� ���͸� �����ϴ� ������� ���

#include <string>
#include <vector>

using namespace std;

int count0, count1;

void go(int y, int x, int n, vector<vector<int>>& arr)
{
    bool isNum = arr[y][x];

    for (int i = y; i < y + n; i++)
    {
        for (int j = x; j < x + n; j++)
        {
            if (arr[i][j] != isNum)
            {
                go(y, x, n / 2, arr);
                go(y, x + n / 2, n / 2, arr);
                go(y + n / 2, x, n / 2, arr);
                go(y + n / 2, x + n / 2, n / 2, arr);
                return;
            }
        }
    }

    if (isNum) count1++;
    else count0++;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    go(0, 0, arr.size(), arr);
    answer.push_back(count0);
    answer.push_back(count1);
    return answer;
}