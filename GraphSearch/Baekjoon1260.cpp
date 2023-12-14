//// ���� 1260 DFS�� BFS
//
//// - �׷����� DFS�� Ž���� ����� BFS�� Ž���� ����� ���
//// - ���� ��ȣ�� ���� ���� ���� �湮�϶�.
//
//// n : ���� ����
//// m : ���� ����
//// v : ���� ����
//
//#include <iostream>
//#include <queue>
//#include <stack>
//#include <vector>
//#include <algorithm>
//#include <memory.h>
//using namespace std;
//
//int n, m, v;
//bool visited[1001];
//vector<int> vec[1001];
//
//// ��¿� ����
//vector<int> printVec;
//
//void DFS(int node) {
//	//// ver. ���
//	//visited[node] = true;
//	//cout << node << " ";
//	//for (int i = 0; i < vec[node].size(); i++) {
//	//	if (visited[vec[node][i]]) continue;
//	//	DFS(vec[node][i]);
//	//}
//
//	// ver. ����
//	stack<int> st;
//	st.push(node);
//
//	while (st.size()) {
//		int temp = st.top();
//		if (!visited[temp]) {
//
//			visited[temp] = 1;
//			printVec.push_back(temp);
//
//			for (auto iter = vec[temp].rbegin(); iter != vec[temp].rend(); iter++) {
//				if (visited[*iter]) continue;
//
//				st.push(*iter);
//			}
//		}
//		else 
//			st.pop();
//	}
//
//	// ���
//	for (int i : printVec) {
//		cout << i << " ";
//	}
//	printVec.clear();
//}
//
//void BFS(int node) {
//	memset(visited, false, sizeof(visited));
//
//	// Ž��
//	queue<int> q;
//	visited[node] = true;
//	q.push(node); 
//	printVec.push_back(node);
//
//	while (q.size()) {
//		int temp = q.front(); 
//		q.pop();
//		for (int i = 0; i < vec[temp].size(); i++) {
//			if (visited[vec[temp][i]]) continue;
//
//			visited[vec[temp][i]] = true;
//			q.push(vec[temp][i]);
//			printVec.push_back(vec[temp][i]);
//		}
//	}
//
//	// ���
//	for (int i : printVec) {
//		cout << i << " ";
//	}
//	printVec.clear();
//	cout << "\n";
//}
//
//
//int main() {
//	cin >> n >> m >> v;
//
//	// �Է�
//	for (int i = 0; i < m; i++) {
//		int s = 0, e = 0;
//		cin >> s >> e;
//		vec[s].push_back(e);
//		vec[e].push_back(s);
//	}
//	// ���� (���� ��ȣ�� ���� ������ Ž��)
//	for (int i = 0; i < n; i++) sort(vec[i].begin(), vec[i].end());
//
//	DFS(v);
//	cout << "\n";
//	BFS(v);
//	return 0;
//}