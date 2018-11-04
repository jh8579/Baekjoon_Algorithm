#include <iostream>
using namespace std;

int value[20];
int coin_check[20] = { 0 };

int main() {
	int N, K;
	int coin_count = 0;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {			// 시간 복잡도 O(N)
		cin >> value[i];
	}

	while (K>0) {

		for (int i = N-1; i >=0; i--) {		// 시간 복잡도 O(N-1 * 동전 갯수)
			if (value[i] <= K) {
				K -= value[i];
				coin_count++;
				break;
			}
		}

	}
	cout << coin_count;
}

int main() {
	int N, K;
	int coin_count = 0;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {			// 시간 복잡도 O(N)
		cin >> value[i];
	}

	while (K > 0) {

		for (int i = N - 1; i >= 0; i--) {		// 시간 복잡도 O(N-1 * 동전 갯수)
			if (value[i] <= K) {
				int num = K / value[i];

				K -= value[i] * num;
				coin_count += num;
				break;
			}
		}

	}
	cout << coin_count;
}