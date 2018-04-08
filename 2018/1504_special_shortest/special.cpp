// 특정한 최단 경로
//
// issue 1 :각 함수 마다 -1을 반환하는지 확인하는게 어렵다.
// 해결방법 : define INF를 통해 정수 최대값으로 설정해주고 합에서 INF를 넘었는지 검증한다.
//			  그러나 채점 결과 코드 길이는 줄었으나 메모리는 오히려 조금 더 사용하였다.

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

	for (int i = 0; i < E; i++) {		// 초기화
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

		for (int i = 0; i < board[temp].size(); i++) {							// 더 작은 값인 경우 갱신
			if (visit[board[temp][i].x] > visit[temp] + board[temp][i].y) {		
				visit[board[temp][i].x] = visit[temp] + board[temp][i].y;
				q.push(board[temp][i].x);
			}
		}
	}
	return visit[end];
}