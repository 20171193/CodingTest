// ���α׷��ӽ� ����2 ��ɰ��� 
#include <string>
#include <vector>

using namespace std;

bool erase[101];

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    for (int i = 0; i < progresses.size(); i++)
    {
        if (erase[i]) continue;
        int cnt = 1;
        int remainProgress = 100 - progresses[i];

        // �������� �ɸ��� �ð�
        int days = remainProgress / speeds[i];
        days = remainProgress % speeds[i] > 0 ? days + 1 : days;
        // �����Ϸ�
        erase[i] = true;

        bool prev = true;
        // �� �۾� Ȯ��
        for (int j = i + 1; j < progresses.size(); j++)
        {
            if (erase[j]) continue;

            progresses[j] += days * speeds[j];
            if (progresses[j] >= 100)
            {
                // ���� ���μ����� ������ �Ϸ�� ��� ����
                if (prev)
                {
                    // �����Ϸ�
                    erase[j] = true;
                    cnt++;
                }
            }
            else
            {
                // ���� ���μ������ʹ� ������������.
                prev = false;
                continue;
            }
        }

        answer.push_back(cnt);
    }

    return answer;
}