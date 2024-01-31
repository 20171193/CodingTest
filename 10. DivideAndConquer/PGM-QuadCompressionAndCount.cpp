// 프로그래머스 레벨2 쿼드압축 후 개수 세기

// 분할정복 풀이
// - 틀렸던 이유 
//  : 재귀 시 매개변수로 사용한 2차원 벡터에 새로운 값이 계속해서 할당됨.
// - 해결
//  : 기존의 2차원 벡터를 참조하는 방식으로 사용

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