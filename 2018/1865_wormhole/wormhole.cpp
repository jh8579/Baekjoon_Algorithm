// ��Ȧ
//
//issue 1 : ���� ����ġ�� �����ϱ� ������ ť�� �ڵ��ϸ� �������� ������ �� ���ɼ��� �����Ѵ�.
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

	for (int k = 0; k < T; k++) {			// �� �׽�Ʈ ���̽�

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

	}	////////////////////////////////////// �� �׽�Ʈ ���̽�

	cin >> N;
}

int BFS() {
	for (int k = 1; k <= N; k++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {			// visit -1�� ��� �ʱ�ȭ

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
				if (visit[road[temp][i].x] < 0) {						// ��ġ�� ���� ���
					visit[road[temp][i].x] = visit[temp] + road[temp][i].y;
					q.push(road[temp][i].x);
				}
				else {													// ��ģ ���
					if (visit[road[temp][i].x] > visit[temp] + road[temp][i].y) {	// �� ���� ���� ��� ����
						visit[road[temp][i].x] = visit[temp] + road[temp][i].y;
						q.push(road[temp][i].x);
					}
				}
			}
		}
	}
	
	return 0;
}