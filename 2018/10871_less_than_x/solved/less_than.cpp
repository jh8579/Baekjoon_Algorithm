#include <iostream>
using namespace std;

int main() {
	int N, X;
	int number[10000];		// �ʱ� �迭
	int less_than[10000];	// x���� ���� ���� �迭
	int count = 0;			// ���� ��� ī��Ʈ

	cin >> N >> X;

	for (int i = 0; i < N; i++) {
		cin >> number[i];
	}
	for (int i = 0; i < N; i++) {
		if (number[i] < X) {
			less_than[count++] = number[i];
		}
	}
	for (int i = 0; i < count; i++) {
		cout << less_than[i] << " ";
	}
}