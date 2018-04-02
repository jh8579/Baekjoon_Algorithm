// ���� ����Ŭ
//
// issue 1   : ť �ȿ� ���� ��� �ʱ�ȭ ����
// �ذ� ��� : �ݺ��� �ȿ� ť�� ����
//
// issue 2   : �ߺ� if ������ �ƹ��͵� ������ �ʴ� ����
// �ذ� ��� : �ʿ� ���� if���� �ϳ��� ����

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, N;

int main() {
	cin >> T;

	for (int k = 0; k < T; k++) {
		int cnt = 0;					// �� �׽�Ʈ ���̽� ���� ī���� �ʱ�ȭ
		int visited[1010] = { 0 };		// ���� ����Ŭ�� ���ԵǾ����� Check

		vector<int> v[1010];			// ���� ����Ʈ �̿�
		
		cin >> N;

		for (int i = 1; i <= N; i++) {
			int temp;
			cin >> temp;
			v[i].push_back(temp);
		}

		for (int i = 1; i <= N; i++) {
			queue<int> q;				// ����Ŭ Ȯ�� �� ���� ť�� �ʱ�ȭ �Ͽ� ���� ��Ҹ� �����

			if (!visited[i]) {			// ���� ����Ŭ���� ����� ��Ҵ� ����
				q.push(i);
			}

			while (!q.empty()) {
				int temp = q.front();
				if (temp == i && visited[i]) {	// �ڱ� �ڽ����� ���ƿ� ��� ī��Ʈ �߰�
					cnt++;
					break;
				}
				visited[temp] = 1;				// ����� ��� üũ

				for (int j = 0; j < v[temp].size(); j++) {	// ����Ǿ��ִ� ��� ť�� �߰�
						visited[v[temp][j]] = 1;
						q.push(v[temp][j]);
				}
				q.pop();						// ����� ��� ť���� ����
			}
		}

		cout << cnt << endl;
	}
}