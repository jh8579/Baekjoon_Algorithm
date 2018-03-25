// 단지번호붙이기
// issue1 : 큐에 중복되어 들어가는 경우가 발생한다.
// 해결방법 : 큐에 넣을 때도 큐에 들어간 좌표인지 구분해주기 위해 0으로 만들어주어야 한다. 

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct location {
	int x, y;
};

int dx[4] = { -1, +1, 0, 0 };
int dy[4] = { 0, 0, -1, +1 };

int N;
int field[27][27];
int v_count = 0;

queue<location> q;
vector<int> house_num;

void BFS();
int main() {
	cin >> N;

	char temp[30][30];

	for (int i = 0; i < N; i++) {
		cin >> temp[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = N-1; j >= 0; j--) {
			field[i][j] = temp[i][j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (field[i][j] != 0) {
				q.push({ i,j });
				BFS();
			}
		}
	}

	sort(house_num.begin(), house_num.end());		// 단지내 집의 수 오름차순 출력 위함

	cout << v_count << endl;
	for (int i = 0; i < house_num.size(); i++) {
		cout << house_num[i] << endl;
	}

	cin >> v_count;

}

void BFS() {
	int count = 0;
	while (!q.empty()) {
		location temp = q.front();

		field[temp.x][temp.y] = 0;
		count++;

		for (int a = 0; a < 4; a++) {
			int nx = temp.x + dx[a];
			int ny = temp.y + dy[a];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (field[nx][ny] != 0) {
					field[nx][ny] = 0;			// 큐에 넣을 때도 0 초기화
					q.push({ nx,ny });
				}
			}
		}
		q.pop();
	}
	house_num.push_back(count);
	v_count++;
}