#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[500000];
int temp[500000];
long long cnt = 0;

void bubblesort(int start, int end);
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	bubblesort(0, n-1);
	cout << cnt;
}
void merge(int start1, int end1, int end2) {
	int i = start1;
	int j = end1+1;
	int k = start1;

	while (i <= end1 && j <= end2) {
		if (arr[i] > arr[j]) {
			cnt += end1 - i + 1;
			temp[k] = arr[j];
			j++;
		}
		else {
			temp[k] = arr[i];
			i++;
		}
		k++;
	}
	if (i > end1) {
		for (int t = j; t <= end2; t++) {
			temp[k++] = arr[t];
		}
	}
	else {
		for (int t = i; t <= end1; t++) {
			temp[k++] = arr[t];
		}
	}


	for (int y = start1; y <= end2; y++) {
		arr[y] = temp[y];
	}
}
void bubblesort(int start, int end) {
	//cout << "합병 정렬(" << start << ", " << end << ") 시작\n";
	int mid = (end + start) / 2;

	if (end >= mid + 1) {
		bubblesort(start, mid);
		bubblesort(mid + 1, end);
		merge(start, mid, end);
	}
	/*cout << "cnt : " << cnt << endl;

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "합병 정렬(" << start << ", " << end << ") 끝\n";*/
}