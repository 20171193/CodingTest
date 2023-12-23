// ���α׷��ӽ� ����2 �޸��� ����

#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// ������ : players
// �߿��� ���� : callings

// swap(�̸��� �Ҹ� ����, �ٷ� ���� ����)

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;

    map<string, int> nameKeyMap;
    map<int, string> orderKeyMap;

    // ���, ���
    for (int i = 0; i < players.size(); i++)
    {
        nameKeyMap.insert({ players[i], i });
        orderKeyMap.insert({ i,players[i] });
    }

    for (int i = 0; i < callings.size(); i++)
    {
        // �������� ������ �ε���
        int index = nameKeyMap[callings[i]];

        swap(players[index], players[index - 1]);

        // �� ������Ʈ

        nameKeyMap[callings[i]]--;
        nameKeyMap[orderKeyMap[index - 1]]++;

        orderKeyMap[index] = orderKeyMap[index - 1];
        orderKeyMap[index - 1] = callings[i];
    }

    answer = players;

    return answer;
}