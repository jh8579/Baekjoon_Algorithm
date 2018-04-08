// 특정한 최단 경로
//
// issue 1 :각 함수 마다 -1을 반환하는지 확인하는게 어렵다.

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct edge {
	int x, y;
};

int V, E;
int Min = 100000000;

vector<edge> board[810];
queue<int> q;

int drop[2];
int visit[810];
int flag = 0;

int dikstra(int start, int end);

int main() {
	cin >> V >> E;

	for (int i = 0; i < E; i++) {		// 초기화
		int u, v, w;

		cin >> u >> v >> w;
		board[u].push_back({ v,w });
		board[v].push_back({ u,w });
	}
	for (int i = 0; i < 2; i++) {
		cin >> drop[i];
	}

	int c1;
	int c11 = dikstra(1, drop[0]);
	int c12 = dikstra(drop[0], drop[1]);
	int c13 = dikstra(drop[1], V);

	if (c11 >= 0 && c12 >= 0 && c13 >= 0) {
		c1 = c11 + c12 + c13;
	}
	else {
		c1 = -1;
	}

	int c2;
	int c21 = dikstra(1, drop[1]);
	int c22 = dikstra(drop[1], drop[0]);
	int c23 = dikstra(drop[0], V);

	if (c21 >= 0 && c22 >= 0 && c23 >= 0) {
		c2 = c21 + c22 + c23;
	}
	else {
		c2 = -1;
	}

	if (c1 >= 0 && c2 >= 0) {
		flag = true;
		Min = min(c1, c2);
	}
	
	
	if (flag) {
		cout << Min;
	}
	else {
		cout << -1;
	}
	cin >> V;
}

int dikstra(int start, int end) {
	for (int i = 1; i <= V; i++) {
		visit[i] = -1;
	}
	visit[start] = 0;
	q.push(start);
	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		for (int i = 0; i < board[temp].size(); i++) {
			if (visit[board[temp][i].x] < 0) {						// 거치지 않은 경우
				visit[board[temp][i].x] = visit[temp] + board[temp][i].y;
				q.push(board[temp][i].x);
			}
			else {													// 거친 경우
				if (visit[board[temp][i].x] > visit[temp] + board[temp][i].y) {	// 더 작은 값인 경우 갱신
					visit[board[temp][i].x] = visit[temp] + board[temp][i].y;
					q.push(board[temp][i].x);
				}
			}
		}
	}
	if (visit[end] < 0) {
		return -1;
	}
	else {
		return visit[end];
	}
}