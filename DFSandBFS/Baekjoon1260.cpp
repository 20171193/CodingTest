//// 백준 1260 DFS와 BFS
//
//// - 그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력
//// - 정점 번호가 작은 것을 먼저 방문하라.
//
//// n : 정점 개수
//// m : 간선 개수
//// v : 시작 정점
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
//// 출력용 벡터
//vector<int> printVec;
//
//void DFS(int node) {
//	//// ver. 재귀
//	//visited[node] = true;
//	//cout << node << " ";
//	//for (int i = 0; i < vec[node].size(); i++) {
//	//	if (visited[vec[node][i]]) continue;
//	//	DFS(vec[node][i]);
//	//}
//
//	// ver. 스택
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
//	// 출력
//	for (int i : printVec) {
//		cout << i << " ";
//	}
//	printVec.clear();
//}
//
//void BFS(int node) {
//	memset(visited, false, sizeof(visited));
//
//	// 탐색
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
//	// 출력
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
//	// 입력
//	for (int i = 0; i < m; i++) {
//		int s = 0, e = 0;
//		cin >> s >> e;
//		vec[s].push_back(e);
//		vec[e].push_back(s);
//	}
//	// 정렬 (정점 번호가 낮은 순으로 탐색)
//	for (int i = 0; i < n; i++) sort(vec[i].begin(), vec[i].end());
//
//	DFS(v);
//	cout << "\n";
//	BFS(v);
//	return 0;
//}