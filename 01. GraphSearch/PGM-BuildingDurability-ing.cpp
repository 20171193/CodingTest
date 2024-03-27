#include <string>
#include <vector>

using namespace std;


// 1 공격
// 2 회복

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

// 프로그래머스 레벨 3 (건물 내구도 - 공격 OR 회복)

// 테스트케이스 모두 통과
// 효율성 모두 실패

// 공통 행렬을 찾기
// 파괴될 만큼의 공격을 받는 공통 행렬
// 복구될 만큼의 회복을 받는 공통 행렬