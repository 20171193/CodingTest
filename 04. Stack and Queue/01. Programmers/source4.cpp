// ���α׷��ӽ� ����2 ��ȣ ȸ���ϱ�
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;

    stack<char> st;

    // ȸ�� ����
    // �ùٸ� ��ȣ���� üũ

    for (int i = 0; i < s.length(); i++)
    {
        int idx = i;
        int cnt = 0;
        for (int j = 0; j < s.length(); j++)
        {
            if (s[idx] == '(' || s[idx] == '{' || s[idx] == '[')
                st.push(s[idx]);
            else
            {
                if (st.empty())
                {
                    answer--;
                    break;
                }
                else
                {
                    if (st.top() + 1 == s[idx] || st.top() + 2 == s[idx])
                    {
                        st.pop();
                    }
                    else
                    {
                        st.push(s[idx]);
                    }
                }
            }


            if (idx == s.length() - 1)
                idx = 0;
            else
                idx++;
        }

        if (st.empty())
            answer++;
        else
        {
            while (!st.empty()) st.pop();
        }
    }

    return answer;
}