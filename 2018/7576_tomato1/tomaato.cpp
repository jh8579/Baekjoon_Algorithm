// �丶��
// issue1 : ���߹迭 ������ ť�� �ٷ�� ����
// �ذ��� : ����ü ���

// issue2 : max üũ 
// �ذ��� : ���������� 1�� ����

// issue3 : �迭 �����¿� üũ
// �ذ��� : �����¿� �迭�� �̸� �����ϰ� �׶����� �����ش�

// issue4 : �迭 �����ڸ� ����ó��
// �ذ��� : �ε��� 1�� M-1�� üũ

// issue5 : �迭 row col ���� �򰥸�
// �ذ��� : row col �ݴ�� �Է�

#include <iostream>
#include <queue>
using namespace std;

int M, N;
int box[1100][1100];
int dayCount = 0;
int d_x[4] = {-1, 1, 0, 0};
int d_y[4] = { 0, 0, -1, 1 };

struct location {
	int x, y;
};
queue<location> q;

void BTS() {
	while (!q.empty()) {
		location temp = q.front();

		for (int i = 0; i < 4; i++) {
			int n_x = temp.x + d_x[i];
			int n_y = temp.y + d_y[i];

			if (n_x >= 0 && n_x <= M - 1 && n_y >= 0 && n_y <= N - 1) {
				if (box[n_x][n_y] == 0) {
					box[n_x][n_y] = box[temp.x][temp.y] + 1;
					location temp_r = { n_x, n_y };
					q.push(temp_r);
				}
			}
		}
		q.pop();
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> box[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (box[i][j] == 1) {
				struct location rotten;
				rotten.x = i;
				rotten.y = j;
				q.push(rotten);
			}
		}
	}

	BTS();

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (box[i][j] == 0) {
				cout << -1;
				return 0;
			}
			if (box[i][j]>= 1 && box[i][j] > dayCount) {
				dayCount = box[i][j];
			}
		}
	}
	cout << dayCount - 1<<endl;

	return 0;
}