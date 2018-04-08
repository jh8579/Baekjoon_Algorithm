// Ư���� �ִ� ���
//
// issue 1 :�� �Լ� ���� -1�� ��ȯ�ϴ��� Ȯ���ϴ°� ��ƴ�.
// �ذ��� : define INF�� ���� ���� �ִ밪���� �������ְ� �տ��� INF�� �Ѿ����� �����Ѵ�.
//			  �׷��� ä�� ��� �ڵ� ���̴� �پ����� �޸𸮴� ������ ���� �� ����Ͽ���.

#include <iostream>
#include <queue>
#include <vector>

#define INF 0x7fffffff

using namespace std;

struct edge {
	int x, y;
};

int V, E;

vector<edge> board[810];
queue<int> q;

int drop[2];
long long int visit[810];

long long int minx(long long int x, long long int y);
long long int dikstra(int start, int end);

int main() {
	cin >> V >> E;

	for (int i = 0; i < E; i++) {		// �ʱ�ȭ
		int u, v, w;

		cin >> u >> v >> w;
		board[u].push_back({ v,w });
		board[v].push_back({ u,w });
	}
	for (int i = 0; i < 2; i++) {
		cin >> drop[i];
	}

	long long int c1 = dikstra(1, drop[0]) + dikstra(drop[0], drop[1]) + dikstra(drop[1], V);
	long long int c2 = dikstra(1, drop[1]) + dikstra(drop[1], drop[0]) + dikstra(drop[0], V);
	long long int Min = minx(c1, c2);

	if (Min > INF) {
		cout << -1;
	}
	else {
		cout << Min;
	}
	cin >> V;
}

long long int minx(long long int x, long long int y)
{
	if (x > y)
		return y;
	return x;
}

long long int dikstra(int start, int end) {
	for (int i = 1; i <= V; i++) {
		visit[i] = INF;
	}
	visit[start] = 0;
	q.push(start);
	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		for (int i = 0; i < board[temp].size(); i++) {							// �� ���� ���� ��� ����
			if (visit[board[temp][i].x] > visit[temp] + board[temp][i].y) {		
				visit[board[temp][i].x] = visit[temp] + board[temp][i].y;
				q.push(board[temp][i].x);
			}
		}
	}
	return visit[end];
}