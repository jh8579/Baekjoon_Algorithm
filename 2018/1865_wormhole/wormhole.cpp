// 웜홀
//
// issue 1 : 음수 가중치가 존재하기 때문에 큐로 코딩하면 무한으로 루프가 돌 가능성이 존재한다.
// 해결방법 : 다익스트라를 v-1번 돌려 벨만포드 알고리즘을 사용한다.
//
#define _CRT_SECURE_NO_WARNINGS
#define m(x, y) make_pair(x,y)
#define INF 0x7fffffff

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int T, N, M, W;

queue<int> q;
vector<pair<int,int>> road[510];

int visit[510];

int dikstra();

int main() {
	scanf("%d", &T);

	while(T--) {			// 각 테스트 케이스

		scanf("%d%d%d", &N, &M, &W);

		for (int i = 0; i < M; i++) {
			int s, e, t;
			scanf("%d%d%d", &s, &e, &t);
			road[s].push_back(m(e, t));
			road[e].push_back(m(s, t));
		}
		for (int i = 0; i < W; i++) {
			int s, e, t;
			scanf("%d%d%d", &s, &e, &t);
			road[s].push_back(m(e, -t));
		}

		if (dikstra()) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}

		for (int i = 1; i <= N; i++) {
			road[i].clear();
		}

	}	////////////////////////////////////// 각 테스트 케이스
	cin >> N;
}

int dikstra() {

	int flag;
	fill(visit, visit + N + 1, INF);
	visit[1] = 0;

	for (int i = 1; i <= N- 1; i++) {
		flag = false;

		for (int j = 1; j <= N; j++) {

			if (visit[j] == INF) {
				continue;
			}
			for (int k = 0; k < road[j].size(); k++) {

				pair<int, int> next = road[j][k];
				if (visit[next.first] > visit[j] + next.second) {
					visit[next.first] = visit[j] + next.second;
					flag = true;
				}
			}
		}
		if (!flag) break;
	}
	return flag;
}