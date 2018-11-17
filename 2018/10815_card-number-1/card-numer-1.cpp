#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;

int nArray[500020];
int mArray[500020];
int mCount[500020] = {0};

void findBinarySearch(int i);

int main() {
	cin >> N;
	//scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin >> nArray[i];
		//scanf("%d", &nArray[i]);
	}

	cin >> M;
	//scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		cin >> mArray[i];
		//scanf("%d", &mArray[i]);
	}

	sort(nArray, nArray + N);

	for (int i = 0; i < M; i++) {
		findBinarySearch(i);
	}

	for (int i = 0; i < M; i++) {
		cout << mCount[i] << " ";
		//printf("%d ",mCount[i]);
	}

}

void findBinarySearch(int i) {
	int start = 0;
	int end = N-1;

	while (1) {
		
		if ( (end-start) < 0) {
			mCount[i] = 0;
			break;
		}

		int temp = (end + start) / 2;

		if (nArray[temp] == mArray[i]) {
			mCount[i] = 1;
			break;
		}
		else if (nArray[temp] > mArray[i]) {
			end = temp - 1;
			
		}
		else {
			start = temp + 1;
		}
	}
}