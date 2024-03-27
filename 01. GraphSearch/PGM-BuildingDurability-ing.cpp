#include <string>
#include <vector>

using namespace std;


// 1 ����
// 2 ȸ��

void Skill(vector<vector<int>>& board, vector<int> skill)
{
    for (int i = skill[1]; i <= skill[3]; i++)
    {
        for (int j = skill[2]; j <= skill[4]; j++)
        {
            // type, r1, c1, r2, c2, degree
            board[i][j] += skill[0] == 1 ? -skill[5] : skill[5];
        }
    }
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;

    for (int i = 0; i < skill.size(); i++)
    {
        Skill(board, skill[i]);
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] > 0)
                answer++;
        }
    }

    return answer;
}

// ���α׷��ӽ� ���� 3 (�ǹ� ������ - ���� OR ȸ��)

// �׽�Ʈ���̽� ��� ���
// ȿ���� ��� ����

// ���� ����� ã��
// �ı��� ��ŭ�� ������ �޴� ���� ���
// ������ ��ŭ�� ȸ���� �޴� ���� ���