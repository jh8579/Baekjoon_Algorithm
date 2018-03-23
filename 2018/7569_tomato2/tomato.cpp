// �丶��2
// issue : 3���� �迭�� �ε��� ����
// �ذ��� : ���� �ε����� �Է� �ݺ��� ���� �ٱ��ʿ� ��ġ��Ŵ

#include <iostream>
#include <queue>
using namespace std;

int M, N, H;
int box[110][110][110];
int dayCount = 0;
int d_x[6] = { -1, 1, 0, 0, 0, 0 };
int d_y[6] = { 0, 0, -1, 1, 0, 0 };
int d_z[6] = { 0, 0, 0, 0, -1, 1 };

struct location {
	int x, y, z;
};
queue<location> q;

void BTS() {
	while (!q.empty()) {
		location temp = q.front();

		for (int i = 0; i < 6; i++) {
			int n_x = temp.x + d_x[i];
			int n_y = temp.y + d_y[i];
			int n_z = temp.z + d_z[i];

			if (n_x >= 0 && n_x <= M - 1 && n_y >= 0 && n_y <= N - 1 && n_z >=0 && n_z <= H-1) {
				if (box[n_x][n_y][n_z] == 0) {
					box[n_x][n_y][n_z] = box[temp.x][temp.y][temp.z] + 1;
					location temp_r = { n_x, n_y, n_z };
					q.push(temp_r);
				}
			}
		}
		q.pop();
	}
}

int main() {
	cin >> N >> M >> H;
	for (int k = H - 1; k >= 0; k--) {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cin >> box[i][j][k];
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < H; k++) {
				if (box[i][j][k] == 1) {
					location rotten = { i,j,k };
					q.push(rotten);
				}
			}
		}
	}

	BTS();

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < H; k++) {
				if (box[i][j][k] == 0) {
					cout << -1;
					cin >> M;
					return 0;
				}
				if (box[i][j][k] >= 1 && box[i][j][k] > dayCount) {
					dayCount = box[i][j][k];
				}
			}
		}
	}
	cout << dayCount - 1 << endl;
	cin >> M;
	return 0;
}