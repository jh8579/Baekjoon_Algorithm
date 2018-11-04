#include <iostream>
#include <algorithm>
using namespace std;

struct meet{
	int x, y, z;

	bool operator<(const meet &cmp) const {
		if (y == cmp.y) {
			return x < cmp.x;
		}
		else {
			return y < cmp.y;
		}
	}
};

int N;
meet time[100010];

int main() {

	int pre = 0;
	int cnt = 0;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		time[i] = { x, y};
	}
	
	sort(time, time+N);

	for (int i = 0; i < N; i++) {
		if (time[i].x >= pre) {
			cnt++;
			pre = time[i].y;
		}
	}
	cout << cnt;
}