// 최단경로
//
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct edge {
	int x, y;
};
int V, E;
int start;

vector<edge> board[20010];
queue<int> q;

int visit[20010];

void BFS();

int main() {
	cin >> V >> E >> start;

	for (int i = 0; i < E; i++) {
		int u, v, w;

		cin >> u >> v >> w;
		board[u].push_back({ v,w });
	}
	
	for (int i = 1; i <= V; i++) {			// visit -1로 모두 초기화
		
		visit[i] = -1;
	}

	visit[start] = 0;
	q.push(start);

	BFS();

	for (int i = 1; i <= V; i++) {			// visit이 0 이하면 INF 출력
		if (visit[i] < 0) {
			cout << "INF" << endl;
			continue;
		}
		cout << visit[i] << endl;
	}
	cin >> V;
}

void BFS() {
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
}