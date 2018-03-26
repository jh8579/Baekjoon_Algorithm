// 연구소
// 바이러스 퍼트리고 0 최댓값을 구하는 함수 생성
// 0중에 3개를 선택해서 벽을 세우는 함수 생성

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct location {
	int x, y;
};

queue<location> q;

vector<location> virus;
vector<location> zero;

int N, M;
int lab[10][10];
int c[10][10];
int Max = 0;

int dx[4] = { -1, +1, 0, 0 };
int dy[4] = { 0, 0, -1, +1 };

void spread();
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 0)
				zero.push_back({ i,j });
			else if (lab[i][j] == 2)
				virus.push_back({i, j});
		}
	}

	for (int i = 0; i < zero.size(); i++) {				// 0 개수를 n이라 할 때
		for (int j = i + 1; j < zero.size(); j++) {		// (0~n-1)중에 3개 선택
			for (int k = j + 1; k < zero.size(); k++) { // 3개를 벽으로 치환

				for (int a = 0; a < N; a++) {			// 초기 연구소 복사
					for (int b = 0; b < M; b++) {
						c[a][b] = lab[a][b];
					}
				}

				location temp1 = zero[i];
				c[temp1.x][temp1.y] = 1;
				location temp2 = zero[j];
				c[temp2.x][temp2.y] = 1;
				location temp3 = zero[k];
				c[temp3.x][temp3.y] = 1;

				spread();								// 바이러스 살포 후 Max 체크

			}
		}
	}

	cout << Max;
	cin >> Max;
}

void spread() {
	int count = 0;

	for (int i = 0; i < virus.size(); i++) {
		q.push(virus[i]);
	}

	while (!q.empty()) {
		location temp = q.front();

		for (int i = 0; i < 4; i++) {
			int nx = temp.x + dx[i];
			int ny = temp.y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (c[nx][ny] == 0) {
					c[nx][ny] = 2;
					q.push({ nx,ny });
				}
			}
		}
		q.pop();
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (c[i][j] == 0) {
				count++;
			}
		}
	}

	if (count == 9) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << c[i][j] << " ";
			}
			cout << endl;
		}
	}

	if (Max < count) {
		Max = count;
	}
}