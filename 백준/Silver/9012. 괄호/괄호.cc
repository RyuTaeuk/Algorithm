#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int t;
	stack<char> s;
	string tmp;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> tmp;
		for (int j = 0; j < tmp.length(); j++) {
			if (tmp[j] == '(') s.push('(');
			else if (tmp[j] == ')') {
				if (!s.empty()) {
					if (s.top() == '(') s.pop();
					else s.push(')');
				}
				else s.push(')');
			}
		}
		if (s.empty()) cout << "YES" << '\n';
		else cout << "NO" << '\n';
		while (!s.empty()) s.pop();
	}

	return 0;
}