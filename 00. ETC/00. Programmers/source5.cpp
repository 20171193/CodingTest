// ���α׷��ӽ� ����2 ����ä�ù�
// 2019 KAKAO BLIND RECRUITMENT

#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

// uid�� ����


vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m; // {id, name}

    // �̸� ����
    for (int i = 0; i < record.size(); i++)
    {
        if (record[i][0] == 'L') continue;

        int j = 6;
        if (record[i][0] == 'C') j = 7;
        string id = "", name = ""; bool isName = false;
        for (j; j < record[i].length(); j++)
        {
            if (record[i][j] == ' ')
            {
                isName = true;
                continue;
            }

            if (isName)
                name += record[i][j];
            else
                id += record[i][j];
        }
        if (m.find(id) == m.end()) m.insert({ id,name });
        else m[id] = name;
    }

    string enter = "���� ���Խ��ϴ�.";
    string leave = "���� �������ϴ�.";

    for (int i = 0; i < record.size(); i++)
    {
        if (record[i][0] == 'C') continue;

        string id = "";
        // find id
        for (int j = 6; j < record[i].length(); j++)
        {
            if (record[i][j] == ' ') break;
            id += record[i][j];
        }

        // result
        if (record[i][0] == 'E')
        {
            answer.push_back(m[id] + enter);
        }
        else
        {

            answer.push_back(m[id] + leave);
        }
    }

    return answer;
}