// ���� 9328�� ����

// 1�� ������ ������ ������ ���Ŀ�����.
// ��鵵���� ������ ��ġ�� ��� ��Ÿ���ְ�
// ������ ���� ������ �Ϻ� ���谡 �ʿ���.
// �Ϻ� ����� �������ְ�, �Ϻ� ����� ������ �ٴڿ� ������ ����.

// . : �����
// * : ��
// $ : ����
// �빮�� : ��
// �ҹ��� : ����
// �빮�� �ҹ��� ���� ��Ī��. A�� ����� a

// ��ĥ �� �ִ� ������ �ִ� ������ ���
// ���� �� ������ ������ �ִ������� ���ľ���.

// - ������������ Ž��
// - �������� �÷��̾���� ������ �� �ִ���?
// - ��λ� ���� �ִٸ�, ���� �ش��ϴ� ������� ������ �� �ִ���?
// - �÷��̾ ���踦 ������ �ִ���?

#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

int t, h, w, a[101][101], visited[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

bool ownKey[27];
vector<pair<int, int>> documents;

void bfs()
{
	// ������ ť�� push-pop�� �ǽ��ϸ� �ʺ�켱Ž���� �� ���
	// Ž�� �� ���踦 ȹ���ߴ��� Ž�� �߿� �̹� ������ ���� �� �� ����
	// ���踦 ȹ���� ��� visited�迭�� queue�� �ʱ�ȭ�ϴ� ������ �ʿ�.
	// ex)
	//		1.a���踸�� ������ Ž�� -> b���� �߰� -> �湮�ʱ�ȭ, ó������ �ٽ� Ž�� 
	//		2.a,b���踦 ������ Ž�� -> c���� �߰� -> �湮�ʱ�ȭ, ó������ �ٽ� Ž��
	//		3.a,b,c���踦 ������ Ž�� -> ....
	// 
	//		- ���������� documents��ġ�� �湮�� ��ġ�� ī���� +
	//		- ������
	// 

	/// <summary>
	/// ���� �����ڸ� �� ����� �� �ִ� ��ġ���� bfsŽ�� �ǽ�.
	/// ����� �� �ִ� ��ġ��
	/// 1.����� (.)
	/// 2.���� (a-z)
	/// 3.���� ($)
	/// 4.�� (A-Z) ***���� �������ִ� ����� ��Ī�Ǵ� ��
	/// </summary>
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			bool reset = false;	// Ž�� �� ���ο� ���踦 ȹ���� ���

			// ù ������ġ?
			if (i > 0 && i < h - 1)
			{
				if (j > 0 && j < w - 1) continue;	// ���� �����ڸ��� �ƴ� ���
			}
			if (a[i][j] == '*') continue;	// ���� ��ġ�� ���� ���
			if ((a[i][j] >= 'A' && a[i][j] <= 'Z') && !ownKey[a[i][j] - 'A']) continue;	// ���� ��ġ�� ���踦 ������ ���� �� �ϰ��
			if ((a[i][j] >= 'a' && a[i][j] <= 'z') && !ownKey[a[i][j] - 'a']) {	// ���� ��ġ�� ������ ��� -> ���� ȹ�� -> Ž���� ����Ǹ� �湮�ʱ�ȭ, i, j �� �ʱ�ȭ 
				// �ݺ����� ó������ �����ϵ�����.
				reset = true;
				ownKey[a[i][j] - 'a'] = true;
			}
			visited[i][j] = 1;
			queue<pair<int, int>> q;
			q.push({ i,j });

			while (q.size())
			{
				pair<int, int> temp = q.front();
				q.pop();
				for (int k = 0; k < 4; k++)
				{
					int nx = temp.second + dx[k];
					int ny = temp.first + dy[k];

					if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
					if (visited[ny][nx]) continue;
					if (a[ny][nx] == '*') continue;
					else if ((a[ny][nx] >= 'A' && a[ny][nx] <= 'Z') && !ownKey[a[ny][nx] - 'A']) continue;
					else if ((a[ny][nx] >= 'a' && a[ny][nx] <= 'z') && !ownKey[a[ny][nx] - 'a']) {
						ownKey[a[ny][nx] - 'a'] = true;	// ���� ȹ��
						reset = true;	// ó������ Ž�� �ϵ��� reset ���� true�� �Ҵ�
						memset(visited, false, sizeof(visited));	// ���� ��ġ���� ��Ž���ϵ��� �湮 �迭�� ���� �ʱ�ȭ
						while (q.size()) q.pop();	// ť�� ��� �ʺ�Ž�� ��� ����
					}

					visited[ny][nx] = 1;
					q.push({ ny,nx });
				}
			}
			if (reset)
			{
				i = 0;
				j = -1;
				memset(visited, false, sizeof(visited));
			}
		}
	}
}

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> h >> w;
		for (int i = 0; i < h; i++)
		{
			string temp = "";
			cin >> temp;
			for (int j = 0; j < temp.length(); j++)
			{
				a[i][j] = temp[j];
				if (a[i][j] == '$')
				{
					documents.push_back({ i,j });	// ������ �����ϴ� ��ġ �Ҵ�
				}
			}
		}
		string temp = "";
		cin >> temp;
		if (temp[0] != '0')
		{
			for (int i = 0; i < temp.length(); i++)
			{
				ownKey[temp[i] - 'a'] = true;	// ������ �ִ� ���� �Ҵ�
			}
		}
		bfs();

		// ��ģ ���� ī���� / ���
		int cnt = 0;
		for (int i = 0; i < documents.size(); i++)
		{
			if (visited[documents[i].first][documents[i].second] == 1) cnt++;
		}
		cout << cnt << '\n';

		memset(a, 0, sizeof(a));
		memset(visited, 0, sizeof(visited));
		memset(ownKey, false, sizeof(ownKey));
		documents.clear();
	}
	return 0;
}

