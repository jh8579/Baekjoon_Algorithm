// ��Ϲ���

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct location {
	int x, y;
};

queue<location> q;

int r_wheel[10][100] = { 0 };
int wheel[10][10];
location list[110];

int check[4] = { 1,1,1,1 };
int K;

void rotate(int n);
void BFS(int n);

int main() {
	char temp[5][10];

	for (int i = 0; i < 4; i++) {
		cin >> temp[i];
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			wheel[i][j] = (temp[i][j] - '0');		// ���ӵ� ���� �Է�
		}
	}

	cin >> K;

	for (int i = 0; i < K; i++) {
		int wheel_num, direction;
		cin >> wheel_num >> direction;
		list[i] = { wheel_num, direction };
	}

	for (int i = 0; i < K; i++) {

		q.push({ list[i].x, list[i].y });			// �ʱⰪ ť�� ����
		BFS(i);										// �ʱⰪ���� ���� ���ư��� ��� ���
		rotate(i);									// 1ȸ���� �Ѳ����� ��ϸ� ������

		for (int j = 0; j < 4; j++) {				// flag �ʱ�ȭ
			check[j] = 1;
		}
	}

	cout << 1 * wheel[0][0] + 2 * wheel[1][0] + 4 * wheel[2][0] + 8 * wheel[3][0] << endl;
	cin >> K;
}

void rotate(int n) {								// ���⿡ ���� �迭 ����Ʈ
	for (int a = 0; a < 4; a++) {
		int direction = r_wheel[a][n];
		
		if (direction == 1) {
			int temp_num = wheel[a][0];
			wheel[a][0] = wheel[a][7];

			for (int i = 0; i < 7; i++) {
				int temp = wheel[a][i + 1];
				wheel[a][i + 1] = temp_num;
				temp_num = temp;
			}
		}
		else if (direction == -1){
			int temp_num = wheel[a][7];
			wheel[a][7] = wheel[a][0];

			for (int i = 7; i > 0; i--) {
				int temp = wheel[a][i - 1];
				wheel[a][i - 1] = temp_num;
				temp_num = temp;
			}
		}
	}
}

void BFS(int n) {
	while (!q.empty()) {
		location temp = q.front();

		int wheel_num = temp.x;
		int direction = temp.y;

		r_wheel[wheel_num - 1][n] = direction;					// �ʱⰪ ȸ�� �迭�� �߰�

		if (wheel_num == 1) {									// 1�� ��ϴ� 2�� ��� ����
			check[0] = 0;
			if (wheel[0][2] + wheel[1][6] == 1 && check[1]) {
				q.push({ 2, -direction });
			}
		}
		else if (wheel_num == 2) {								// 2�� ��ϴ� 1,3�� ��� ����
			check[1] = 0;
			if (wheel[0][2] + wheel[1][6] == 1 && check[0]) {
				q.push({ 1, -direction });
			}
			if (wheel[1][2] + wheel[2][6] == 1 && check[2]) {
				q.push({ 3 , -direction });
			}
		}
		else if (wheel_num == 3) {								// 3�� ��ϴ� 2,4�� ��� ����
			check[2] = 0;
			if (wheel[1][2] + wheel[2][6] == 1 && check[1]) {
				q.push({ 2, -direction });
			}
			if (wheel[2][2] + wheel[3][6] == 1 && check[3]) {
				q.push({ 4 , -direction });
			}
		}
		else {													// 4�� ��ϴ� 3�� ��� ����
			check[3] = 0;
			if (wheel[2][2] + wheel[3][6] == 1 && check[2]) {
				q.push({ 3, -direction });
			}
		}
		q.pop();												
	}
}

