#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>

using namespace std;

bool isMulDiv(char x) {
	if (x == '*' || x == '/') return true;
	return false;
}

bool isPlMin(char x) {
	if (x == '+' || x == '-') return true;
	return false;
}

int main() {
	string q;
	stack<char> st;

	cin >> q;

	for (int i = 0; i < q.length(); i++) {
		if (q[i] >= 'A' && q[i] <= 'Z') {
			printf("%c", q[i]);
		}
		else if (q[i] == ')') { 
			while (st.top() != '(') {
				printf("%c", st.top());
				st.pop();
			}
			st.pop();
		}
		else if (isMulDiv(q[i])) { //'*', '/'
			while (!st.empty() && isMulDiv(st.top())) {
				printf("%c", st.top());
				st.pop();
			}
			st.push(q[i]);
		}
		else if (isPlMin(q[i])) { //'+', '-'
			while (!st.empty() && st.top() != '(') {
				printf("%c", st.top());
				st.pop();
			}
			st.push(q[i]);
		}
		else {
			st.push(q[i]);
		}
	}
	while (!st.empty()) {
		printf("%c", st.top());
		st.pop();
	}

	return 0;
}