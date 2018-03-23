// 토마토
// issue1 : 이중배열 정수형 큐로 다루기 힘듬
// issue2 : max 체크 
// issue3 : 배열 상하좌우 체크
// issue4 : 배열 가장자리 예외처리

#include <iostream>
#include <queue>
using namespace std;

int M, N;
int box[1010][10010];
int dayCount = 0;

struct location {
	int x, y;
};
queue<location> q[1000];

int main() {
	cin >> M >> N;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> box[i][j];
		}
	}
	for (int i = 0; i <= M + 1; i++) {
		box[i][0] = -1;
		box[i][N + 1];
	}
	for (int i = 0; i <= N + 1; i++) {
		box[0][i] = -1;
		box[M][i];
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (box[i][j] == 1) {
				struct location rotten;
				rotten.x = i;
				rotten.y = j;
				q[dayCount].push(rotten);
			}
		}
	}
	while (!q[dayCount].empty()) {
		while (!q[dayCount].empty()) {
			struct location front = q[dayCount].front();
			int x = front.x;
			int y = front.y;

			if (box[x - 1][y] == 0) {
				box[x - 1][y] = 1;
				struct location rotten;
				rotten.x = x - 1;
				rotten.y = y;
				q[dayCount + 1].push(rotten);
			}
			if (box[x + 1][y] == 0) {
				box[x + 1][y] = 1;
				struct location rotten;
				rotten.x = x + 1;
				rotten.y = y;
				q[dayCount + 1].push(rotten);
			}
			if (box[x][y - 1] == 0) {
				box[x][y - 1] = 1;
				struct location rotten;
				rotten.x = x;
				rotten.y = y - 1;
				q[dayCount + 1].push(rotten);
			}
			if (box[x][y + 1] == 0) {
				box[x][y + 1] = 1;
				struct location rotten;
				rotten.x = x;
				rotten.y = y + 1;
				q[dayCount + 1].push(rotten);
			}
		}
		dayCount++;
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (box[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << dayCount;
	return 0;
}