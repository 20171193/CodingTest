// 프로그래머스 레벨2 피로도
// 재귀 풀이
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int ret = 0;

void go(int k, bool visited[8], vector<vector<int>> dungeons, int count)
{
    ret = max(ret, count);

    for (int i = 0; i < dungeons.size(); i++)
    {
        if (visited[i])
            continue;
        if (dungeons[i][0] > k)
            continue;

        visited[i] = true;
        go(k - dungeons[i][1], visited, dungeons, count + 1);
        visited[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    bool visited[8] = { false, };
    go(k, visited, dungeons, 0);
    return ret;
}

int main()
{
    vector<vector<int>> d = { {80,20}, {50,40}, {30,10} };
    solution(80, d);
    cout << ret << '\n';
    return 0;
}