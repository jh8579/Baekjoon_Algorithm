// 효율적인 해킹
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
int Max = -1;

vector<int> board[10010];
queue<int> q;

int visit[20010];
int record[20010];

int BFS();

int main() {
	cin >> V >> E;						// 초기화

	for (int i = 0; i < E; i++) {
		int u, v;

		cin >> u >> v;
		board[v].push_back(u);
	}

	for (int i = 1; i <= V; i++) {

		for (int j = 1; j <= V; j++) {	// 계산 때마다 초기화
			visit[j] = -1;
		}
		visit[i] = 1;					// 첫 요소 0으로 초기화
		q.push(i);						// 첫 요소 푸쉬
		record[i] = BFS();				// 최대값 저장

		Max = max(record[i], Max);		// 전체 최대값 갱신
	}

	for (int j = 1; j <= V; j++) {		// 최대값을 가지는 경우 오름차순 출력
		if (record[j] == Max) {
			cout << j << " ";
		}
	}
	cin >> V;
}

int BFS() {
	int cnt = 0;						// 최대값 카운트

	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		for (int i = 0; i < board[temp].size(); i++) {
			if (visit[board[temp][i]] < 0) {						// 거치지 않은 경우
				visit[board[temp][i]] = 1;
				q.push(board[temp][i]);
				cnt++;												// 거칠때 마다 카운트 갱신
			}
		}
	}	
	return cnt;														// 최대값 리턴
}