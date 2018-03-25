// �̷� Ž��
// issue1: ���ٿ� ���ڸ� �Ѳ����� �����鼭 100�ڸ� ���ڸ� �ް� �� ��� int�� ���� ó���� �� ����
// �ذ��� : char �迭�� ���� �Է��� �ް� �ε����� ������ ���ڸ��� int �迭�� ��ȯ�Ͽ� �־��ش�.

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
			board[i][j] = temp[i][j] - '0';	// ������ ���ڸ� ���������� ��ȯ
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