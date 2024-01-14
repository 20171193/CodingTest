// 프로그래머스 레벨2 H-Index
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    int n = citations.size();
    for (int i = 0; i < n; i++)
    {
        int h = n - i;
        if (citations[i] >= h)
        {
            answer = h;
            break;
        }
    }
    return answer;
}