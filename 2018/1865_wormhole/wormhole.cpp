// ��Ȧ
//
// issue 1 : ���� ����ġ�� �����ϱ� ������ ť�� �ڵ��ϸ� �������� ������ �� ���ɼ��� �����Ѵ�.
// �ذ��� : ���ͽ�Ʈ�� v-1�� ���� �������� �˰����� ����Ѵ�.
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

	while(T--) {			// �� �׽�Ʈ ���̽�

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

	}	////////////////////////////////////// �� �׽�Ʈ ���̽�
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