// 프로그래머스 레벨2 리코챗로봇

// BFS풀이
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

pair<int, int> clearPosition;   // G 위치
pair<int, int> robotPosition;   // R 위치
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
            while (!(nx < 0 || nx >= m || ny < 0 || ny >= n) && board[ny][nx] != 'D')   // 해당 방향의 끝(맵의 끝 또는 벽)까지 전진.
            {
                nx += dx[i];
                ny += dy[i];
            }
            nx -= dx[i];
            ny -= dy[i];

            if (temp == make_pair(ny, nx)) continue;    // 해당 방향이 막혀있는 경우 continue;

            if (visited[ny][nx])
            {
                // 이미 방문한 좌표일 경우 최단거리로 갱신
                visited[ny][nx] = min(visited[ny][nx], visited[temp.first][temp.second] + 1);
            }
            else
            {
                // 방문하지 않은 좌표일경우 방문체크(거리 업데이트) 후 큐에 push 
                visited[ny][nx] = visited[temp.first][temp.second] + 1;
                q.push({ ny,nx });
            }
        }
    }
}


int solution(vector<string> board) {
    int answer = 0;

    n = board.size();       // 맵 y축 사이즈할당
    m = board[0].length();  // 맵 x축 사이즈할당
    // 로봇이 어디에 멈추어야할지?
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