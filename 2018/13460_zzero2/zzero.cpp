// °��Ż��2
//
#include <iostream>
#include <queue>
using namespace std;

struct location {
	int x, y;
};

struct ball {
	struct location r;
	struct location b;
};

struct Case {
	struct ball x;
	int C;
};

int N, M;
int Min = 11;

char board[13][13];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1 , 0, 0 };

queue<Case> q;

location blueF, redF;


bool red_move(int direct, location &red, location &blue);
bool blue_move(int direct, location &red, location &blue);

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {							// ������ ���� ���� �ʱ�ȭ
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'B') {
				blueF.x = i;
				blueF.y = j;
				board[i][j] = '.';

			}
			if (board[i][j] == 'R') {
				redF.x = i;
				redF.y = j;
				board[i][j] = '.';
			}
		}
	}

	q.push({ {redF,blueF }, 0 });

	while (!q.empty()) {

		struct Case temp_case = q.front();
		ball temp = temp_case.x;
		location red = temp.r;
		location blue = temp.b;
		int cnt = temp_case.C;

		if (cnt > 11) {
			q.pop();
			continue;
		}
		else {
			cnt++;
			q.pop();
		}

		for (int i = 0; i < 4; i++) {		// ���� ����
			int nx = red.x + dx[i];
			int ny = red.y + dy[i];

			int bx = blue.x + dx[i];
			int by = blue.y + dy[i];

			int flag = false;
			int win, lose = false;

			if (i == 0) {				// �켱 ���� ����
				if (red.y > blue.y)
					flag = true;
			}
			if (i == 1) {
				if (red.y < blue.y)
					flag = true;
			}
			if (i == 2) {
				if (red.x > blue.x)
					flag = true;
			}
			if (i == 3) {
				if (red.x < blue.x)
					flag = true;
			}

			location red_t = red;
			location blue_t = blue;

			if (flag) {					// �켱 ���� ��� �ű��
				win = red_move(i, red_t, blue_t);
				lose = blue_move(i, red_t, blue_t);
			}
			else {
				lose = blue_move(i, red_t, blue_t);
				win = red_move(i, red_t, blue_t);
			}

			if (win && !lose) {			// ����
				if (cnt < Min) {
					Min = cnt;
				}
			}
			else if (lose) {
				continue;
			}
			else {
				if (cnt < 10) {
					q.push({ { red_t, blue_t }, cnt });
				}	
			}
		}
	}

	if (Min>=11) {						// �ּڰ� ����
		cout << Min;
		return 0;
		
	}
	cout << -1;							// �ּҰ� ���� ��
}

bool red_move(int direct, location &red, location &blue) {		// ������ �� �����̱�
	char temp_board[12][12];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp_board[i][j] = board[i][j];
		}
	}
	temp_board[red.x][red.y] = 'R';
	temp_board[blue.x][blue.y] = 'B';							// �����ǿ� �� �ʱ�ȭ

	int nx = red.x;
	int ny = red.y;

	while (1) {
		nx += dx[direct];
		ny += dy[direct];
			
		if (temp_board[nx][ny] == '.') {						// ��� �����̱�
			continue;
		}
		else if (temp_board[nx][ny] == 'O') {					// ���ۿ� ���� 1 ����
			red.x = 0;
			red.y = 0;
			return 1;	
		}
		else {													// ������ �� ������ �� ������ ����
			nx -= dx[direct];
			ny -= dy[direct];
			break;
		}
	}

	red.x = nx;
	red.y = ny;

	return 0;
}
bool blue_move(int direct, location &red, location &blue) {		// �Ķ��� �� �����̱�(������ �����̱�� ����)

	char temp_board[12][12];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp_board[i][j] = board[i][j];
		}
	}
	temp_board[red.x][red.y] = 'R';
	temp_board[blue.x][blue.y] = 'B';

	int nx = blue.x;
	int ny = blue.y;

	while (1) {
		nx += dx[direct];
		ny += dy[direct];

		if (temp_board[nx][ny] == '.') {
			continue;
		}
		else if (temp_board[nx][ny] == 'O') {
			blue.x = 0;
			blue.y = 0;
			return 1;
		}
		else {
			nx -= dx[direct];
			ny -= dy[direct];
			break;
		}
	}

	blue.x = nx;
	blue.y = ny;

	return 0;
}