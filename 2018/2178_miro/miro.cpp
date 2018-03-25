// 미로 탐색
// issue1: 한줄에 숫자를 한꺼번에 받으면서 100자리 숫자를 받게 될 경우 int로 값을 처리할 수 없다
// 해결방법 : char 배열로 한줄 입력을 받고 인덱스로 접근해 한자리씩 int 배열에 변환하여 넣어준다.

#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct location {
	int x, y;
};

int N, M;
int board[110][110];

int dx[4] = { -1, 1, 0, 0};
int dy[4] = { 0, 0, 1, -1};

int Max = 0;

queue<location> q;

void BTS();

int main() {
	cin >> N >> M;

	char temp[110][110];

	for (int i = 0; i < N; i++) {
		cin >> temp[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = M - 1; j >= 0; j--) {
			board[i][j] = temp[i][j] - '0';	// 문자인 숫자를 정수형으로 변환
		}
	}

	q.push({ 0,0 });
	BTS();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] > Max) {
				Max = board[i][j];
			}
		}
	}

	cout << Max;
	cin >> Max;
}

void BTS() {
	while (!q.empty()) {
		location temp = q.front();

		for (int i = 0; i < 4; i++) {
			int nx = temp.x + dx[i];
			int ny = temp.y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (board[nx][ny] == 1) {
					board[nx][ny] = board[temp.x][temp.y] + 1;
					q.push({ nx,ny });
				}
			}
		}
		q.pop();
	}
}