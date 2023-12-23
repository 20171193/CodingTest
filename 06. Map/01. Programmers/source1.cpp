// 프로그래머스 레벨2 달리기 경주

#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// 현재등수 : players
// 추월한 선수 : callings

// swap(이름이 불린 선수, 바로 앞의 선수)

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;

    map<string, int> nameKeyMap;
    map<int, string> orderKeyMap;

    // 사람, 등수
    for (int i = 0; i < players.size(); i++)
    {
        nameKeyMap.insert({ players[i], i });
        orderKeyMap.insert({ i,players[i] });
    }

    for (int i = 0; i < callings.size(); i++)
    {
        // 앞지르는 선수의 인덱스
        int index = nameKeyMap[callings[i]];

        swap(players[index], players[index - 1]);

        // 맵 업데이트

        nameKeyMap[callings[i]]--;
        nameKeyMap[orderKeyMap[index - 1]]++;

        orderKeyMap[index] = orderKeyMap[index - 1];
        orderKeyMap[index - 1] = callings[i];
    }

    answer = players;

    return answer;
}