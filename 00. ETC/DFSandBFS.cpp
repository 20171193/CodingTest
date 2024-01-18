// 백준 1260번 DFS와 BFS

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

vector<int> Node[1001];
bool visited[1001];
int n, m, v;

void DFS(int curNode)
{
	#pragma region VER. 재귀

	if (visited[curNode]) return;

	visited[curNode] = true;
	cout << curNode << " ";

	for (int i = 0; i < Node[curNode].size(); i++)
	{
		int nextNode = Node[curNode][i];
		if (visited[nextNode]) continue;
		DFS(nextNode);	// 재귀
	}
	#pragma endregion

	#pragma region VER. 스택
	//stack<int> st;
	//st.push(curNode);
	//visited[curNode] = true;
	//cout << curNode << " ";

	//while (st.size())
	//{
	//	int cur = st.top(); st.pop();
	//	for (int i = 0; i < Node[cur].size(); i++)
	//	{
	//		int nextNode = Node[cur][i];
	//		if (visited[nextNode]) continue;

	//		cout << nextNode << " ";
	//		visited[nextNode] = true;
	//		st.push(nextNode);
	//	}
	//}
	#pragma endregion
}
void BFS(int curNode)
{
	queue<int> q;
	q.push(curNode);
	visited[curNode] = true;
	cout << curNode << " ";
	while (q.size())
	{
		int cur = q.front(); q.pop();
		for (int i = 0; i < Node[cur].size(); i++)
		{
			int nextNode = Node[cur][i];
			if (visited[nextNode]) continue;

			cout << nextNode << " ";
			visited[nextNode] = true;
			q.push(nextNode);
		}
	}


}

int main()
{
	cin.tie(NULL);
	iostream::sync_with_stdio(false);

	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		Node[a].push_back(b);
		Node[b].push_back(a);
	}
	DFS(v);
	memset(visited, false, sizeof(visited));	// visited 배열 초기화
	cout << '\n';
	BFS(v);
	return 0;
}