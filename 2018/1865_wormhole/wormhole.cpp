// 웜홀
//
//issue 1 : 음수 가중치가 존재하기 때문에 큐로 코딩하면 무한으로 루프가 돌 가능성이 존재한다.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct test {
	int x, y;
};

int T, N, M, W;

queue<int> q;
vector<test> road[510];

int visit[510];

int BFS();

int main() {
	cin >> T;

	for (int k = 0; k < T; k++) {			// 각 테스트 케이스

		cin >> N >> M >> W;

		for (int i = 0; i < M; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			road[s].push_back( { e,t } );
			road[e].push_back( { s,t } );
		}
		for (int i = 0; i < W; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			road[s].push_back({ e,-t });
		}

		int flag = BFS();

		if (flag) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}

	}	////////////////////////////////////// 각 테스트 케이스

	cin >> N;
}

int BFS() {
	for (int k = 1; k <= N; k++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {			// visit -1로 모두 초기화

			visit[j] = 100000;
		}

		visit[k] = 0;
		q.push(k);

		while (!q.empty()) {

			int temp = q.front();
			q.pop();

			if (temp == k && visit[k] < 0) {
				return 1;
			}
			else if (temp == k && cnt) {
				continue;
			}
			cnt++;

			for (int i = 0; i < road[temp].size(); i++) {
				if (visit[road[temp][i].x] < 0) {						// 거치지 않은 경우
					visit[road[temp][i].x] = visit[temp] + road[temp][i].y;
					q.push(road[temp][i].x);
				}
				else {													// 거친 경우
					if (visit[road[temp][i].x] > visit[temp] + road[temp][i].y) {	// 더 작은 값인 경우 갱신
						visit[road[temp][i].x] = visit[temp] + road[temp][i].y;
						q.push(road[temp][i].x);
					}
				}
			}
		}
	}
	
	return 0;
}