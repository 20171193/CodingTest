// 프로그래머스 레벨2 기능개발 
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

        // 배포까지 걸리는 시간
        int days = remainProgress / speeds[i];
        days = remainProgress % speeds[i] > 0 ? days + 1 : days;
        // 배포완료
        erase[i] = true;

        bool prev = true;
        // 뒷 작업 확인
        for (int j = i + 1; j < progresses.size(); j++)
        {
            if (erase[j]) continue;

            progresses[j] += days * speeds[j];
            if (progresses[j] >= 100)
            {
                // 이전 프로세스가 개발이 완료된 경우 배포
                if (prev)
                {
                    // 배포완료
                    erase[j] = true;
                    cnt++;
                }
            }
            else
            {
                // 다음 프로세스부터는 배포하지않음.
                prev = false;
                continue;
            }
        }

        answer.push_back(cnt);
    }

    return answer;
}