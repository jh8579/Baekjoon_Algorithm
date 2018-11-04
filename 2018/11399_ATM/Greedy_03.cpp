#include <iostream>
#include <algorithm>
using namespace std;

int num[1010];
int N;

int main() {
	cin >> N;
	int sum = 0;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, num + N);
	
	for (int i = 0; i < N; i++) {
		sum += num[i] * (N-i);
	}

	cout << sum;
}