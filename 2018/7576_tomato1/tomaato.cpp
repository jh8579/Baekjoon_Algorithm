// 토마토
// issue1 : 이중배열 정수형 큐로 다루기 힘듬
// 해결방법 : 구조체 사용

// issue2 : max 체크 
// 해결방법 : 썩을때마다 1씩 증가

// issue3 : 배열 상하좌우 체크
// 해결방법 : 상하좌우 배열을 미리 정의하고 그때마다 더해준다

// issue4 : 배열 가장자리 예외처리
// 해결방법 : 인덱스 1과 M-1을 체크

// issue5 : 배열 row col 방향 헷갈림
// 해결방법 : row col 반대로 입력

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