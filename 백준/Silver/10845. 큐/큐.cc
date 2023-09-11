#include<iostream>

using namespace std;

int main() {
	int n, tmp, queue[10001] = { 0, }, front = 0, back = 0;
	string cmd;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> tmp;
			queue[back] = tmp;
			back++;
		}
		else if (cmd == "pop") {
			if (front >= back) cout << -1 << '\n';
			else {
				cout << queue[front] << '\n';
				front++;
			}
		}
		else if (cmd == "size") {
			cout << back - front << '\n';
		}
		else if (cmd == "empty") {
			if (front >= back) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (cmd == "front") {
			if (front >= back) cout << -1 << '\n';
			else cout << queue[front] << '\n';
		}
		else if (cmd == "back") {
			if (front >= back) cout << -1 << '\n';
			else cout << queue[back - 1] << '\n';
		}
		else return 0;
	}

	return 0;
}