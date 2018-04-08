// ȿ������ ��ŷ
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
	cin >> V >> E;						// �ʱ�ȭ

	for (int i = 0; i < E; i++) {
		int u, v;

		cin >> u >> v;
		board[v].push_back(u);
	}

	for (int i = 1; i <= V; i++) {

		for (int j = 1; j <= V; j++) {	// ��� ������ �ʱ�ȭ
			visit[j] = -1;
		}
		visit[i] = 1;					// ù ��� 0���� �ʱ�ȭ
		q.push(i);						// ù ��� Ǫ��
		record[i] = BFS();				// �ִ밪 ����

		Max = max(record[i], Max);		// ��ü �ִ밪 ����
	}

	for (int j = 1; j <= V; j++) {		// �ִ밪�� ������ ��� �������� ���
		if (record[j] == Max) {
			cout << j << " ";
		}
	}
	cin >> V;
}

int BFS() {
	int cnt = 0;						// �ִ밪 ī��Ʈ

	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		for (int i = 0; i < board[temp].size(); i++) {
			if (visit[board[temp][i]] < 0) {						// ��ġ�� ���� ���
				visit[board[temp][i]] = 1;
				q.push(board[temp][i]);
				cnt++;												// ��ĥ�� ���� ī��Ʈ ����
			}
		}
	}	
	return cnt;														// �ִ밪 ����
}