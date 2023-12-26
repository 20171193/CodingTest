// ���α׷��ӽ� ����2 ����ê�κ�

// BFSǮ��
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

pair<int, int> clearPosition;   // G ��ġ
pair<int, int> robotPosition;   // R ��ġ
int cx, cy, n, m, visited[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(vector<string> board)
{
    queue<pair<int, int>> q;
    q.push(robotPosition);
    visited[robotPosition.first][robotPosition.second] = 1;
    while (q.size())
    {
        pair<int, int> temp = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = temp.second;
            int ny = temp.first;
            while (!(nx < 0 || nx >= m || ny < 0 || ny >= n) && board[ny][nx] != 'D')   // �ش� ������ ��(���� �� �Ǵ� ��)���� ����.
            {
                nx += dx[i];
                ny += dy[i];
            }
            nx -= dx[i];
            ny -= dy[i];

            if (temp == make_pair(ny, nx)) continue;    // �ش� ������ �����ִ� ��� continue;

            if (visited[ny][nx])
            {
                // �̹� �湮�� ��ǥ�� ��� �ִܰŸ��� ����
                visited[ny][nx] = min(visited[ny][nx], visited[temp.first][temp.second] + 1);
            }
            else
            {
                // �湮���� ���� ��ǥ�ϰ�� �湮üũ(�Ÿ� ������Ʈ) �� ť�� push 
                visited[ny][nx] = visited[temp.first][temp.second] + 1;
                q.push({ ny,nx });
            }
        }
    }
}


int solution(vector<string> board) {
    int answer = 0;

    n = board.size();       // �� y�� �������Ҵ�
    m = board[0].length();  // �� x�� �������Ҵ�
    // �κ��� ��� ���߾������?
    for (int y = 0; y < board.size(); y++)
    {
        for (int x = 0; x < board[y].length(); x++)
        {
            if (board[y][x] == 'G')
            {
                clearPosition = { y,x };
            }
            else if (board[y][x] == 'R')
            {
                robotPosition = { y,x };
            }
        }
    }

    bfs(board);
    answer = visited[clearPosition.first][clearPosition.second];
    if (answer == 0) return -1;

    return answer - 1;
}

int main()
{
    vector<string> board = { "...D..R", ".D.G...", "....D.D", "D....D.", "..D...." };
    cout << solution(board) << '\n';

    return 0;
}