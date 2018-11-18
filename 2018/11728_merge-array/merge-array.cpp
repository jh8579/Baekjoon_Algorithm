
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int nArray[1000010];
int mArray[1000010];

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {			// O(N)
		cin >> nArray[i];
	}

	for (int i = 0; i < M; i++) {			// O(N)
		cin >> mArray[i];
	}

	sort(nArray, nArray + N);
	sort(mArray, mArray + M);

	int i=0, j = 0;

	while (i <= N - 1 && j <= M - 1) {
		if (nArray[i] < mArray[j]) {
			cout << nArray[i++] << " ";
		}
		else {
			cout << mArray[j++] << " ";
		}
	}

	if (i == N) {
		for (int k = j; k < M; k++) {
			cout << mArray[k] << " ";
		}
	}
	else {
		for (int k = i; k < N; k++) {
			cout << nArray[k] << " ";
		}
	}
}
