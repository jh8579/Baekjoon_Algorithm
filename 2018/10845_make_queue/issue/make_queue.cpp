// 큐
// issue : 명령어들을 enum으로 처리할 수 있을까?

#include <iostream>
#include <string>
using namespace std;

int n;
string ins[10000];
int input_number[10000];

int my_queue[10000];
int count_queue = 0;

void print_push(int num);
void print_pop();
void print_size();
void print_empty();
void print_front();
void print_back();

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ins[i];
		if (ins[i].compare("push") == 0) {
			cin >> input_number[i];
		}
	}

	for (int i = 0; i < n; i++) {
		if (ins[i].compare("push") == 0) {
			print_push(input_number[i]);
		}
		else if (ins[i].compare("pop") == 0) {
			print_pop();
		}
		else if (ins[i].compare("size") == 0) {
			print_size();
		}
		else if (ins[i].compare("empty") == 0) {
			print_empty();
		}
		else if (ins[i].compare("front") == 0) {
			print_front();
		}
		else if (ins[i].compare("back") == 0) {
			print_back();
		}
		else {

		}
	}
}

void print_push(int num) {
	my_queue[count_queue++] = num;
}
void print_pop() {
	if (count_queue != 0) {
		cout << my_queue[0] << "\n";
		for (int i = 0; i < count_queue; i++) {
			if (i != count_queue - 1)
				my_queue[i] = my_queue[i + 1];
		}
		count_queue--;
	}
	else {
		cout << -1 << "\n";
	}
	
}
void print_size() {
	cout << count_queue << "\n";
}
void print_empty() {
	if (count_queue == 0) {
		cout << 1 << "\n";
	}
	else {
		cout << 0 << "\n";
	}
}
void print_front() {
	if (count_queue != 0) {
		cout << my_queue[0] << "\n";
	}
	else {
		cout << -1 << "\n";
	}
}
void print_back() {
	if (count_queue != 0) {
		cout << my_queue[count_queue-1] << "\n";
	}
	else {
		cout << -1 << "\n";
	}
}