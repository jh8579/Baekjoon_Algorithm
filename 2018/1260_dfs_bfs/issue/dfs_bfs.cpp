// BTS, DTS ����
//
// issue : �޸� �ʰ�
// ���� : BFS �Լ� ����
// �ذ��� : BFS �Լ��� ť�� ����Ѵ�.
//
// issue :  �迭 �ʰ�
// ���� : �迭 �ε��� �� �°� ����
// �ذ��� : �迭�� ���� ���Ǻ��� �����Ӱ� ����

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> vertex[1001];
queue<int> vertexQueue;
int numberVertex, numberEdge, startVertex;
int checkD[1001], checkB[1001];

void BFS(int start);
void DFS(int start);

int main() {
	cin >> numberVertex >> numberEdge >> startVertex;

	for (int i = 0; i < numberEdge; i++) {
		int top, bottom;
		cin >> top >> bottom;
		vertex[top].push_back(bottom);
		vertex[bottom].push_back(top);	// ���ʿ� ��� �߰�
	}

	for (int i = 0; i < numberVertex; i++) {
		sort(vertex[i].begin(), vertex[i].end());
	}

	DFS(startVertex);
	cout << "\n";
	BFS(startVertex);

	return 0;
}

void BFS(int start) {
	vertexQueue.push(start);
	checkB[start] = 1;
	int i;
	while (!vertexQueue.empty()) {
		int frontVertex = vertexQueue.front();
		for (i = 0; i < vertex[frontVertex].size(); i++) {
			if (checkB[vertex[frontVertex][i]] != 1) {
				checkB[vertex[frontVertex][i]] = 1;
				vertexQueue.push(vertex[frontVertex][i]);
			}
		}
		cout << vertexQueue.front() << " ";
		vertexQueue.pop();
	}
}
void DFS(int start) {
	int i;
	if (checkD[start] != 1) {
		checkD[start] = 1;
		cout << start << " ";

		for (i = 0; i < vertex[start].size(); i++) {
			DFS(vertex[start][i]);
		}
	}
}
