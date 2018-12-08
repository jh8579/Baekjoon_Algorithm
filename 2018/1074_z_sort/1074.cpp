#include <iostream>
using namespace std;

int N, r, c;
int cnt = 0;

void devide(int num, int row, int col);

int main() {
	cin >> N >> r >> c;

	devide(N, r, c);

	cout << cnt;
}

void devide(int num, int row, int col) {
	int num1 = 1;

	for (int i = 0; i < num; i++) {
		num1 *= 2;
	}

	int start2 = num1 / 2;

	if (num == 1) {
		if (row % 2 == 0) {
			if (col % 2 == 0) {
				cnt += 0;
			}
			else {
				cnt += 1;
			}
		}
		else {
			if (col % 2 == 0) {
				cnt += 2;
			}
			else {
				cnt += 3;
			}

		}
		return;
	}


	if (row < start2 && col < start2) {
		cnt += 0;
		devide(num-1, row, col);
	}
	else if (row >= start2 && col <start2) {
		cnt += start2 * start2 * 2;
		devide(num-1, row-start2, col);
	}
	else if (row <start2 && col >= start2) {
		cnt += start2 * start2 * 1;
		devide(num-1, row, col-start2);
	}
	else {
		cnt += start2 * start2 * 3;
		devide(num-1, row-start2, col-start2);
	}

}
	