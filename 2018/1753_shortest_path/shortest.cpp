// �ִܰ��
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
	
	for (int i = 1; i <= V; i++) {			// visit -1�� ��� �ʱ�ȭ
		
		visit[i] = -1;
	}

	visit[start] = 0;
	q.push(start);

	BFS();

	for (int i = 1; i <= V; i++) {			// visit�� 0 ���ϸ� INF ���
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
			if (visit[board[temp][i].x] < 0) {						// ��ġ�� ���� ���
				visit[board[temp][i].x] = visit[temp] + board[temp][i].y;
				q.push(board[temp][i].x);
			}
			else {													// ��ģ ���
				if (visit[board[temp][i].x] > visit[temp] + board[temp][i].y) {	// �� ���� ���� ��� ����
					visit[board[temp][i].x] = visit[temp] + board[temp][i].y;
					q.push(board[temp][i].x);
				}
			}
		}
	}
}