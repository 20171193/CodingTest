// 프로그래머스 레벨3 짝지어 제거하기
#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> q;
    for (int i = 0; i < s.length(); i++) {
        if (i == s.length() - 1) {
            if (q.empty()) q.push(s[i]);
            else {
                if (q.top() == s[i]) q.pop();
                else q.push(s[i]);
            }
        }
        else {
            if (q.empty()) {
                q.push(s[i]);
            }
            else {
                if (q.top() == s[i]) q.pop();
                else {
                    q.push(s[i]);
                }
            }
        }
    }
    answer = q.size() == 0 ? 1 : 0;

    return answer;
}