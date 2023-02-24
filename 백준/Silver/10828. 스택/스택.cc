#include <iostream>
#include <string>
using namespace std;

int st[10001];
int s = 0;

void push(int x) {
	st[s] = x;
	s++;
	return;
}

int pop() {
	if (s == 0) return -1;
	else {
		s--;
		return st[s];
	}
}
int size() {
	return s;
}

int empty() {
	if (s == 0) return 1;
	else return 0;
}

int top() {
	if (s == 0) return -1;
	else return st[s - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string inp;
	int tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> inp;
		if (inp == "push") {
			cin >> tmp;
			push(tmp);
		}
		else if (inp == "pop") {
			cout << pop() << '\n';
		}
		else if (inp == "size") {
			cout << size() << '\n';
		}
		else if (inp == "empty") {
			cout << empty() << '\n';
		}
		else if (inp == "top") {
			cout << top() << '\n';
		}
	}

	return 0;
}