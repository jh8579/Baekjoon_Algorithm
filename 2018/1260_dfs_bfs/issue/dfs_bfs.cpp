// BTS, DTS 문제
//
// issue : 메모리 초과
// 원인 : BFS 함수 오류
// 해결방법 : BFS 함수에 큐를 사용한다.
//
// issue :  배열 초과
// 원인 : 배열 인덱스 딱 맞게 설정
// 해결방법 : 배열을 원래 조건보다 여유롭게 설정

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
		vertex[bottom].push_back(top);	// 양쪽에 모두 추가
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
