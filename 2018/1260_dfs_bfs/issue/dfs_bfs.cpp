// BTS, DTS 문제
// issue : 메모리 초과
// 해결방법 : 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> vertex[1000];
int numberVertex, numberEdge, startVertex;
int top, bottom;
int checkD[1000], checkB[1000];

void BTS(int start);
void DTS(int start);

int main() {
	cin >> numberVertex >> numberEdge >> startVertex;

	for (int i = 0; i < numberEdge; i++) {
		cin >> top >> bottom;
		vertex[top].push_back(bottom);
	}

	for (int i = 0; i < numberVertex; i++) {
		sort(vertex[i].begin(), vertex[i].end());
	}

	DTS(startVertex);
	cout << "\n";
	BTS(startVertex);

	return 0;
}

void BTS(int start) {
	if (checkB[start] != 1) {
		checkB[start] = 1;
		cout << start << " ";
	}

	for (int i = 0; i < vertex[start].size(); i++) {
		if (checkB[vertex[start][i]] != 1) {
			checkB[vertex[start][i]] = 1;
			cout << vertex[start][i] << " ";
		}
	}
	for (int i = 0; i < vertex[start].size(); i++) {
		BTS(vertex[start][i]);
	}

}
void DTS(int start) {
	if (checkD[start] != 1) {
		checkD[start] = 1;
		cout << start << " ";

		for (int i = 0; i < vertex[start].size(); i++) {
			DTS(vertex[start][i]);
		}
	}
}
