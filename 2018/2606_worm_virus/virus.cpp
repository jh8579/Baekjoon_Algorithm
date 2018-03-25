// ���̷���
// �׷��� ������ vector �迭�� �����Ͽ���
// Bool �迭�� ���� ��ǻ�� ���� ���� Ȯ��
// Bool �迭�� ��� ���� ��ǻ�� 1�� �� �������� ���

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool check_virus[110] = {0};
vector<int> com[110];
queue<int> q;
int comNum, nodeNum;
int Max = 0;

void BTS();
int main() {
	cin >> comNum >> nodeNum;

	for (int i = 0; i < nodeNum; i++) {
		int c, n_c;
		cin >> c >> n_c;
		com[c].push_back(n_c);
		com[n_c].push_back(c);
	}
	check_virus[1] = 1;
	q.push(1);

	BTS();

	for (int i = 1; i <= comNum; i++) {
		Max += check_virus[i];
	}
	cout << Max -1;
	cin >> Max;
}

void BTS() {
	while (!q.empty()) {
		int temp = q.front();

		for (int i = 0; i < com[temp].size(); i++) {
			if (!check_virus[com[temp][i]]) {
				check_virus[com[temp][i]] = 1;
				q.push(com[temp][i]);
			}
		}
		q.pop();
	}
}