#include <iostream>
using namespace std;

int main() {
	int N, X;
	int number[10000];		// 초기 배열
	int less_than[10000];	// x보다 작은 수의 배열
	int count = 0;			// 작은 경우 카운트

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