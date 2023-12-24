// 프로그래머스 레벨2 행렬의 곱셈

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    // 행렬곱셈 조건 : arr1의 열 개수와 arr2의 행 개수가 동일해야함.
    // 3중 for문
    for (int i = 0; i < arr1.size(); i++)
    {
        vector<int> temp;
        for (int j = 0; j < arr2[0].size(); j++)
        {
            int sum = 0;
            for (int k = 0; k < arr1[0].size(); k++)
            {
                sum += arr1[i][k] * arr2[k][j];
            }
            temp.push_back(sum);
        }
        answer.push_back(temp);
    }

    return answer;
}